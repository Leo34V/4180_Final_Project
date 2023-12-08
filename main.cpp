#include <mbed.h>
#include <string>
#include <list>
#include "uLCD_4DGL.h"
#include <mpr121.h>
#include "rtos.h"

Mutex LCD;
InterruptIn interrupt(p21);
uLCD_4DGL uLCD(p13,p14,p11); 
I2C i2c(p9, p10);
Serial blue(p28,p27);
Mpr121 mpr121(&i2c, Mpr121::ADD_VSS);
PwmOut speaker(p22);

volatile int key_code=0;
volatile float volume = 0;

void touchInterrupt(){
    int i=0;
    int value=mpr121.read(0x00);
    value +=mpr121.read(0x01)<<8;
    i=0;
    for (i=0; i<12; i++) {
        if (((value>>i)&0x01)==1) key_code=i+1;
    }
    speaker.period(1.0/ (float (key_code*75.1) ) );
}

void LCDThread(void const *args) {
    while(1){
        LCD.lock();
        uLCD.cls();
        uLCD.locate(0,0);
        uLCD.color(GREEN);
        uLCD.text_bold(ON);
        uLCD.printf("MUSIC PLAYER\n");
        uLCD.color(WHITE);
        uLCD.textbackground_color(BLUE);
        uLCD.printf("\nTouchpad Key Pressed: %d\n", key_code-1);
        uLCD.color(GREEN);
        uLCD.textbackground_color(BLACK);
        uLCD.printf("\n\n");
        uLCD.printf("Volume: %0.2f", (float) speaker);
        uLCD.printf("\nPitch: %.2f", (float (key_code*75.1)));
        uLCD.printf("\n" );
        LCD.unlock();
        Thread::wait(500);
    }
}

void bluetoothThread(void const *args){
    char bnum;
    char bhit;
    while(1) {
        while(!blue.readable()) Thread::yield();
        LCD.lock();
        if (blue.getc()=='!') {
            if (blue.getc()=='B') { //button data packet
                bnum = blue.getc(); //button number
                bhit = blue.getc(); //1=hit, 0=release
                switch (bnum) {
                    case '5': //button 5 up arrow
                    if ((bhit=='1')&&(volume<=0.5)) volume+=0.05;
                    break;
                    case '6': //button 6 down arrow
                    if ((bhit=='1')&&(volume>=0)) volume-=0.05;
                    break;
                    case '8': //button 8 right arrow
                    if ((bhit=='1')&&(key_code<=12)) key_code++;
                    speaker.period(1.0/ (float (key_code*75.1) ) );
                    break;
                    case '7': //button 7 left arrow
                    if ((bhit=='1')&&(key_code>=1)) key_code--;
                    speaker.period(1.0/ (float (key_code*75.1) ) );
                    break;
                    case '1':
                        if (bhit=='1') {
                            key_code = 0;
                            volume = 0;
                        }
                    break;
                    case '2':
                        if (bhit=='1') {
                            key_code = 4;
                            volume = 0.15;
                        }
                    break;
                    case '3':
                        if (bhit=='1') {
                            key_code = 8;
                            volume = 0.3;
                        }
                    break;
                    case '4':
                        if (bhit=='1') {
                            key_code = 12;
                            volume = 0.5;
                        }
                    break;
                    default:
                    break;
                }
            }
        }
        LCD.unlock();
    }
}

int main() {
    interrupt.fall(&touchInterrupt);
    interrupt.mode(PullUp);
    uLCD.background_color(BLACK);
    uLCD.cls();
    uLCD.color(WHITE);
    uLCD.textbackground_color(BLUE);
    uLCD.set_font(FONT_7X8);
    uLCD.text_mode(TRANSPARENT);
    Thread t2(LCDThread);
    Thread t3(bluetoothThread);
    while (1) {
        //speaker.period(1.0/ (float (key_code*75.1) ) ); Note: this causes noise
        speaker = volume;
    }
}
