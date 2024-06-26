#include <SPI.h>

#include "Button2.h"

#define BUTTON_1            0    // left button
#define BUTTON_2            35   // right button 

Button2 btn1(BUTTON_1);
Button2 btn2(BUTTON_2);

/**
 * callback 함수로 버튼 처리했다. 
 */
void button_init()
{
    
    btn1.setPressedHandler([](Button2 & b) {       
        Serial.println("btn 1 click");
    });
    
    btn1.setLongClickHandler([](Button2 & b) {
        Serial.println("btn 1 long press");    
    });

    btn2.setPressedHandler([](Button2 & b) {     
        Serial.println("btn 2 click");
    });

    btn2.setLongClickHandler([](Button2 & b) {
        Serial.println("btn 2 long press");    
    });
    
}

/**
 * 두개의 버튼에 대해서 loop 처리하기 위해서 함수를 만듬.
 */
void button_loop()
{
    btn1.loop();
    btn2.loop();
}

void setup() {
    
    
    // 시리얼 초기화 
    Serial.begin(115200);
    Serial.println("Start");
    
    button_init();

}


void loop() {
    
    // loop 내에 넣어 놓아서 btn1,
    // btn2가 loop처리되도록 함.
    button_loop();
}
