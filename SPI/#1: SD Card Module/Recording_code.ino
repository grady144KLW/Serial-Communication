#include <SD.h>
#include <SPI.h>

int b = 9; // delcaring the pin blue LED

int pot = A3; // declaring the pin of the potentiometer
int val_; // delaring the values of the potentiometer

const int cs = 4; // delcaring the chipselect pin of the sd card module 
File datafile;

void setup() {
  Serial.begin(9600); // turning on the serial monitor 
  SD.begin(cs); // initializing the sd library
    if(!SD.begin(cs)){
      Serial.println("error");
    }
  pinMode(b, OUTPUT);
  pinMode(pot, INPUT);
}

void loop() {
  val_ = map(analogRead(pot), 0, 1023, 0, 255); // mapping the values from the potentiometer to the LED
  analogWrite(b, val_); // adjusting the brightness of the LED
  datafile = SD.open("web2.txt", FILE_WRITE); // opening and writing the text file  
    if(datafile){ // if the file is avaiable 
      datafile.println(val_); // print the values to the text file 
      datafile.close(); // closing the text file
      Serial.println(val_); // printing the values to the serial monitor
    }
    else{
      Serial.println("another error");
    }
}
