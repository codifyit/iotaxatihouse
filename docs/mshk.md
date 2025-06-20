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

## Things in the project

<table><tr><th>Thing</th><th>Description</th></tr>
<tr><td>Arduino Uno R3</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/arduino-uno.png" align="center" width="25%"></td></tr>
<tr><td>Sensor Shield V5.0</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/sensor-shield.png" align="center" width="25%"></td></tr>
<tr><td>Yellow led</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/yellow-led.png" align="center" width="25%"></td></tr>
<tr><td>White led</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/white-led.png" align="center" width="25%"></td></tr>
<tr><td>Passive buzzer</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/passive-buzzer.png" align="center" width="25%"></td></tr>
<tr><td>Button (2)</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/button.png" align="center" width="25%"></td></tr>
<tr><td>Relay (2)</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/relay.png" align="center" width="25%"></td></tr>
<tr><td>Photocell</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/photocell.png" align="center" width="25%"></td></tr>
<tr><td>Servo (2)</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/servo.png" align="center" width="25%"></td></tr>
<tr><td>Fan</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/fan.png" align="center" width="25%"></td></tr>
<tr><td>Water sensor</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/water.png" align="center" width="25%"></td></tr>
<tr><td>PIR sensor</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/pir.png" align="center" width="25%"></td></tr>
<tr><td>MQ2 gas sensor</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/gas.png" align="center" width="25%"></td></tr>
<tr><td>LCD1602 display</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/display.png" align="center" width="25%"></td></tr>
<tr><td>Humedity sensor</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/humedity.png" align="center" width="25%"></td></tr>
  <tr><td>Bluetooth</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/bluetooth.png" align="center" width="25%"></td></tr>
</table>

## Connections diagrams

<table><tr><td>Realy and white led<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/relay-white-led.png" align="center" width="50%"></td></tr>
<tr><td>Fan connection<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/fan-connection.png" align="center" width="50%"></td></tr>
<tr><td>Button and yellow led<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/button-yellow-led.png" align="center" width="50%"></td></tr>
<tr><td>Button and gas sensor<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/button-gas.png" align="center" width="50%"></td></tr>
<tr><td>Buzzer and infrared sensor<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/buzzer-infrared.png" align="center" width="50%"></td></tr>
</table>



