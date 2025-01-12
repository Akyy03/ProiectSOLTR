#include <Wire.h>
#include <BH1750.h>
#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT11
#define LIGHT_SENSOR_PIN 2

DHT dht(DHTPIN, DHTTYPE);
BH1750 lightMeter;

void setup() {
  Serial.begin(9600);
  dht.begin();

  Wire.begin();
  lightMeter.begin();

  Serial.println("Incepem citirile de la senzori...");
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  float lux = lightMeter.readLightLevel();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Eroare la citirea senzorului DHT11!");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print(" °C");
  Serial.print("  Umiditatea: ");
  Serial.print(humidity);
  Serial.print(" %  ");

  Serial.print("Lumina: ");
  Serial.print(lux);
  Serial.println(" lx");

  delay(2000);
}