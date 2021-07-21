1. Dowload Software 
	- Arduino

2. prepare Hardwares
	- esp32
	- Soil Moisture Sensor
	- Relay Module 5V 
	- water pump

3.When you get firmware.ino file ,Open it in Arduino ISE

4.In firmware.ino file,You have to change some of them to your data.

	//Wi-Fi settings
	const char* ssid = " YOUR WIFI NAME";
	const char* password = " WIFI PASSWORD ";

	// MQTT INFORMATION ,You can get this information by creating an instant from the mqtt broker.
	const char* topic = " <<YOUR MQTT TOPIC NAME>> ";
	#define mqtt_server " <<YOUR MQTT SERVER>>"
	#define mqtt_port <<YOUR MQTT port>>
	#define mqtt_user " <<YOUR MQTT user>> "
	#define mqtt_password  " <<YOUR MQTT PASSWORD>> "

5.Connect the hardware as declared in the code.

	int Relay1 = 1;       //led at pin 1
	int pumpPin2 = 2;     //Water pump at pin 2
	int analogPin = A0;   //Soil Moisture Sensor at pin A0

6.Check your connection (Wifi/MQTT) that you have connected.

7.Upload the firmware to esp32

8.You can send a message from MQTT to Hardware >> go to Websocket and send a message.if you send "on" LED will turn on.
if you send "off",LED will turn off.

9.For Node-red "server.json" file you must install node-red on your computer before. follow these step
	-open CMD and input command >> for window >> npm install -g --unsafe-perm node-red  
				    >> for ios    >> sudo npm install -g --unsafe-perm node-red
	-so you can run node-red by this command  >> node-red
	-you will get a link to connected to broker that you can open it in browser.
	-when you open it on browser you can import json file from your computer.
	-then deploy it.
	-it will signal for you that it have connected with MQTT broker and serial port.
	-you can open dashbroad.

