<table><tr><th>Thing</th><th>Description</th><th>Code abstraction</th></tr>
<tr><td>Arduino Uno R3</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/arduino-uno.png" align="center" width="25%"></td></tr>
<tr><td>Sensor Shield V5.0</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/sensor-shield.png" align="center" width="25%"></td></tr>
<tr><td>Yellow led</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/yellow-led.png" align="center" width="25%"></td>
<td><pre>
<code>using namespace std;
#include &lt;Arduino.h&gt;
#include &lt;Axactuator.h&gt;
#ifndef Axled_h
#define Axled_h

class Axled:public Axactuator{

};
#endif</code>
</pre></td>
</tr>
<tr><td>White led</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/white-led.png" align="center" width="25%"></td><td>
<code>using namespace std;
#include &lt;Arduino.h&gt;
#include &lt;Axactuator.h&gt;
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
#include &lt;Axactuator.h&gt;
#include &lt;Arduino.h&gt;
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
#include &lt;Axactuator.h&gt;
#ifndef Axlight_h
#define Axlight_h

class Axlight:public Axactuator{

};
#endif</code>
</td></tr>
<tr><td>Servo (2)</td><td><img src="https://github.com/codifyit/iotaxatihouse/blob/main/docs/images/servo.png" align="center" width="25%"></td>
<td>
<code>using namespace std;
#include &lt;Servo.h&gt;
#include &lt;Axactuator.h&gt;
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
