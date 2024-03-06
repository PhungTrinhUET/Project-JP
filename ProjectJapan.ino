//***************************/Define your Blynk template ID, template name and Auth Token/**************************************************
#define BLYNK_TEMPLATE_ID "TMPL6vBkTXD55"
#define BLYNK_TEMPLATE_NAME "AGUET"
#define BLYNK_AUTH_TOKEN "xbqDxt56ReAadRp_lZ2M92js2wJY3G9i"

//***************************/Including necessary libraries for WiFi and Blynk functionalities/**********************************************
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

//***************************/Including the DHT sensor library/******************************************************************************
#include <DHT.h>

//***************************/Define the DHT sensor pin and type/******************************************************************************
#define DHTPIN 14 
#define DHTTYPE DHT11 

//***************************/Define the GPIO pin for Prothe LED/*********************************************************************************
#define LED_PIN 2  

//***************************/Wifi credentials (Change the Wi-Fi name and Wi-Fi password)/*****************************************************
char ssid[] = "Fatlab";
char pass[] = "12345678@!";

//***************************/Initialize the DHT sensor/***************************************************************************************
DHT dht(DHTPIN, DHTTYPE);

//***************************/Initialize a Blynk timer/***************************************************************************************
BlynkTimer timer;

//***************************/Function to send sensor data to Blynk/***************************************************************************
void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

   //-------------------------Check if the sensor readings are valid-------------------------------------------------------------------------
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!!");
    return;
  }
  
  //--------------------------Send temperature and humidity data to Blynk--------------------------------------------------------------------
  Blynk.virtualWrite(V1, t); // Send temperature to V1 in Blynk
  Blynk.virtualWrite(V2, h); // Send Humidity to V2 in Blynk
}
//***********************************Void setup***********************************************************************************************
void setup() {
   //-------------------------Initialize serial communication-------------------------------------------------------------------------------
  Serial.begin(9600);
  //--------------------------Begin Blynk---------------------------------------------------------------------------------------------------
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  //--------------------------Start the DHT sensor------------------------------------------------------------------------------------------
  dht.begin();
  //--------------------------Set LED pin as output-----------------------------------------------------------------------------------------
  pinMode(LED_PIN, OUTPUT);
  //--------------------------Setup a function to be called every 2000 miliseconds
  timer.setInterval(2000L, sendSensor); 
}

//***********************************Void loop***********************************************************************************************
void loop() {
   //-------------------------Run Blynk-------------------------------------------------------------------------------------------------------
  Blynk.run();
  //--------------------------Run the Blynk timer---------------------------------------------------------------------------------------------
  timer.run();
}
//----------------------------Function to control LED with Blynk app-----------------------------------------------------------------------
BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); // Get value from V0 pin in Blynk app
  digitalWrite(LED_PIN, pinValue); // Control LED ON/OFF
}
