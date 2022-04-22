#include <SoftwareSerial.h>
SoftwareSerial mySerial(A4, A5); //Rx,
//Entradas

//Salidas
  const byte motor = 5;

//Constantes

//Variables
  byte velocidad[1];
  bool encendido;
//  señal recibida por bluetooth

void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  mySerial.setTimeout(50);
  pinMode(motor, OUTPUT);
}
void loop(){
  //Bluetooth
  if (mySerial.available()) {
    mySerial.readBytes(velocidad,1);
    serialFlush();
    
    Serial.println(velocidad[0]);
    analogWrite(motor, velocidad[0]);
  }
}
// Borrar datos del puerto serial
void serialFlush(){
  while(mySerial.available() > 0) {
    char t = mySerial.read();
  }
}