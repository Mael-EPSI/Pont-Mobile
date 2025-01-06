#include <Wire.h>
#include "rgb_lcd.h"
#include <Servo.h>

// Rename library
rgb_lcd lcd;

Servo monservo;
Servo monservo2;

// Define timer
const int countdownDuration = 10;

// Define variables 
int leds_red_tri = 12;
int leds_green_tri = 13;
int leds_yellow_tri = 11;

int leds_red_bi = 6;
int leds_green_bi = 5;

int lock = 0;
int btn_pin = 10;

void setup() {
    Serial.begin(9600);
    pinMode(btn_pin, INPUT);
    
    // Set up RGB LCD
    lcd.begin(16, 2);
    lcd.setRGB(255, 255, 255);
    
    // Set up servos
    monservo.attach(9);
    monservo2.attach(10);
    monservo.write(0);
    monservo2.write(0);
    
    // Set up LEDs tricolor
    pinMode(leds_red_tri, OUTPUT);
    pinMode(leds_green_tri, OUTPUT);
    pinMode(leds_yellow_tri, OUTPUT);

    // Set up LEDs bicolors
    pinMode(leds_red_bi, OUTPUT);
    pinMode(leds_green_bi, OUTPUT);
}
void loop[
    int btn_val = digitalRead(btn_pin);
    Serial.println(btn_val);
    
    // Button press
    if (btn_val == LOW && lock = 1){
        digitalWrite(leds_red_tri, LOW);
        digitalWrite(leds_green_tri, HIGH);
        digitalWrite(leds_yellow_tri, LOW);
        delay(200)
        digitalWrite(leds_green_tri, LOW);
        digitalWrite(leds_yellow_tri, HIGH);
        delay(200)
        digitalWrite(leds_yellow_tri, LOW);
        digitalWrite(leds_green_tri, LOW);
        digitalWrite(leds_red_tri, HIGH);
        
        
        digitalWrite(leds_red_bi, LOW);
        digitalWrite(leds_green_bi, HIGH);

        monservo.write(90);
        monservo2.write(90);

        for (int i = countdownDuration, i > 0; i--){
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Estimation du ");
            lcd.setCursor(0, 1);
            lcd.print("Temps Restant: ");
            lcd.setCursor(14, 1);
            lcd.print(i);
            delay(1000);
        }
        lock = 0;
    }
    if(btn_val == HIGH && lock == 0){
        lock = 1;
        digitalWrite(leds_red_tri, LOW);
        digitalWrite(leds_green_tri, HIGH);
        digitalWrite(leds_yellow_tri, LOW);
        digitalWrite(leds_red_bi, HIGH);
        digitalWrite(leds_green_bi, LOW);

        // LCD 
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Vous pouvez");
        lcd.setCursor(0, 1);
        lcd.print("passer");

        monservo.write(0);
        monservo2.write(0);

        lock = 1;
    }
]