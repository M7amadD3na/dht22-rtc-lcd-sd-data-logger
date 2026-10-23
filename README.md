# DHT22 Data Logger with RTC, LCD, and SD Card

Reads temperature and humidity, shows values and time on an LCD, and logs timestamped measurements to a CSV file on an SD card.

## Technologies

DHT22, DS3231 RTC, I2C LCD, SD card

## Requirements

`DHT` (Adafruit DHT sensor library), `RTClib`, `LiquidCrystal_I2C`, `SD`, and `Wire`.

## Hardware and setup notes

DHT22 data GPIO2; SD card chip select GPIO4; DS3231 and LCD connect over I2C. The logger writes `data.csv` every 2 seconds.

## Run

1. Install the Arduino IDE and the required board support and libraries.
2. Open `DHT22_RTC_LCD_SD_Logger.ino` from this folder.
3. Review pin assignments, the target board, and any network settings.
4. Replace placeholders (such as `YOUR_THINGSPEAK_WRITE_API_KEY`) with **your own settings locally**. Never commit real passwords or API keys.
5. Compile and upload to compatible hardware; monitor serial output where relevant.

> Note: This portfolio package is a cleaned copy of an existing project sketch, not a claim that it was retested on hardware or security-hardened.
