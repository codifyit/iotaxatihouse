# Multi-purpose Smart Home Kit

The sketch includes code for default behavior.

- Photocell sensor, PIR motion sensor and LED. When at night, someone passes by, LED is on; nobody is around, the LED is off.
- There are 1602LCD display, 2 buttons, 1 servo on the board. Press button1 to enter the password(you can set password in the test code),
  the 1602LCD will show “*”, then press button2 to “ensure”. If the password is correct, the 1602LCD will show “open”, the door will be open.
  However, if the password is wrong, the “error” pops up , after 2s, “error” will turn into “again” , you can enter password again. The correct
  password is ”. - - . - .” which means that short press button1, long press button1, long press button1, short press button1, long press button1,
  short press button1 (”- ”means long press button1, ”.”means short press button1).
- The door will be closed when PIR motion sensor doesn’t detect people around.
- Pressing and holding button2, buzzer will sound, LCD displays “wait”.（If the password is right, the servo will rotate to 180°, otherwise，the servo don’t rotate)
- Insert soil humidity into plant pot, when the soil is too dry, buzzer will alarm and you will get the notification on app.
- When the gas sensor detects the gas with high concentration, the buzzer emits a "tick,tick" alarm sound.
- When steam sensor detects rains, the servo 2 will be activated, the window will be closed automatically, otherwise, the window will be open. 



<img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/arduino-uno.png" align="center" width="40%">

