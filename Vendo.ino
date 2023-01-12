#include <Servo.h>

#define SWA A3
#define SWB A2
#define SWC A1


Servo myservoA;
Servo myservoB;
Servo myservoC;

int sensor = 3;
int Buzz = 5;
bool picked = false;
const int coin = 2;
boolean insert = false;
volatile int pulse = 0;
volatile unsigned long timelastPulse = 0;
int buttonState = 0;
int credits = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(coin, INPUT_PULLUP);
  pinMode(13, OUTPUT);
   pinMode(Buzz, OUTPUT);
  pinMode(SWA, INPUT_PULLUP);
  pinMode(SWB, INPUT_PULLUP);
  pinMode(SWC, INPUT_PULLUP);
  buzzer();
  delay(2000);
}

void loop() {

Serial.println(" --ye");
  while (!insert) {
    Serial.println("insert");
    attachInterrupt(digitalPinToInterrupt(coin), coinInterrupt, FALLING);
  }
  
  if ((digitalRead(SWA) == LOW) && (picked ==  false)) {
    buzzer();
    picked = true;
    buttonState = 1;
    Serial.println("maxx");
    myservoA.attach(7);
    myservoA.write(180);

  }
  if ((digitalRead(SWB) == LOW) && (picked == false)) {
     buzzer();
    picked = true;
    buttonState = 2;
    Serial.println("XO");
    myservoB.attach(8);
    myservoB.write(180);
  }
  if ((digitalRead(SWC) ==  LOW) && (picked == false)) {
     buzzer();
    picked = true;
    buttonState = 3;
    Serial.println("SnowBear");
    myservoC.attach(9);
    myservoC.write(180);
  }


  if (digitalRead(sensor) == LOW) {
    buttonState = 0;
    picked = true;
    reset();

  }

}

//interrupt
void coinInterrupt() {
  insert = true;


}


void reset () {

  myservoA.detach();
  myservoB.detach();
  myservoC.detach();
  insert = false;
  picked = false;

}


void buzzer() {
  digitalWrite(Buzz, HIGH);
  delay(50);
  digitalWrite(Buzz, LOW);
 delay(50);
   digitalWrite(Buzz, HIGH);
  delay(50);
  digitalWrite(Buzz, LOW);
  delay(50);
   digitalWrite(Buzz, HIGH);
  delay(50);
  digitalWrite(Buzz, LOW);

}
