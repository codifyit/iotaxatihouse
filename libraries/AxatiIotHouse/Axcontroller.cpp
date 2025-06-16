#include <Arduino.h>
#include <Axcontroller.h>
#include <Axconfig.h>

Axcontroller::Axcontroller(){
 
}
void Axcontroller::start(){
  this->gasAction();
  this->lightAction();
  this->soilAction();
  this->rainAction();
  //aXbutton1.resetPushCount(); // set btn1_num to 0
  //aXbutton2.resetPushCount(); // set btn2_num to 0
}
void Axcontroller::doorAction()
{ 
  String passwd;
  if(this->aXconfig.axButton1.digRead(0) == 0) // if variablebutton1 is 0
  {
    delay(10);           // delay in 10ms
    while (this->aXconfig.axButton1.digRead(0) == 0) // if variablebutton1 is 0，program will circulate
    {
      this->aXconfig.axButton1.incPushCount();
      delay(100);               // delay in 100ms
    }
  }
  if (this->aXconfig.axButton1.getPushCount()>= 1 && this->aXconfig.axButton1.getPushCount() < 5) // 1≤if variablebtn1_num<5
  {
    Serial.print(F("."));
    Serial.print(F(""));
    passwd = String(passwd) + String("."); // set passwd
    //pass = String(pass) + String(".");     // set pass
    // LCD shows pass at the first row and column
    this->aXconfig.axDisplay.setCursor(1 - 1, 2 - 1);
    this->aXconfig.axDisplay.print(String(passwd) + String(F(".")) + String(F(".")));
  }
  if (this->aXconfig.axButton1.getPushCount() >= 5)
  // if variablebtn1_num ≥5
  {
    Serial.print(F("-"));
    passwd = String(passwd) + String(F("-")); // Set passwd
    //pass = String(pass) + String("-");     // set pass
    // LCD shows pass at the first row and column
    this->aXconfig.axDisplay.setCursor(1 - 1, 2 - 1);
    this->aXconfig.axDisplay.print(String(passwd) + String(F("-")) + String(F("-")));
  }
  if (this->aXconfig.axButton2.getPushCount() == 0) // if variablebutton2 is 0
  {
    delay(10);
    if (this->aXconfig.axButton2.getPushCount() == 0) // if variablebutton2 is 0
    {
      if (passwd == ".--.-.") // if passwd is ".--.-."
      {
        this->aXconfig.axDisplay.clear(); // clear LCD screen
        // LCD shows "open!" at first character on second row
        this->aXconfig.axDisplay.setCursor(1 - 1, 2 - 1);
        this->aXconfig.axDisplay.print(F("open!"));
        this->aXconfig.axServo1.write(100);// set servo connected to digital 9 to 100°
        this->aXconfig.axServo2.write(100);// set servo connected to digital 9 to 100°
        delay(300);
        delay(5000);
        passwd = "";
        this->aXconfig.axDisplay.clear();// clear LCD screen
        // LCD shows "password:"at first character on first row
        this->aXconfig.axDisplay.setCursor(1 - 1, 1 - 1);
        this->aXconfig.axDisplay.print(F("password:"));
      }
      else // Otherwise
      {
        this->aXconfig.axDisplay.clear();// clear LCD screen
        // LCD shows "error!"at first character on first row
        this->aXconfig.axDisplay.setCursor(1 - 1, 1 - 1);
        this->aXconfig.axDisplay.print(F("error!"));
        passwd = "";
        delay(2000);
        // LCD shows "again" at first character on first row
        this->aXconfig.axDisplay.setCursor(1 - 1, 1 - 1);
        this->aXconfig.axDisplay.print(F("again"));
      }
    }
  }
}
void Axcontroller::infraredAction(){
  if (this->aXconfig.axInfrared.digRead(0) == 0 && (this->command != 'l' && this->command != 't'))
  // if variable infrar is 0 and val is not 'l' either 't'
  {
    // servo_9.write(0);  //set servo connected to digital 9 to 0°
    this->aXconfig.axServo2.write(0); // set servo connected to digital 9 to 0°
    delay(50);
  }
  if (this->aXconfig.axButton2.digRead(0) == 0) // if variablebutton2 is 0
  {
    delay(10);
    while (this->aXconfig.axButton2.getPushCount() == 0) // if variablebutton2 is 0，program will circulate
    {
      this->aXconfig.axButton2.digRead(0); // assign the value of digital 8 to button2
      this->aXconfig.axButton2.incPushCount();  // variable btn2_num plus 1
      delay(100);
      if (this->aXconfig.axButton2.getPushCount() >= 15) // if variablebtn2_num ≥15
      {
        tone(3, 532);
        delay(125);
        this->aXconfig.axDisplay.clear();// clear LCD screen
        
        // LCD shows "password:" at the first character on first row
        this->aXconfig.axDisplay.setCursor(1 - 1, 1 - 1);
        this->aXconfig.axDisplay.print(F("password:"));
        
        // LCD shows "wait" at the first character on first row
        this->aXconfig.axDisplay.setCursor(1 - 1, 1 - 1);
        this->aXconfig.axDisplay.print(F("wait:"));
      }
      else // Otherwise
      {
        noTone(3); // digital 3 stops playing music
      }
    }
  }
}
/**
 * Gas detection
 */
