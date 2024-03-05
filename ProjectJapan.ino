#define BLYNK_TEMPLATE_ID "TMPL6pYeyPJ-m"
#define BLYNK_TEMPLATE_NAME "LEDTEST"
#define BLYNK_AUTH_TOKEN "HqVxQ1lq1p4B9J9-PcsI3JCH3iWaaJvw" 

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

#define DHTPIN 14 
#define DHTTYPE DHT11 
#define LED_PIN 2  // Sử dụng GPIO 2 cho LED

char ssid[] = "Fatlab";
char pass[] = "12345678@!";

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Kiểm tra xem giá trị từ DHT11 có hợp lệ không
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!!");
    return;
  }
  
  // Gửi nhiệt độ và độ ẩm lên Blynk
  Blynk.virtualWrite(V1, t); // Gửi nhiệt độ lên V1 trong Blynk
  Blynk.virtualWrite(V2, h); // Gửi độ ẩm lên V2 trong Blynk
}

void setup() {
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);
  timer.setInterval(2000L, sendSensor); // Cập nhật giá trị cảm biến mỗi 2 giây
}

void loop() {
  Blynk.run();
  timer.run();
}

BLYNK_WRITE(V0) {
  int pinValue = param.asInt(); // Nhận giá trị từ pin V0
  digitalWrite(LED_PIN, pinValue); // Điều khiển LED ON hoặc OFF
}
