/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sat, 24 Nov 2018 08:35:46 GMT
 */



boolean fan;

void setup()
{

  pinMode(6, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);

}


void loop()
{
  if (digitalRead(6)) {
    if (fan) {
      fan = false;

    } else {
      fan = true;

    }
    delay(100);

  }
  if (fan) {
    analogWrite(4, 255);
    analogWrite(5, 0);
    Serial.println("開啟風扇");

  } else {
    analogWrite(4, 0);
    analogWrite(5, 0);
    Serial.println("關閉風扇");

  }
  delay(100);
}