void Axcontroller::gasAction()
{
  if (this->aXconfig.axGas.anaRead(0) > 700)
  {
    do
    {
      Serial.println(F("danger")); // output "danger" in new lines
      tone(3, 440);
      delay(125);
      delay(100);
      noTone(3);
      delay(100);
      tone(3, 440);
      delay(125);
      delay(100);
      noTone(3);
      delay(300);
    }while(this->aXconfig.axGas.anaRead(0)>=100);
  }
  else
  {
    noTone(3); // digital 3 stops playing music
  }
  this->doorAction(); // run subroutine
}
void Axcontroller::rainAction(){
  if (this->aXconfig.axHygro1.anaRead(0) > 800)
  // if variable water is larger than 800
  {
    do
    // if flag2 is 1, program will circulate
    {
      Serial.println(F("rain")); // output "rain" in new lines
      this->aXconfig.axServo2.write(180); // set the servo connected to digital 10 to 180° 
      delay(300);             // delay in 300ms
      delay(100);
      this->aXconfig.axHygro1.anaRead(0);
      // if variable water is less than 30
    }while(this->aXconfig.axHygro1.anaRead(0)>=30);
  }
  else // Otherwise
  {
    if (this->command != 'u' && this->command != 'n')
    // if val is not equivalent 'u' either 'n'
    {
      this->aXconfig.axServo2.write(0); // set servo connected to digital 10 to 0°
      delay(10);
    }
  }
}
void Axcontroller::lightAction(){
  if (this->aXconfig.axLight.anaRead(0) < 300)        // if variable light is less than 300
  {
    Serial.println(this->aXconfig.axInfrared.digRead(0));  // output the value of variable infrar in new lines
    if (this->aXconfig.axInfrared.digRead(0) == 1)
    // if variable infra is 1
    {
      this->aXconfig.axLed1.digWrite(0,HIGH);// set digital 13 to high level, LED is on
    }
    else // Otherwise
    {
      this->aXconfig.axLed1.digWrite(0,LOW); // set digital 13 to low level, LED is off
    }
  }
}
void Axcontroller::soilAction(){
  if (this->aXconfig.axHygro2.anaRead(0) > 50)
  // if variable soil is greater than 50
  {
    do
    // If set flag3 to 1, program will circulate
    {
      Serial.println(F("hydropenia ")); // output "hydropenia " in new lines
      tone(3, 440);
      delay(125);
      delay(100);
      noTone(3);
      delay(100);
      tone(3, 440);
      delay(125);
      delay(100);
      noTone(3); // digital 3 stops playing sound
      delay(300);
    }while(this->aXconfig.axHygro2.anaRead(0)>=10);
  }
  else // Otherwise
  {
    noTone(3); // set digital 3 to stop playing music
  }
}
int Axcontroller::getCommand(){
  return this->command;
}
void Axcontroller::request(int command){
  this->command = command;
  switch (this->command) {
    case 'a':     
      //if val is character 'a'，program will circulate
      //set digital 13 to high level，LED 	lights up
      this->aXconfig.axLed1.digWrite(0,HIGH); 
      break;                   
    case 'b':                  
      //if val is character 'b'，program will circulate
      //Set digital 13 to low level, LED is off
      this->aXconfig.axLed1.digWrite(0,LOW); 
      break;                   
    case 'c':                  
      //if val is character 'c'，program will circulate
      //set digital 12 to high level，NO of relay is connected to COM
      this->aXconfig.axRelay.digWrite(0, HIGH);
      break;                   
    case 'd':                  
      //if val is character 'd'，program will circulate
      //set digital 12 to low level，NO of relay is disconnected to COM
      this->aXconfig.axRelay.digWrite(0, LOW);
      break;                  
    case 'e':                 //if val is character 'e'，program will circulate
      this->aXconfig.axBuzzer.music1();               //play birthday song
      break;                  
    case 'f':                 //if val is character 'f'，program will circulate
      this->aXconfig.axBuzzer.music2();               //play ode to joy song
      break;                  
    case 'g':                 //if val is character 'g'，program will circulate
      noTone(3);              //set digital 3 to stop playing music
      break;                  
    case 'h':                 //if val is character 'h'，program will circulate
      Serial.println(this->aXconfig.axLight.anaRead(0));  //output the value of variable light in new lines
      delay(100);
      break;                
    case 'i':               //if val is character 'i'，program will circulate
      Serial.println(this->aXconfig.axGas.anaRead(0));  //output the value of variable gas in new lines
      delay(100);
      break;                 
    case 'j':                //if val is character 'j'，program will circulate
      Serial.println(this->aXconfig.axGas.anaRead(0));  //output the value of variable soil in new lines
      delay(100);
      break;                 
    case 'k':                 //if val is character 'k'，program will circulate
      Serial.println(this->aXconfig.axHygro1.anaRead(0));  //output the value of variable water in new lines
      delay(100);
      break;               
    case 'l':              //if val is character 'l'，program will circulate
      this->aXconfig.axServo1.write(180);  //set servo connected to digital 9 to 180°
      delay(500);
      break;   
    case 'm':  //if val is character 'm'，program will circulate
      this->aXconfig.axServo1.write(0);
      ;  //set servo connected to digital 9 to 0°
      delay(500);
      break;                 
    case 'n':               //if val is character 'n'，program will circulate
      this->aXconfig.axServo2.write(180);  //set servo connected to digital 10 to 180°
      delay(500);
      break;               
    case 'o':             //if val is character 'o'，program will circulate
      this->aXconfig.axServo2.write(0);  //set servo connected to digital 10 to 0°
      delay(500);
      break;                   
    case 'p':                 
      //if val is character 'p'，program will circulate
      //set digital 5 to high level, LED is on
      this->aXconfig.axLed2.digWrite(0,HIGH);
      break;                  
    case 'q':                 
      //if val is character 'q'，program will circulate
      // set digital 5 to low level, LED is off
      this->aXconfig.axLed2.digWrite(0,LOW);
      break;                  
    case 'r':                 
      //if val is character 'r'，program will circulate
      this->aXconfig.axFan.digWrite(1,LOW);
      this->aXconfig.axFan.digWrite(0,HIGH); //fan rotates anticlockwise at the fastest speed
      digitalWrite(6, HIGH);  
      break;                  
    case 's':                 
      //if val is character 's'，program will circulate
      this->aXconfig.axFan.digWrite(0,LOW); //fan stops rotating
      this->aXconfig.axFan.digWrite(1,LOW);
      break;                 
    case 't':  
      //if val is 't'，program will circulate
      this->aXconfig.axServo1.write(String(Serial.readStringUntil('#')).toInt()); //set the angle of servo connected to digital 9 to servo1_angle
      delay(300);
      break;   
    case 'u':  
      //if val is 'u'，program will circulate
      this->aXconfig.axServo2.write(String(Serial.readStringUntil('#')).toInt()); //set the angle of servo connected to digital 9 to servo1_angle
      delay(300);
      break;   
    case 'v':  
      //if val is 'v'，program will circulate
      delay(300);
      this->aXconfig.axLight.anaWrite(0, String(Serial.readStringUntil('#')).toInt());  //PWM value of digital 5 is value_led2
      break;                       
    case 'w':                      
      //if val is 'w'，program will circulate
      this->aXconfig.axFan.digWrite(0, LOW);
      this->aXconfig.axFan.anaWrite(0, String(Serial.readStringUntil('#')).toInt());  //set PWM value of digital 6 to fans_val，the larger the value, the faster the fan
      break;  
  }
}