#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library

#include "Button2.h"

#define BUTTON_1            35
#define BUTTON_2            0

// 점이 두께
#define THICKNESS           3

// TFT_eSPI 생성 
// LCD 사이즈를 지정해서 넣을 수도 있음.
// TFT_eSPI tft = TFT_eSPI(135, 240); 
TFT_eSPI tft = TFT_eSPI();
Button2 btn1(BUTTON_1);
Button2 btn2(BUTTON_2);

void setup() {
    
    uint16_t color_green    = TFT_GREEN;
    uint16_t color_red      = TFT_RED;
    uint16_t color_yellow   = TFT_YELLOW;
    uint16_t color_blue     = TFT_BLUE;
    
    // 시리얼 초기화 
    Serial.begin(115200);
    Serial.println("Start");

    // LCD 초기화 
    tft.init();
    // 스크린 회전 : 0~3, BMP drawing 에 대해서는 4~7
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
    tft.drawRect(0  ,   0, 2, 2, color_green);
    
    tft.drawRect(133, 238, 2, 2, color_red);
    
        

}

void loop() {
    // put your main code here, to run repeatedly:

}
