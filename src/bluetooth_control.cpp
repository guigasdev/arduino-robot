#include <SoftwareSerial.h>
 
// Definição dos pinos para comunicação com o módulo Bluetooth
int bluetoothTx = 9;  // Pino TX do módulo Bluetooth conectado ao RX do Arduino
int bluetoothRx = 8;  // Pino RX do módulo Bluetooth conectado ao TX do Arduino
 
// Inicialização do objeto para comunicação Bluetooth
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);
 
 
void setup() 
{
  // Inicialização da comunicação serial padrão (para comunicação com o computador via USB)
  Serial.begin(9600);
 
  // Inicialização da comunicação serial com o módulo Bluetooth
  bluetooth.begin(9600);
 
  // Motor Esquerdo
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
}
 
 
void loop() 
{
   if(bluetooth.available() > 0)
   {
	char direcao = bluetooth.read();
    // CARRINHO ANDAR PARA FRENTE
    if (direcao == 'F') {
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(13,HIGH);
 
    }
    // CARRINHO ANDAR PARA TRÁS!
    if(direcao == 'B') {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    }
 
    // CARRINHO ANDAR PARA ESQUERDA
 
    if(direcao == 'R') {
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
 
 
    if(direcao == 'L'){
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
    }
    //CARRINHO ANDAR PRA TRAS DIREITA
    if(direcao == 'P') {
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    }    
    if(direcao == 'S') {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    }
   }
    // CARRINHO ANDAR PARA DIREITA
 
}