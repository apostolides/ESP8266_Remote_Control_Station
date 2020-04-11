#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include "ircodes.h"
#include "tv_page.h"
#include "index_page.h"

const char *ssid = //
const char *password = //
const char *domain = "station";
const int port = 80;
const int ir_led_pin = 12;

IRsend irsend(ir_led_pin);
ESP8266WebServer server(port);


// ----- Start of Handlers ----- //

void rootHandler(){
  Serial.println("Requested root");
	server.send(200, "text/html", index_page);
}

// ----- Start of TV Controller ----- //

void tvRemoteHandler(){
  Serial.println("Requested tv remote main page");
  server.send(200, "text/html", tv_page);
}

void tvPowerHandler(){
  Serial.println("Requested tv power");
  irsend.sendRaw(rawDataTVPower,sizeof(rawDataTVPower),38);
  server.send(200, "text/html", "Requested tv power"); 
}

void tvMuteHandler(){
  Serial.println("Requested tv mute");
  irsend.sendRaw(rawDataMute,sizeof(rawDataMute),38);
  server.send(200, "text/html", "Requested tv mute"); 
}

void tvVolumeUpHandler(){
  Serial.println("Requested tv vol up");
  irsend.sendRaw(rawDataVolumeUp,sizeof(rawDataVolumeUp),38);
  server.send(200, "text/html", "Requested tv vol up");
}

void tvVolumeDownHandler(){
  Serial.println("Requested tv vol down");
  irsend.sendRaw(rawDataVolumeDown,sizeof(rawDataVolumeDown),38);
  server.send(200, "text/html", "Requested tv vol down");
}

void tvChannelUpHandler(){
  Serial.println("Requested tv channel up");
  irsend.sendRaw(rawDataChannelUp,sizeof(rawDataChannelUp),38);
  server.send(200, "text/html", "Requested channel up");
}

void tvChannelDownHandler(){
  Serial.println("Requested tv channel down");
  irsend.sendRaw(rawDataChannelDown,sizeof(rawDataChannelDown),38);
  server.send(200, "text/html", "Requested tv channel down"); 
}

void tvMute(){
  Serial.println("Requested tv mute");
  irsend.sendRaw(rawDataMute, sizeof(rawDataMute), 38);
  server.send(200, "text/html", "Requested tv mute");
}

void tvButton0Handler(){
  Serial.println("Requested channel 0");
  irsend.sendRaw(tvrawData0,sizeof(tvrawData0),38);
  server.send(200, "text/html", "Requested channel 0");
}

void tvButton1Handler(){
  Serial.println("Requested channel 1");
  irsend.sendRaw(tvrawData1,sizeof(tvrawData1),38);
  server.send(200, "text/html", "Requested channel 1");
}

void tvButton2Handler(){
  Serial.println("Requested channel 2");
  irsend.sendRaw(tvrawData2,sizeof(tvrawData2),38);
  server.send(200, "text/html", "Requested channel 2");
}

void tvButton3Handler(){
  Serial.println("Requested channel 3");
  irsend.sendRaw(tvrawData3,sizeof(tvrawData3),38);
  server.send(200, "text/html", "Requested channel 3");
}

void tvButton4Handler(){
  Serial.println("Requested channel 4");
  irsend.sendRaw(tvrawData4,sizeof(tvrawData4),38);
  server.send(200, "text/html", "Requested channel 4");
}

void tvButton5Handler(){
  Serial.println("Requested channel 5");
  irsend.sendRaw(tvrawData5,sizeof(tvrawData5),38);
  server.send(200, "text/html", "Requested channel 5");
}

void tvButton6Handler(){
  Serial.println("Requested channel 6");
  irsend.sendRaw(tvrawData6,sizeof(tvrawData6),38);
  server.send(200, "text/html", "Requested channel 6");
}

void tvButton7Handler(){
  Serial.println("Requested channel 7");
  irsend.sendRaw(tvrawData7,sizeof(tvrawData7),38);
  server.send(200, "text/html", "Requested channel 7");
}

void tvButton8Handler(){
  Serial.println("Requested channel 8");
  irsend.sendRaw(tvrawData8,sizeof(tvrawData8),38);
  server.send(200, "text/html", "Requested channel 8");
}

void tvButton9Handler(){
  Serial.println("Requested channel 9");
  irsend.sendRaw(tvrawData9,sizeof(tvrawData9),38);
  server.send(200, "text/html", "Requested channel 9");
}
// ----- End of TV Controller ----- //

// ----- End of Handlers ----- //

void setup(){
	Serial.begin(115200);
	WiFi.begin(ssid, password);
	Serial.print("\nConnecting to network");
	
	while(WiFi.status() != WL_CONNECTED){
		delay(500);
		Serial.print(".");
	}
	Serial.print("\nConnected to: ");
	Serial.println(ssid);
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());

  irsend.begin();

  server.on("/", rootHandler);
  server.on("/tvRemote",tvRemoteHandler);
  server.on("/tvMute",tvMuteHandler);
  server.on("/tvPower",tvPowerHandler);
  server.on("/tvVolumeUp",tvVolumeUpHandler);
  server.on("/tvVolumeDown",tvVolumeDownHandler);
  server.on("/tvChannelUp",tvChannelUpHandler);
  server.on("/tvChannelDown",tvChannelDownHandler);
  server.on("/tvMute", tvMute);
  server.on("/tv0", tvButton0Handler);
  server.on("/tv1", tvButton1Handler);
  server.on("/tv2", tvButton2Handler);
  server.on("/tv3", tvButton3Handler);
  server.on("/tv4", tvButton4Handler);
  server.on("/tv5", tvButton5Handler);
  server.on("/tv6", tvButton6Handler);
  server.on("/tv7", tvButton7Handler);
  server.on("/tv8", tvButton8Handler);
  server.on("/tv9", tvButton9Handler);
  
  server.begin();

}

void loop(){
	server.handleClient();
}





 
