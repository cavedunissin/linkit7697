/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sun, 14 Jan 2018 15:52:59 GMT
 */

#include <LBLE.h>
#include <LBLEPeriphral.h>

int data;

LBLEService __periphralService("951A6899-6F0F-456F-8AE0-5E0B4352D85B");
LBLECharacteristicInt __b77d53ac_d590_41e0_b75a_6da442f543f6("B77D53AC-D590-41E0-B75A-6DA442F543F6", LBLE_READ | LBLE_WRITE);

void setup()
{
  LBLE.begin();
  while (!LBLE.ready()) { delay(100); }

  __periphralService.addAttribute(__b77d53ac_d590_41e0_b75a_6da442f543f6);

  LBLEPeripheral.addService(__periphralService);
  LBLEPeripheral.setName("LED控制");
  LBLEPeripheral.begin();
  LBLEAdvertisementData __advertisement;
  __advertisement.configAsConnectableDevice("LED控制");
  LBLEPeripheral.advertise(__advertisement);
  Serial.begin(9600);

  Serial.println("藍牙裝置建立成功");
  pinMode(7, OUTPUT);
}


void loop()
{
  if (__b77d53ac_d590_41e0_b75a_6da442f543f6.isWritten()) {
    data = __b77d53ac_d590_41e0_b75a_6da442f543f6.getValue();
    if (data == 0) {
      Serial.println("關燈");
      digitalWrite(7, LOW);

    } else if (data == 1) {
      Serial.println("開燈");
      digitalWrite(7, HIGH);
    }
    Serial.println(data);
    delay(1000);

  }
}
