/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Fri, 01 Dec 2017 05:42:26 GMT
 */

#include <LWiFi.h>
#include "MCS.h"

#include "DHT.h"

char _lwifi_ssid[] = "CAVEDU_02";
char _lwifi_pass[] = "12345678";
MCSDevice mcs("D1eRZbQc", "N0D62n4W3zHe0q2y");

MCSControllerInteger turn("turn");
MCSControllerInteger pwm("pwm");
MCSDisplayFloat temp("temp");
DHT __dht2(2, DHT22);

void setup()
{
  Serial.begin(9600);

  mcs.addChannel(turn);
  mcs.addChannel(pwm);
  mcs.addChannel(temp);
  Serial.println("開始連線");
  while (WiFi.begin(_lwifi_ssid, _lwifi_pass) != WL_CONNECTED) { delay(1000); }
  while(!mcs.connected()) { mcs.connect(); }
  Serial.println("連線成功");
  Serial.begin(9600);
  __dht2.begin();

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}


void loop()
{
  while (!mcs.connected()) {
    mcs.connect();
    if (mcs.connected()) { Serial.println("MCS Reconnected."); }
  }
  mcs.process(100);
  temp.set(__dht2.readTemperature());
  if (turn.value()) {
    Serial.println(turn.value());
    if (turn.value() == 1) {
      Serial.println("自動模式");
      Serial.print("目前溫度:");
      Serial.println(__dht2.readTemperature());
      if (__dht2.readTemperature() >= 25 && __dht2.readTemperature() < 28) {
        analogWrite(4, 150);
        analogWrite(5, 0);

      } else if (__dht2.readTemperature() >= 28 && __dht2.readTemperature() < 30) {
        analogWrite(4, 200);
        analogWrite(5, 0);
      } else if (__dht2.readTemperature() >= 30) {
        analogWrite(4, 255);
        analogWrite(5, 0);
      }

    } else if (turn.value() == 2) {
      Serial.println("手動模式");
      if (pwm.value()) {
        Serial.print("目前通道數值:");
        Serial.println(pwm.value());
        analogWrite(4, pwm.value());
        analogWrite(5, 0);

      }
    }

  }
}