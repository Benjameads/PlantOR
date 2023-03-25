#include <SoftwareSerial.h>

// int relay = 8;
// int timer = 0;
// volatile byte relayState = LOW;
SoftwareSerial bluetooth(0,1);

char data = 0;
unsigned long timer = 0;
void setup() {
  //put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  bluetooth.println("TEST BLUETOOTH");
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);

  //pinMode(relay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0) {
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    if (data == '1') {
      digitalWrite(13, LOW);
    }
    else if (data == '2') {
      digitalWrite(12, LOW);
    }
    else if (data == '0') {
      digitalWrite(12, HIGH);
      digitalWrite(13, HIGH);
    }
  }

  //Send moisture content data
  if(timer % 10 == 0) {
    Serial.print("Soil Moisture: ");
    Serial.println(analogRead(A0));
  }
  bluetooth.println("Testeroosies");


  // digitalWrite(8,HIGH);
  // delay(5000);
  // digitalWrite(8,LOW);
  // delay(3000);

  delay(500);
  timer++;
}
