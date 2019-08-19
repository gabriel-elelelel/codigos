#include<NewPing.h>
#define eco 7
#define trigo 8
NewPing sonar(trigo,eco);

void setup(){
  Serial.begin(9600);
  
}
void loop(){
  int dist = sonar.ping_cm();
  Serial.print(dist);
  Serial.println("cm");
delay(200);
}
