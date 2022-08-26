//Declaring GPIO Pins

int L3 =13; //LED 3 to pin 13
int ir3= A3; //IR 3 to pin A3

//White values
int offset= 50; //Additional value to set white
int state3_white=20 + offset; //Set value of white with extra

void setup (){

    pinMode(L3,OUTPUT);
    pinMode(ir3,INPUT);
    Serial.begin(9600);

}

void loop(){

    int state3= analogRead(ir3);
    Serial.println (state3);

    //----Start conditional statement here----





    //-----------End here---------------
}