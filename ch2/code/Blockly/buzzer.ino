/*
 * Generated using BlocklyDuino:
 *
 * https://github.com/MediaTek-Labs/BlocklyDuino-for-LinkIt
 *
 * Date: Mon, 12 Nov 2018 03:15:32 GMT
 */



void setup()
{
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(3, INPUT);
}


void loop()
{
  if (digitalRead(3) == false) {
    for (int count = 0; count < 1; count++) {
      tone(2, 253, 300);
      delay(300);
      tone(2, 588, 300);
      delay(300);
      tone(2, 660, 300);
      delay(300);
      tone(2, 698, 300);
      delay(300);
      tone(2, 784, 300);
      delay(300);
      tone(2, 660, 300);
      delay(300);
      tone(2, 523, 300);
      delay(300);
      tone(2, 784, 300);
      delay(300);
      tone(2, 698, 300);
      delay(300);
      tone(2, 588, 300);
      delay(300);
    }

  } else {
    digitalWrite(2, LOW);

  }
}