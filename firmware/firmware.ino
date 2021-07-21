#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <PubSubClient.h>


/*const char* topic = "server";
#define mqtt_server "driver.cloudmqtt.com"
#define mqtt_port 18763
#define mqtt_user "ktzuvtgv"
#define mqtt_password  "nRcALzAXMNjj"*/

const char* topic = "project";
#define mqtt_server "broker.hivemq.com"
#define mqtt_port 1883
#define mqtt_user ""
#define mqtt_password  ""

WiFiClient espClient;
PubSubClient client(espClient);


int analogPin = A0;
int val = 0; 
int Relay1 = 3;       //led
char *led_status = "off";
char *water_status = "stop";
int pumpPin2 = 2;    //ปั้ม


//Wi-Fi settings
const char* ssid = "cutesuaywifi28";
const char* password = "suaymak28";
void setup() {
          /*------------NETWORK-------------*/

Serial.begin(9600);
pinMode(pumpPin2, OUTPUT); // sets the pin as output
Serial.begin(4800);
pinMode(Relay1, OUTPUT); 
Serial.begin(115200);

Serial.println();
Serial.print("Connecting to");
Serial.println(ssid);
WiFi.begin(ssid,password);
while (WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
    Serial.println("");
    Serial.println("Wifi connected ");
    Serial.println("IP Address:");
    Serial.println(WiFi.localIP());

    /*------------MQTT-------------*/
client.setServer(mqtt_server,mqtt_port);
client.setCallback(callback);

}

void loop() {
if(!client.connected())
{
  Serial.print("MQTT Connecting...");
  if(client.connect("ESP32Client",mqtt_user,mqtt_password))
  {
    client.subscribe(topic);
    Serial.println("Connected");
  }
  else
  {
    Serial.print("failed,rc =");
    Serial.print(client.state());
    Serial.println("Try agian in 5 seconds");
    delay(5000);
    return;
  }
}
          /*---------------------------------*/
val = analogRead(analogPin); //อ่านค่าสัญญาณ analog 
Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
Serial.println(val); // พิมพ์ค่าของตัวแปร val
if (val > 500) {
digitalWrite(pumpPin2, HIGH); // สั่งให้ ปั้มน้ำเปิด
}
else {
digitalWrite(pumpPin2, LOW); // สั่งให้ ปั้มน้ำเปิด

 
}
delay(100);
client.loop();
}

void callback(char* topic,byte* payload,unsigned int length)
{
  Serial.print("Message from");
  Serial.println(topic);
  
  String msg = "";
  int i = 0;
  while(1 < length)
  {
    msg += (char)payload[i++];
  }
  Serial.print("receive");
  Serial.println(msg);

  if (msg == "on")
  {
    digitalWrite(Relay1,1);
  }else if (msg == "off")
    {
      digitalWrite(Relay1,0);
    }

    if (msg == "run")
    {
      digitalWrite(Relay1,1);
    }else if (msg == "stop")
    {
      digitalWrite(Relay1,0);
    }

    
}
