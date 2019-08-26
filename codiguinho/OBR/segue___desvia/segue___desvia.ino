//teste git
#include <NewPing.h>
#include <Servo.h>
#define se 3
#define sd 2
#define triglateral 7
#define ecolateral 8
#define trig 10
#define eco 11
Servo motorE;
Servo motorD;
NewPing sonarlateral(triglateral, ecolateral);
NewPing sonar(trig, eco);
int distlateral;
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
  int distlateral = sonarlateral.ping_cm();
  int dist = sonar.ping_cm();

  Serial.print (distlateral);
  Serial.println (" cm");
  Serial.print("        ");

  Serial.print(dist);
  Serial.println(" cm2");
  delay(500);

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

  direita();
  delay(750);

  if (distlateral > 1 && distlateral < 6 ) {
    frente();
  } else {
    esquerda();
    delay(750);
  }

  if (distlateral > 1 && distlateral < 6 ) {
    frente();
  } else {
    esquerda();
    delay(750);
  }

}
