/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Sat, 24 Nov 2018 09:24:06 GMT
 */



void setup()
{

  pinMode(3, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, INPUT);
}


void loop()
{
  if (digitalRead(3) == true) {
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
    delay(3000);

  } else if (digitalRead(4) == true) {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    delay(3000);
  } else {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);

  }
}