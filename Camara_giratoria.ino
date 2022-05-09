#include <EEPROM.h>
#include <SoftwareSerial.h>
//Puertos seriales por definidos por software
SoftwareSerial mySerial(A4, A5); //Rx,
//Entradas

//Salidas
  const byte motor = 5;

//Constantes
  
  //número de bytes recibidos por bluetooth a la vez
  const int bytes = 2;
//Variables

  //  Cadena de bytes recibidos por el móduilo bluetooth
  char data[bytes];
  bool encendido;
  byte velocidad;

  int tiempoArranque;

  unsigned long tiempoGiro;

  unsigned long timer;
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
    mySerial.readBytes(data,bytes);
    serialFlush();
    //2 bytes. el byte 0 es para enviar el tipo de comando y el byte 1 para una cantidad
    //byte 0
    //  0: apagar
    //  1: encender
    //  2: enviar velocidad
    //  3: enviar tiempo de arranque
    switch (data[0])
    {
    case 0:
      encendido = false;
      Serial.println("Apagado");
      break;
    
    case 1:
      encendido = true;
      Serial.println("Encendido");
      break;
    
    case 2:
      velocidad = data[1];
      Serial.print("Velocidad: ");
      Serial.println((byte)data[1]);
      break;
    
    case 3:
      tiempoArranque = data[1];
      Serial.print("tiempo de arranque");
      break;
    
    case 4:
      tiempoGiro = data[1];
      Serial.println("Encendido");
      break;
    }

    Serial.println(velocidad);
    analogWrite(motor, velocidad);
  }
}
// Borrar datos del puerto serial
void serialFlush(){
  while(mySerial.available() > 0)
    char t = mySerial.read();
}
void DEBUG(char data[bytes], size_t count){
  for (int index = 0; index < count; index++)
    Serial.print(data[index]); 
  Serial.println();
}