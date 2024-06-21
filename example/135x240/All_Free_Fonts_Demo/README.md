# 설명

전체 표현가능한 폰트를 출력함. 

```c
  tft.fillScreen(TFT_BLACK);             // 화면을 검은색으로 전부 칠함
  // #define FF18 &FreeSans12pt7b
  tft.setFreeFont(FF18);                 // 폰트 설정
  // #define sFF1 "Mono 9"
  tft.drawString(sFF1, 160, 60, GFXFF);  // 정해진 좌표에 글자 출력
  tft.setFreeFont(FF1);                  // 폰트 선택
  // #define TEXT "aA MWyz~12"
  tft.drawString(TEXT, 160, 120, GFXFF); // 정해진 좌표에 글자 출력
```
