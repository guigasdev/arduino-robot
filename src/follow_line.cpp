// C++ code
//
int velocidadeD = 255; 
int velocidadeE = 255;
int direita = 0;
 
int esquerda = 0;
 
void setup()
{
  pinMode(12, INPUT);
  pinMode(3, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}
 
void loop()
{
  if (digitalRead(3) == HIGH && digitalRead(12) == HIGH) {
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }
  if(digitalRead(3) == LOW && digitalRead(12) == LOW){
    analogWrite(6, 200);
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    analogWrite(5, 200);
 
  }else if (digitalRead(3) == HIGH && digitalRead(12) == LOW) {
    analogWrite(6, 200);
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
    analogWrite(5, 55);
    } else if(digitalRead(3) == LOW && digitalRead(12) == HIGH) {
    analogWrite(6, 55);
    digitalWrite(7, HIGH);
    digitalWrite(4, LOW);
    analogWrite(5, 200);
 
 
    }
 
 
 
 
 
  delay(10); // Delay a little bit to improve simulation performance
}