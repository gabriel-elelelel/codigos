// bulir en


#include <Servo.h>
Servo braco;
Servo cotovelo;
Servo mao;
#include <NewPing.h>
#define ecco 10
#define trigger 11
NewPing sonar (trigger, ecco);
int x = 80;
int y = 105;
int z = 35;
char comando = 'm';
void setup()
{
  braco.attach(2);
  braco.write(x);
  cotovelo.attach(3);
  cotovelo.write(y);
  mao.attach(4);
  mao.write(z);
  Serial.begin(9600);
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

  int dist = sonar.ping_cm();


}
