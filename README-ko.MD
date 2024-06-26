# TTGO T-Display

현재 이 라이브러리는 오래된 라이브러리다. **툴** --> **라이브러리 관리** 에서 **TFT_eSPI**를 찾아서 설치해도 동작에는 문제가 없다. 

현재 여기에는 에제코드가 일부 달라서 업데이트한 소스 코드를 머지 하지는 않았다.

## Quick start

1. **USB 드라이버를 설치한다.**, [CHxxx Series MAC driver](http://www.wch-ic.com/downloads/CH34XSER_MAC_ZIP.html) , [CHxxx Series Windows driver](http://www.wch-ic.com/downloads/CH343SER_ZIP.html),[CP21xx Series driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads)

2. 이 저장소에 있는 **TFT_eSPI** 폴더를  **<C:\Users\Your User Name\Documents\Arduino\libraries>**  폴더로 복사한다.

![](image/setup-window-01.png)

3. 복사한 후 **

3. **Arduino IDE**를 실행하고, **File** 메뉴 하위에 있는 **example** 의 서브 메뉴인   **TFT_eSPI**를 찾는다. **T-Display** 의 factory test program 은 **TFT_eSPI -> FactoryTest** 에 있다. 또한 TFT_eSPI 에서 제공하고 있는 다른 예제 프로그램도 사용할수 있다.

![](image/setup-window-02.png)

4. **Arduino IDE** tool 메뉴에서 **development board**를 선택한다. **ESP32 Dev Module**를 선택하고, **PSRAM 옵션은 Disable** 설정한다. 그리고 **Flash Size 옵션은 4MB 또는 16MB를 구매한 제품의 Flash 사이즈에 맞게 설정한다.**, 다른 옵션은 default를 유지한다.

![](image/setup-window-T-display-option-2.png)

5. 만약 ESP32 라이브러리를 최신 버전을 사용하고 있다는 **LilyGo T-Display** development board가 존재하므로 이 보드를 선택해도 된다. 아두이노 1.8 버전을 사용할 경우 간혹 발생하는 문제중 upload 명령에서 에러가 발생한다. 이럴 경우는 **ESP32 Dev module** 로 수정해서 진행하면 정상적으로 동작한다. 

![](image/setup-window-T-display-option.png)


6. 소스코드 중에  ESP32 보드 메니져 버전은 **3.0.x** 버전을 사용한다면 에러가 발생한다. 이럴 경우 **processors\TFT_eSPI_ESP32.h** 에 아래와 같이 내용을 추가하면 된다. 버전업 되면서 라이브러리가 변경된 것으로 보인다. 자세한 내용은 [관련 이슈 링크](https://github.com/Bodmer/TFT_eSPI/issues/3346)에서 확인하면 된다.

```c
// For core 3.0.0 and higher
#if ESP_ARDUINO_VERSION_MAJOR >= 3
	#include "driver/gpio.h"
	#include <rom/ets_sys.h>
#endif
```

1. 시리얼 포트(serial port)를 연결하고 대응되는 포트를 선택한다. 여러개의 포트가 동작하고 있어서 명확하지 않을 때는 모든 시리얼 포트를 제거하고 USB로 보드와 연결하여 해당포트를 확인하고 선택한다.

2. 마지막으로 체크 버튼 옆에 있는 화살표 버튼을 클릭하여 업로드를 수행한다.

![](image/setup-window-03.png)

-------------------------
## SD card 연결
- SD 카드를 데모 장치로 사용하여 두번째 SPI 장치를 이용하는 방법을 시연한 예입니다.

![](image/SD.jpg)

## Pinout
| Name       | V18    |
| ---------- | ------ |
| TFT Driver | ST7789 |
| TFT_MISO   | N/A    |
| TFT_MOSI   | 19     |
| TFT_SCLK   | 18     |
| TFT_CS     | 5      |
| TFT_DC     | 16     |
| TFT_RST    | 23     |
| TFT_BL     | 4      |
| I2C_SDA    | 21     |
| I2C_SCL    | 22     |
| ADC_IN     | 34     |
| BUTTON1    | 35     |
| BUTTON2    | 0      |
| ADC Power  | 14     |
