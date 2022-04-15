//Entradas
const byte potenciometro = A0;
//Salidas
const byte motor = 5;
const byte rele = 3;
//Constantes

//Variables
byte velocidad;
//  señal recibida por bluetooth
 
void setup(){
  pinMode(potenciometro, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(rele, OUTPUT);
}
void loop(){
  digitalWrite(rele, HIGH);
  delay(1000);
  velocidad = analogRead(potenciometro);
  digitalWrite(rele, LOW);
  while (true)
  {
    if (velocidad > 255*0.98)
    {
      velocidad = 255*0.98;
    }
    analogWrite(motor, velocidad);
    if (velocidad < 26)
    {
      while (velocidad < 26)
      {
        velocidad = analogRead(potenciometro);
	analogWrite(motor, velocidad);
        delay(30);
      }
      break;
    }
    delay(500);
    velocidad = analogRead(potenciometro);
  }
}