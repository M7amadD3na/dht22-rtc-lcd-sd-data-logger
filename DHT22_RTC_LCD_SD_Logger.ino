#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <RTClib.h>
#include <SD.h>

// ===== DHT =====
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// ===== RTC =====
RTC_DS3231 rtc;

// ===== LCD =====
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ===== SD =====
#define CSPIN 4
File dataFile;

// ===== TIMER =====
unsigned long previousMillis = 0;
const unsigned long interval = 2000;

void setup() {
  lcd.init();
  lcd.backlight();

  dht.begin();
  rtc.begin();

  if (!SD.begin(CSPIN)) {
    lcd.print("SD Failed");
    while (1);
  }
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  lcd.print("System Ready");
  delay(1500);
  lcd.clear();
  if (!SD.exists("data.csv")) {
  dataFile = SD.open("data.csv", FILE_WRITE);
  if (dataFile) {
    dataFile.println("DateTime,Temperature,Humidity");
    dataFile.close();
  }
}

}

void loop() {
  unsigned long currentMillis = millis();
  

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    DateTime now = rtc.now();

    float temp = dht.readTemperature();
    float hum  = dht.readHumidity();

    if (isnan(temp) || isnan(hum)) {
      lcd.clear();
      lcd.print("Sensor Error");
      return;
    }

    // ===== LCD =====
    lcd.clear();
    lcd.setCursor(0,0);
  lcd.print(now.timestamp(DateTime::TIMESTAMP_TIME));
    
lcd.setCursor(0,1);
    lcd.print("T:");
    lcd.print(temp);
    lcd.print("C ");

   
    lcd.print("H:");
    lcd.print(hum);
    lcd.print("%");

    // ===== SD =====
   
    dataFile = SD.open("data.csv", FILE_WRITE);
if (dataFile) {
  dataFile.print(now.timestamp(DateTime::TIMESTAMP_FULL));
  dataFile.print(",");
  dataFile.print(temp);
  dataFile.print(",");
  dataFile.println(hum);
  dataFile.close();
}

  }
}
