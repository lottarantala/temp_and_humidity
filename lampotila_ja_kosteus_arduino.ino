#include <DHT.h>
#include <LiquidCrystal.h>
 
//DHTPIN defines to what fysical pin is the sensor in
#define DHTPIN 7
//Sensor type
#define DHTTYPE DHT22
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
//DHT constructor
DHT dht(DHTPIN, DHTTYPE);
 
//setup
void setup() {
  dht.begin();
  //set up LCDn rows and columns
  lcd.begin(16, 2);
}
 
//loops forever
void loop() {
  //delay before the first measurement, sensor is a bit slow
  delay(2000);
  //t = temperature, h = humidity
  float t, h;
 
  //reading values from DHT
  t = dht.readTemperature();
  h = dht.readHumidity();
 
  //checs if reading the values was succesful, if not, lets know in serial port
  if (isnan(h) || isnan(t)) {
    //prints in Finnish
    Serial.println("Sensorin lukeminen epäonnistui");
    //stops the loop
    return;
  }
  //first row
  lcd.setCursor(0, 0);
  //prints temperature
  lcd.print("Asteet: ");
  lcd.print(t);
  //second row
  lcd.setCursor(0, 1);
  //prints humidity in %
  lcd.print("Kosteus: ");
  lcd.print(h);
  lcd.print("%");
}
