//Entradas
//Entrada analógica entre 0 y 1023 (10 bits)
const int potenciometro = A0;
//Salidas
const byte motor = 5;
const byte encendido = 2;
//Constantes

//Variables
byte velocidad;
//  señal recibida por bluetooth
 
void setup(){
  //Serial.begin(9600);
  pinMode(potenciometro, INPUT);
  pinMode(encendido, INPUT_PULLUP);
  pinMode(motor, OUTPUT);
}
void loop(){
  //Arranque manual del motor
  
  //Se divide entre 4 porque el pwm es de 8 bits (256)
  velocidad = map(analogRead(potenciometro), 0, 1023, 0, 255);
  analogWrite(motor, velocidad);
  delay(50);
  velocidad = analogRead(potenciometro);
}