#include <Arduino.h>
#include <Axbuzzer.h>
/*
-----------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------
Functions and variables to play sounds
-----------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------
*/

/*
-----------------------------------------------------------------------------------------------------------------------------
INITIALIZE VARS
-----------------------------------------------------------------------------------------------------------------------------
*/

//-----------------------------------------------------------------------------------------------------------------------------

/*
-----------------------------------------------------------------------------------------------------------------------------
FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------------------------------------------------------------
*/
Axbuzzer::Axbuzzer()
{
  // set sound play frequency
  int tune[64] =
      {
          M3, M3, M4, M5,
          M5, M4, M3, M2,
          M1, M1, M2, M3,
          M3, M2, M2,
          M3, M3, M4, M5,
          M5, M4, M3, M2,
          M1, M1, M2, M3,
          M2, M1, M1,
          M2, M2, M3, M1,
          M2, M3, M4, M3, M1,
          M2, M3, M4, M3, M2,
          M1, M2, D5, D0,
          M3, M3, M4, M5,
          M5, M4, M3, M4, M2,
          M1, M1, M2, M3,
          M2, M1, M1};
  // set music beat
  float durt[] = {
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1 + 0.5,
      0.5,
      1 + 1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1 + 0.5,
      0.5,
      1 + 1,
      1,
      1,
      1,
      1,
      1,
      0.5,
      0.5,
      1,
      1,
      1,
      0.5,
      0.5,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      1,
      0.5,
      0.5,
      1,
      1,
      1,
      1,
      1 + 0.5,
      0.5,
      1 + 1};
     this->setDurt(durt);
     this->setTune(tune);
     this->length = sizeof(this->tune) / sizeof(this->tune[0]);  //set the value of length
}
////////////////////////set birthday song//////////////////////////////////
void Axbuzzer::birthday()
{
  const int PIN = this->getDigPinNum();
  tone(PIN, 294); // digital 3 outputs 294HZ sound
  delay(250);   // delay in 250ms
  tone(PIN, 440);
  delay(250);
  tone(PIN, 392);
  delay(250);
  tone(PIN, 532);
  delay(250);
  tone(PIN, 494);
  delay(500);
  tone(PIN, 392);
  delay(250);
  tone(PIN, 440);
  delay(250);
  tone(PIN, 392);
  delay(250);
  tone(PIN, 587);
  delay(250);
  tone(PIN, 532);
  delay(500);
  tone(PIN, 392);
  delay(250);
  tone(PIN, 784);
  delay(250);
  tone(PIN, 659);
  delay(250);
  tone(PIN, 532);
  delay(250);
  tone(PIN, 494);
  delay(250);
  tone(PIN, 440);
  delay(250);
  tone(PIN, 698);
  delay(375);
  tone(PIN, 659);
  delay(250);
  tone(PIN, 532);
  delay(250);
  tone(PIN, 587);
  delay(250);
  tone(PIN, 532);
  delay(500);
}
// Birthday song
void Axbuzzer::music1(void)
{
  this->birthday();
}
// Ode to joy
void Axbuzzer::music2(void)
{
  this->odeToJoy();
}
void Axbuzzer::odeToJoy(void) // play Ode to joy song
{
  const int PIN = this->getDigPinNum();
  for (int x = 0; x < this->length; x++)
  {
    tone(PIN, this->tune[x]);
    delay(300 * this->durt[x]);
  }
}
//-----------------------------------------------------------------------------------------------------------------------------
void Axbuzzer::setDurt(float durt[]){
  memcpy(this->durt, durt, sizeof(durt));
}
void Axbuzzer::setTune(int tune[]){
  memcpy(this->tune, tune, sizeof(tune));
}