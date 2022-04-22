#include <SoftwareSerial.h>


int Buzz_Pin = 4;
int Led_Pin = 6;
char input = 'a';

SoftwareSerial Blue(2,3);

void setup()

{

// Initialization of Serials and Pin Mode

Serial.begin(9600);
Blue.begin(9600);
pinMode(Buzz_Pin,OUTPUT);
pinMode(Led_Pin, OUTPUT);

// Setup Completed

Serial.println("Configuracion bluetooth");

}

void loop()

{
  // At the Start of the loop making output low
  digitalWrite(Buzz_Pin,LOW);
digitalWrite(Led_Pin,LOW);
  //Loop will run only if there any msg.
  while(Serial.available() > 0 ){
      //Reading msg from the Mobile device
  input = Serial.read();
       //SOS Message will be sent from Mobile device
    if(input == 'S'){
      digitalWrite(Led_Pin,HIGH);
      digitalWrite(Buzz_Pin,HIGH);
          Serial.println("TURNED ON");
      delay(1000);
  }
}
}