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
  this->tonepin = 3; // set the signal end of passive buzzer to digital 3
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
  tone(3, 294); // digital 3 outputs 294HZ sound
  delay(250);   // delay in 250ms
  tone(3, 440);
  delay(250);
  tone(3, 392);
  delay(250);
  tone(3, 532);
  delay(250);
  tone(3, 494);
  delay(500);
  tone(3, 392);
  delay(250);
  tone(3, 440);
  delay(250);
  tone(3, 392);
  delay(250);
  tone(3, 587);
  delay(250);
  tone(3, 532);
  delay(500);
  tone(3, 392);
  delay(250);
  tone(3, 784);
  delay(250);
  tone(3, 659);
  delay(250);
  tone(3, 532);
  delay(250);
  tone(3, 494);
  delay(250);
  tone(3, 440);
  delay(250);
  tone(3, 698);
  delay(375);
  tone(3, 659);
  delay(250);
  tone(3, 532);
  delay(250);
  tone(3, 587);
  delay(250);
  tone(3, 532);
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
  for (int x = 0; x < this->length; x++)
  {
    tone(this->tonepin, this->tune[x]);
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