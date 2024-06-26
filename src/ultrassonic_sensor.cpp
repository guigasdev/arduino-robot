// C++ code
//
#include <Servo.h>
 
Servo servo_11;
 
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Limpa o trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Set delay para 2 MS
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Leitura do PinMode
  return pulseIn(echoPin, HIGH);
}
 
void setup()
{
  servo_11.attach(11, 500, 2500);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  servo_11.write(90);
}
 
void loop(){
int frente =  0.01723 * readUltrasonicDistance(A0, A1);
int direita;
int esquerda;
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
 
  if (frente < 30) {
    digitalWrite(4, LOW);
    analogWrite(5, 0);
    analogWrite(6, 0);
    digitalWrite(7, LOW);
 
    servo_11.write(0);
    delay(1000); 
    direita = 0.01723 * readUltrasonicDistance(A0, A1);
    servo_11.write(180);
    delay(2000); 
    esquerda = 0.01723 * readUltrasonicDistance(A0, A1);
 
    if (direita > esquerda) {
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      delay(400);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
    }
    if (direita < esquerda) {
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      delay(400);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
    }
  }
servo_11.write(90);
delay(200);
}

//Manda um gatilho para o servo com delay de 200MS