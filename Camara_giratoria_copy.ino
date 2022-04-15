//Entradas
const byte Potenciometro = A0;
//Salidas
const byte motor = 6;
//Constantes
const bool MODO_POTENCIOMETRO = false;
const bool MODO_BLUETOOTH = true;

//Variables
//  señal recibida por bluetooth
char option;
byte velocidad;
bool modo;
 
void setup(){
  Serial.begin(9600);
  pinMode(Potenciometro, INPUT);
  pinMode(motor, OUTPUT)
}
void loop(){
  //existen 2 modos: bluetooth y modo potenciómetro
  //Estados
  //1. Encontrar modo

    //leer bluetooth
    //encontrar modo

  //2. 
  //modo bluetooth

  //si existe información pendiente
  if (Serial.available()>0){
    //leeemos la opcion
    option = Serial.read();
    //si la opcion esta entre '1' y '9'
    switch (option)
    {
    case 'B':
        modo = MODO_BLUETOOTH;
        break;
    case 'P':
        modo = MODO_POTENCIOMETRO
        break;
    }
  }
}