#include <SoftwareSerial.h>
SoftwareSerial mySerial(A4, A5); //Rx,
//Entradas

//Salidas
  const byte motor = 5;

//Constantes

//Variables
byte velocidad;
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
    char data[2];
    size_t count = mySerial.readBytesUntil('\n', data, 2);
    
    DEBUG(data, count);
    if (data == 'ON')
    {
      encendido = true;
    }
    else if (data == 'OF')
    {
      encendido = false;
    }
    else
    {
      velocidad = (unsigned byte)data[0];
    }
  }
  //Se divide entre 4 porque el pwm es de 8 bits (256)
  if (encendido)
  {
    analogWrite(motor, 0);
  }
  else
  {
    analogWrite(motor, velocidad);
  }
  serialFlush();
  delay(50);
}

void DEBUG(char a[2], size_t b)
{
  if (a[0] == 'O' && a[1] == 'N')
  {
    for (int index = 0; index < b; index++)
      Serial.print(a[index]);
  }
  else if (a[0] == 'O' && a[1] == 'F')
  {
    for (int index = 0; index < b; index++)
      Serial.print(a[index]);
  }
  else
  {
    Serial.print((unsigned byte)a[0]);
  }
  Serial.println();
}
void serialFlush(){
  while(mySerial.available() > 0) {
    char t = mySerial.read();
  }
}
