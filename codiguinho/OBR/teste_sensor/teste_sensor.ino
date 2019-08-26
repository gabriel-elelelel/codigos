#define analogico A4
#define digital 7

void setup() {
  Serial.begin(9600);
  pinMode(digital, INPUT);
  pinMode(analogico, INPUT);

}


void loop() {
  int valorD = digitalRead(digital);
  int valorA = analogRead(analogico);
  Serial.print(valorA);
  Serial.print("      ");
  Serial.println(valorD);
delay(400);
}


//impossível 
