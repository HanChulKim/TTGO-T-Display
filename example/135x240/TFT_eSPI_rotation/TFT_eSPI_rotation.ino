#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library

#include "Button2.h"

#define BUTTON_1            35  // right button
#define BUTTON_2            0   // left button 
#define WIDTH               135
#define HEIGHT              240

// 점이 두께
#define THICKNESS           4

// 색상이 필요해서 
uint16_t color_green    = TFT_GREEN;
uint16_t color_red      = TFT_RED;
uint16_t color_yellow   = TFT_YELLOW;
uint16_t color_blue     = TFT_BLUE;

// TFT_eSPI 생성 
// LCD 사이즈를 지정해서 넣을 수도 있음.
// TFT_eSPI tft = TFT_eSPI(135, 240); 
TFT_eSPI tft = TFT_eSPI();

Button2 btn1(BUTTON_1);
Button2 btn2(BUTTON_2);

int display_width  = WIDTH;     // 초기 값 
int display_height = HEIGHT;

int cur_location = -1;          // 초기  방향
int new_location =  0;

void button_init()
{
    btn1.setPressedHandler([](Button2 & b) {
        // 아무것도 하지 않는다.
        // Serial.println("btn 1 click");
    });

    btn2.setPressedHandler([](Button2 & b) {
        
        // 왼쪽 버튼을 클릭하면 위치를 하나씩 이동시킨다.
        new_location ++ ;
        if( new_location % 4 == 0 ) new_location = 0;
        
        Serial.println("btn 2 click");
    });   
    
}

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

    // LCD 초기화 
    tft.init();
    
    update_display();

}

void update_display() 
{
    if( cur_location == new_location ) return ;

    cur_location = new_location ;
    
    if ( cur_location == 1 || cur_location == 3) {
        display_width   = HEIGHT;
        display_height  = WIDTH ;
        
    } else if(cur_location == 0 || cur_location == 2) {
        display_width   = WIDTH ;
        display_height  = HEIGHT; 
        
    } else {
        cur_location = 0 ; // 혹시 엉뚱한 값이 올지 몰라서 
        display_width   = WIDTH ;
        display_height  = HEIGHT; 
    }

    // 스크린 회전 : 0~3, BMP drawing 에 대해서는 4~7
    tft.setRotation(cur_location);
    tft.fillScreen(TFT_BLACK);
    
    tft.drawRect(0  ,   0, THICKNESS, THICKNESS, color_green);
    tft.drawRect(display_width - THICKNESS, display_height - THICKNESS, 
                    THICKNESS, THICKNESS, color_red);
    
    
}
void loop() {


    if( cur_location != new_location ) 
        update_display();
    
    
    // put your main code here, to run repeatedly:
    button_loop();
}
