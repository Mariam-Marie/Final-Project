int switch_bell = 12;
int switch_state_bell = 0;

int switch_gate = 13;
int switch_state_gate = 0;
int door = 0;

int motor_speed = 0;
#define EN 10
#define IN1 8
#define IN2 9

int buzzer = 11;

void setup() {
  // put your setup code here, to run once:
pinMode (switch_bell, INPUT);
pinMode (switch_gate, INPUT);

pinMode (buzzer, OUTPUT);

pinMode (EN, OUTPUT);
pinMode (IN1, OUTPUT);
pinMode (IN2, OUTPUT);

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

switch_state_bell = digitalRead(switch_bell);

if (switch_state_bell == HIGH) {
  analogWrite(buzzer, HIGH);
} else {
  analogWrite(buzzer, LOW);
}


switch_state_gate = digitalRead(switch_gate);


if (switch_state_gate == HIGH && switch_state_bell == HIGH && door==0){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN, 125);
  delay(3000);
  analogWrite(EN, 0);
  door =1;
}
  
 if (switch_state_gate == LOW && switch_state_bell == HIGH && door==1){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(EN, 125);
  delay(3000);
  analogWrite(EN, 0);
  door=0;
  }
}
