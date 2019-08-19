#include <NewPing.h>
#include <Servo.h>
#define se 3
#define sd 2
#define trig 7
#define eco 8
Servo motorE;
Servo motorD;
NewPing sonar (trig, eco);
void setup() {
  pinMode(se, INPUT);
  pinMode(sd, INPUT);
  motorE.attach(5);
  motorD.attach(4);
  Serial.begin (9600);
}

void loop() {
  int valorE = digitalRead(se);
  int valorD = digitalRead(sd);
  int dist = sonar.ping_cm();
  Serial.print (dist);
  Serial.println (" cm");


  if (valorE == 1 && valorD == 0)//branco
  {
    frente ();
  }
  if (valorE == 0 && valorD == 1)//preto
  {
    frente ();
  }
  if (valorE == 0 && valorD == 0)
  {
    esquerda ();
  }
  if (valorE == 1 && valorD == 1)
  {
    direita ();
  }
  if (dist > 2 && dist < 10)
  {

    desvia ();

  }


}


void frente () {
  motorE.write(180) ;
  motorD.write(1);
}
void esquerda () {
  motorE.write (180);
  motorD.write (180);
}
void direita () {
  motorE.write (1);
  motorD.write (1);
}
void desvia () {
  direita ();
  delay (750);
  frente ();
  delay (1200);
  esquerda ();
  delay (750);
  frente ();
  delay (2300);
  esquerda ();
  delay (720);
  frente();


}
