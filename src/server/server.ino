#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include "ircodes.h"
#include "tv_page.h"

const char *ssid = // ssid here
const char *password = // password here
const char *domain = "station";
const int port = 80;
const int ir_led_pin = 12;

IRsend irsend(ir_led_pin);
ESP8266WebServer server(port);


// ----- Start of Handlers ----- //

void rootHandler(){
  Serial.println("Requested root");
	server.send(200, "text/html", tv_page);
}

// ----- Start of TV Controller ----- //
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

void tvButton1Handler(){
  
}

void tvButton2Handler(){
  
}

void tvButton3Handler(){
  
}

void tvButton4Handler(){
  
}

void tvButton5Handler(){
  
}

void tvButton6Handler(){
  
}

void tvButton7Handler(){
  
}

void tvButton8Handler(){
  
}

void tvButton9Handler(){
  
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

  server.on("/",rootHandler);
  server.on("/tvPower",tvPowerHandler);
  server.on("/tvVolumeUp",tvVolumeUpHandler);
  server.on("/tvVolumeDown",tvVolumeDownHandler);
  server.on("/tvChannelUp",tvChannelUpHandler);
  server.on("/tvChannelDown",tvChannelDownHandler);
 
  server.begin();

}

void loop(){
	server.handleClient();
}





 
