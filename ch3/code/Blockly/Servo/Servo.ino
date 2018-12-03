/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 15 Jan 2018 07:58:56 GMT
 */

#include <LBLE.h>
#include <LBLEPeriphral.h>
#include <Servo.h>

int data;

LBLEService __periphralService("951A6899-6F0F-456F-8AE0-5E0B4352D85B");
LBLECharacteristicInt __b77d53ac_d590_41e0_b75a_6da442f543f6("B77D53AC-D590-41E0-B75A-6DA442F543F6", LBLE_READ | LBLE_WRITE);
Servo __myservo2;

void setup()
{
  LBLE.begin();
  while (!LBLE.ready()) { delay(100); }

  __periphralService.addAttribute(__b77d53ac_d590_41e0_b75a_6da442f543f6);

  LBLEPeripheral.addService(__periphralService);
  LBLEPeripheral.setName("柵欄控制");
  LBLEPeripheral.begin();
  LBLEAdvertisementData __advertisement;
  __advertisement.configAsConnectableDevice("柵欄控制");
  LBLEPeripheral.advertise(__advertisement);
  Serial.begin(9600);

  __myservo2.attach(2);
  Serial.println("藍牙裝置建立成功");
  __myservo2.write(0);
  pinMode(7, OUTPUT);
}


void loop()
{
  if (__b77d53ac_d590_41e0_b75a_6da442f543f6.isWritten()) {
    data = __b77d53ac_d590_41e0_b75a_6da442f543f6.getValue();
    if (data == 0) {
      Serial.println("關閉");
      __myservo2.write(0);
      Serial.println(__myservo2.read());
      digitalWrite(7, LOW);

    } else if (data == 1) {
      Serial.println("開啟");
      __myservo2.write(90);
      Serial.println(__myservo2.read());
      digitalWrite(7, HIGH);
    }
    Serial.println(data);
    delay(1000);

  }
}