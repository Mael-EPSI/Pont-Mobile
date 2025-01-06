#define en1 9
#define in1 7
#define in2 6

#define pot 0;

void setup() {
    Serial.begin(9600);
    pinMode(14, INPUT); 
    pinMode(17, INPUT); 
    pinMode(en1, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);

    pinMode(pot, INPUT);
}

void loop() {
    int cfh = digitalRead(14);
    int cfb = digitalRead(17); 
    int potValue = analogRead(pot);
    Serial.println(potval);
    
    if((cfh == 1) && (potval < 400 )){
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(9, 0);
    }
    else if ((cfb == 1) && (potval > 700)){
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        analogWrite(9, 0);
    }
    else if(potval<400 && cfb ==0){
        analogWrite(9, 255);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
    }
    else if(potval>400 && potval<600){
        analogWrite(9, 0);
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
    }
    else if(potval>700 && cfh == 0){
        analogWrite(9, 255);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    }
}