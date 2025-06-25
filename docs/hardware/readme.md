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

<table><tr><th>Thing</th><th>Description</th><th>Code abstraction</th></tr>
<tr><td>Arduino Uno R3</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/arduino-uno.png" align="center" width="25%"></td></tr>
<tr><td>Sensor Shield V5.0</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/sensor-shield.png" align="center" width="25%"></td></tr>
<tr><td>Yellow led</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/yellow-led.png" align="center" width="25%"></td>
<td><pre>
<code>using namespace std;
#include <Arduino.h>
#include <Axactuator.h>
#ifndef Axled_h
#define Axled_h

class Axled:public Axactuator{

};
#endif</code>
</pre></td>
</tr>
<tr><td>White led</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/white-led.png" align="center" width="25%"></td><td>
<code>using namespace std;
#include <Arduino.h>
#include <Axactuator.h>
#ifndef Axled_h
#define Axled_h

class Axled:public Axactuator{

};
#endif</code></td>
</tr>
<tr><td>Passive buzzer</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/passive-buzzer.png" align="center" width="25%"></td>
<td>
  <code>#include &lt;Axactuator.h&gt;
#ifndef Axbuzzer_h
#define Axbuzzer_h
class Axbuzzer:public Axactuator{
    private:
        int length;
        int tonepin;
        int tune[64];
        float durt[64];
    public:
        Axbuzzer();
        void birthday(); //set birthday song
        void music1();
        void music2();
        void odeToJoy(); //Ode to joy
        void setDurt(float []);
        void setTune(int []);
};
#endif</code>
</td></tr>
<tr><td>Button (2)</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/button.png" align="center" width="25%"></td><td><code>using namespace std;
#include <Axactuator.h>
#include <Arduino.h>
#ifndef Axbutton_h
#define Axbutton_h
class Axbutton:public Axactuator{
    private:
        int pushCount;
    public:
        int getPushCount();
        void incPushCount();
        void resetPushCount();
};
#endif</code></td></tr>
<tr><td>Relay (2)</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/relay.png" align="center" width="25%"></td>
<td>
<code>using namespace std;
#ifndef Axrelay_h
#define Axrelay_h

class Axrelay:public Axactuator{

};
#endif</code>
</td></tr>
<tr><td>Photocell</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/photocell.png" align="center" width="25%"></td>
<td>
<code>using namespace std;
#include <Axactuator.h>
#ifndef Axlight_h
#define Axlight_h

class Axlight:public Axactuator{

};
#endif</code>
</td></tr>
<tr><td>Servo (2)</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/servo.png" align="center" width="25%"></td>
<td>
<code>using namespace std;
#include <Servo.h>
#include <Axactuator.h>
#ifndef Axservo_h
#define Axservo_h         

class Axservo:public Axactuator{
    private: 
        Servo servo;
    public:
        void attach(int pin);
        void write(int what);
};
#endif</code>
</td>
</tr>
<tr><td>Fan</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/fan.png" align="center" width="25%"></td><td>
<code>using namespace std;
#include &lt;Axactuator.h&gt;
#ifndef Axfan_h
#define Axfan_h
class Axfan:public Axactuator{

};
#endif</code>
</td></tr>
<tr><td>Water sensor</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/water.png" align="center" width="25%"></td>
<td>
<code>#include &lt;Axsensor.h&gt;
#ifndef Axrain_h
#define Axrain_h
class Axrain:public Axsensor{

};
#endif
</code>
</td></tr>
<tr><td>PIR sensor</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/pir.png" align="center" width="25%"></td>
<td><code>#include &lt;Axsensor.h&gt;
#ifndef Axinfrared_h
#define Axinfrared_h

class Axinfrared: public Axsensor{

};
#endif</code>
</td></tr>
<tr><td>MQ2 gas sensor</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/gas.png" align="center" width="25%"></td><td><code>#include &lt;Axsensor.h&gt;
#ifndef Axgas_h
#define Axgas_h

class Axgas:public Axsensor{

};  
#endif</code></td></tr>
<tr><td>LCD1602 display</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/display.png" align="center" width="25%"></td></tr>
<tr><td>Humedity sensor</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/humedity.png" align="center" width="25%"></td>
<td><code>#include &lt;Axsensor.h&gt;
#ifndef Axhygro_h
#define Axhygro_h

class Axhygro:public Axsensor{

};
#endif</code></td></tr>
  <tr><td>Bluetooth</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/bluetooth.png" align="center" width="25%"></td><td><code>#include &lt;Axthing.h&gt;
#ifndef Axbluetooth_h
#define Axbluetooth_h
class Axbluetooth:public Axthing{
    
};
#endif</code></td></tr>
</table>

## Connections diagrams

<table><tr><td>Realy and white led<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/relay-white-led.png" align="center" width="50%"></td>
</tr>
<tr><td>Fan connection<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/fan-connection.png" align="center" width="50%"></td></tr>
<tr><td>Button and yellow led<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/button-yellow-led.png" align="center" width="50%"></td></tr>
<tr><td>Button and gas sensor<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/button-gas.png" align="center" width="50%"></td></tr>
<tr><td>Buzzer and infrared sensor<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/buzzer-infrared.png" align="center" width="50%"></td></tr>
<tr><td>Bluetooth connection<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/bluetooth-connection.png" align="center" width="50%"></td></tr>
<tr><td>Display connection<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/display-connection.png" align="center" width="50%"></td></tr>
<tr><td>Servos connection<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/servos-connection.png" align="center" width="50%"></td></tr>
<tr><td>Light, humedity and water sensors connection<br><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/light-humedity-water.png" align="center" width="50%"></td></tr>
</table>



