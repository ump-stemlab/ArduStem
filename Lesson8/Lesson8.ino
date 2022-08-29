//Declare infrared input pins
int ir1=A0, ir3=A2, ir5=A7;

//Declare motor variables
int pwmL1=3, pwmL2=5, pwmR1=9, pwmR2=10;

//Declare auto-calibration variables
int ir1min=1023, ir3min=1023, ir5min=1023;
int ir1max=0, ir3max=0, ir5max=0;
int ir1avg=0, ir3avg=0, ir5avg=0;

//Declare initial state value
int state1=0, state3=0, state5=0;

void setup() {

  //Setting pinmode for infrared
  pinMode(ir1, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir5, INPUT);

  //Setting pinmode for DC motor
  pinMode(pwmL1,OUTPUT); digitalWrite(pwmL1,LOW);
  pinMode(pwmL2,OUTPUT); digitalWrite(pwmL2,LOW);
  pinMode(pwmR1,OUTPUT); digitalWrite(pwmR1,LOW);
  pinMode(pwmR2,OUTPUT); digitalWrite(pwmR2,LOW);

  //Auto Calibration for infrared sensor
  right(128,128); //Make the stembot rotate to the right

  for (int i=0; i<300; i++){

    //Calibrate ir1 value
    state1=analogRead(ir1);
    if(ir1min>state1){
      ir1min=state1;
    }else{
      ir1max=state1;
    }

    //Calibrate ir3 value
    state3=analogRead(ir3);
    if(ir3min>state3){
      ir3min=state3;
    }else{
      ir3max=state3;
    }

    //Calibrate ir5 value
    state5=analogRead(ir5);
    if(ir5min>state5){
      ir5min=state5;
    }else{
      ir5max=state5;
    }
    
    delay(10);

  }

  forward(0,0);

  //Calculate average value

  ir1avg = (ir1min + ir1max)/2;
  ir3avg = (ir3min + ir3max)/2;
  ir5avg = (ir5min + ir5max)/2;

  delay(2000);  

}

void loop() {

  int state1 = analogRead(ir1);
  int state3 = analogRead(ir3);
  int state5 = analogRead(ir5);

  //Detect line on the right and turn left
  if ((state5>ir5avg) && (state3<ir3avg)){
    left(128,128);
  } 
  
  //Detect Line on the left and turn right
  else if((state1>ir1avg) && (state3<ir3avg)){
    right(128,128);
  } 
  
  //Detect right junction
  else if((state1>ir1avg) && (state3>ir3avg)){
    forward(255,255);
    delay(10);
    right(128,128);
    delay(200);
  } 

   else if((state5>ir5avg) && (state3>ir3avg)){
    forward(255,255);
    delay(10);
    left(128,128);
    delay(200);
  } 
  
  //detect no junction: forward
  else {
    forward (255,255);
  }

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
