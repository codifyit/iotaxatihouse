//call the relevant library file
#include <Axcontroller.h>

//set the controller
Axcontroller axController;

void setup() {
  Serial.begin(9600);  //set baud rate to 

  delay(300);

  axController.start();
}
void loop() {
  if (Serial.available() > 0)  //serial reads the characters
  {
    axController.request(Serial.read()); //set val to character read by serial
  }
}