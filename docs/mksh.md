# Multi-purpose Smart Home Kit

The sketch includes code for default behavior.

- Photocell sensor, PIR motion sensor and LED. When at night, someone passes by, LED is on; nobody is around, the LED is off.
- There are 1602LCD display, 2 buttons, 1 servo on the board. Press button1 to enter the password(you can set password in the test code),
  the 1602LCD will show “*”, then press button2 to “ensure”. If the password is correct, the 1602LCD will show “open”, the door will be open.
  However, if the password is wrong, the “error” pops up , after 2s, “error” will turn into “again” , you can enter password again.

