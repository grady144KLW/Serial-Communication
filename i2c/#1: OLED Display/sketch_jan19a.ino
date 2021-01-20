#include <DHT.h>
#include <DHT_U.h>

#include <Adafruit_SSD1306.h>
#include <splash.h>

#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Wire.h>


#define reset 4 // declaring a reset pin
Adafruit_SSD1306 display(reset); // declaring an object to represent the display

#define Type DHT11 // declaring what type of dht sensor is it
int pin = 2; // declaring the pin of the dht11 sensor
DHT dht(pin, Type); // declaring the object of the dht11 sensor
float humidity; // declaring the humidity variable
float temperature; // declaring the temperature variable

void setup() {
Wire.begin();
display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initializing the display with the address 
dht.begin();

}

void loop() {
humidity = dht.readHumidity(); // reading the humidity values and assigning it to the variable
temperature = dht.readTemperature(); // reading the humidity values and assigning it to the variable

display.clearDisplay(); // updating the text of the display
display.setTextColor(WHITE); // setting the text colour
display.setTextSize(1); // setting the size of the text
display.setCursor(0,0); // setting the cursor at the top
display.print("GTK Website"); // printing on the top of the cursor 
display.setCursor(0,10); // setting the cursor at the middle 
display.print("Temperature: "); // printing at the middle of the cursor 
display.print(temperature); // printing the temperature values
display.print(" C"); // printing the unit of the temperature
display.setCursor(0, 20); // setting the cursor at the bottom 
display.print("Humidity: "); // printing at the middle of the cursor 
display.print(humidity); // printing the humidity values
display.print("%"); // printing the unit of the humidity
display.display(); // telling the oled to actually display what was instructed 
}
