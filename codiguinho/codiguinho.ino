#include <Servo.h>
Servo braco;
Servo cotovelo;
Servo mao;
#define sensorE 8
#define sensorD  9
#include <NewPing.h>
#define ecco 10
#define trigger 11
NewPing sonar (trigger, ecco);
Servo motorE;
Servo motorD;



int x = 90;
int y = 90;
int z = 90;
char comando = 'm';
void setup()
{
  braco.attach(4);
  cotovelo.attach(2);
  mao.attach(3);
  Serial.begin(9600);


  motorE.attach (5);
  motorD.attach(6);
  Serial.begin (9600);
  pinMode (sensorD, INPUT);
  pinMode (sensorE, INPUT);
}

void loop()
{
  // apenas responde quando dados são recebidos:
  // quando tem algo disponivel
  if (Serial.available() > 0) {

    // lê do buffer o dado recebido:
    // le o que esta disponivel
    comando = Serial.read();




    if (comando == 'M') {
      Serial.print("mao + " );
      x = x + 5;
      mao.write(x);
      Serial.println(x);
    }


    if (comando == 'm') {
      Serial.print("mao -");
      x = x - 5;
      mao.write(x);
      Serial.println(x);
    }


    if (comando == 'C') {
      Serial.print("cotovelo + ");
      y = y + 5;
      cotovelo.write(y);
      Serial.println(y);
    }


    if (comando == 'c') {
      Serial.print("cotovelo -");
      y = y - 5;
      cotovelo.write(y);
      Serial.println(y);
    }


    if (comando == 'B') {
      Serial.print("braco +");
      z = z + 5;
      braco.write(z);
      Serial.println(z);
    }


    if (comando == 'b') {
      Serial.print("braco -");
      z = z - 5;
      braco.write(z);
      Serial.println(z);
    }
  }

  int valorE = digitalRead (sensorE);
  int valorD = digitalRead (sensorD);
  int dist = sonar.ping_cm();

  if (valorE == 0 && valorD == 0 )
  {
    frente ();
  }
  if (valorE == 1 && valorD == 1)
  {
    frente ();
  }
  if (valorE == 0 && valorD == 1)
  {
    direita ();
  }
  if (valorE == 1 && valorD == 0)
  {
    esquerda ();
  }
  if (dist < 10 && dist > 0)
{
    desvia ();
  }
}

void frente () {
  motorE.write(180) ;
  motorD.write(1);
}
void esquerda () {
  motorE.write (1);
  motorD.write (1);
}
void direita () {
  motorE.write (180);
  motorD.write (180);
}
void desvia () {
  direita ();
  delay (680);
  frente ();
  delay (1500);
  esquerda ();
  delay (680);
  frente ();
  delay (3000);
  esquerda ();
  delay (680);
  frente();
  delay (1500);
  direita ();
  delay (680);
}
