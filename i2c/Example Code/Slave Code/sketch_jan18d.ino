#include <Wire.h> // Adding the library for the i2c

#define slave_address 9 // Declaring the address

int r = 11; // Declaring the LED pin
int x; // declaring the variable to store the values from the Master code

void setup() {
Wire.begin(slave_address); // initializing the wire library and assigning it to the address
Serial.begin(9600);
pinMode(r, OUTPUT);
Wire.onReceive(receiveEvent); // receiving the values from the Master code
}

void loop() {
receiveEvent();
}

void receiveEvent(){
x = Wire.read(); // reading the values from the master code    
analogWrite(r,x); // adjusting the brightness of the led from the values in the master code
Serial.println(x); // printing the values from the master code 
delay(100);
}
