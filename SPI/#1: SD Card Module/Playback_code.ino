#include <SD.h>
#include <SPI.h>

int b = 9; // declaring the pin on the LED

const int cs = 4; // declaring the chipselect pin on the sd card module
File datafile; // creating a file object 
int val_; // declaring the value variable to store the values in the file

void setup() {
  Serial.begin(9600); // turning on the serial monitor
  pinMode(b, OUTPUT); // declaring the LED as output
  SD.begin(cs); // initalizing the sd library 
    if (!SD.begin(cs)){ // if there isn't any initalization 
      Serial.println("error on SD"); // print error on serial monitor 
    } 
  datafile = SD.open("web2.txt"); // opening and reading the file
    if(datafile){
      while(datafile.available()){ // waiting for any data/values on the file
        val_ = datafile.parseInt(); // reading the values in the file
        Serial.println(val_); // printing the values on the Serial Monitor
        analogWrite(b, val_); // displaying the values on the LED
      }
      datafile.close(); // closing the file
    }
    else{
      Serial.println("error on the file");
    }
}

void loop() {

}
