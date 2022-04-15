//Entradas
//Entrada analógica entre 0 y 1023 (10 bits)
const int potenciometro = A0;
//Salidas
const byte motor = 5;
const byte rele = 3;
const byte arranque = 2;
//Constantes

//Variables
byte velocidad;
//  señal recibida por bluetooth
 
void setup(){
  //Serial.begin(9600);
  pinMode(potenciometro, INPUT);
  pinMode(arranque, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
  pinMode(rele, OUTPUT);
}
void loop(){
  //Arranque manual del motor
  if (!digitalRead(arranque))
  {
    while (digitalRead(arranque))
    {
      digitalWrite(rele, HIGH);
      delay(100);
    }
    digitalWrite(rele, LOW);
  }
  
  //Se divide entre 4 porque el pwm es de 8 bits (256)
  velocidad = map(analogRead(potenciometro), 0, 1023, 0, 250);
  analogWrite(motor, velocidad);
  delay(50);
  velocidad = analogRead(potenciometro);
}