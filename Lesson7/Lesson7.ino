//Declare infrared input pins
int ir1=A0, ir3=A2, ir5=A7;

//Declare motor variables
int pwmL1=3, pwmL2=5, pwmR1=9, pwmR2=10;

void setup() {
  // put your setup code here, to run once:
  pinMode(pwmL1,OUTPUT); digitalWrite(pwmL1,LOW);
  pinMode(pwmL2,OUTPUT); digitalWrite(pwmL2,LOW);
  pinMode(pwmR1,OUTPUT); digitalWrite(pwmR1,LOW);
  pinMode(pwmR2,OUTPUT); digitalWrite(pwmR2,LOW);

  for (int i=0; i<3;i++){
    forward(255,255);
    delay(1000);
    backward(255,255);
    delay(1000);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

//Motor movement
void forward (int speed1, int speed2){
  digitalWrite(pwmL2,0); digitalWrite(pwmR2,0);
  analogWrite(pwmL1,speed1); analogWrite(pwmR1,speed2);
}

void backward (int speed1, int speed2){
  digitalWrite(pwmL1,0); digitalWrite(pwmR1,0);
  analogWrite(pwmL2,speed1); analogWrite(pwmR2,speed2);
}

void right (int speed1, int speed2){
  digitalWrite(pwmL2,0); digitalWrite(pwmR1,0);
  analogWrite(pwmL1,speed1); analogWrite(pwmR2,speed2);
}

void left (int speed1, int speed2){
  digitalWrite(pwmL1,0); digitalWrite(pwmR2,0);
  analogWrite(pwmL2,speed1); analogWrite(pwmR1,speed2);
}
