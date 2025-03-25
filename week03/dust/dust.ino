int vo = A0;
int v_LED = 2;

float voltage = 0;
float dustDensity = 0;
float vo_value = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(v_LED, OUTPUT);
  pinMode(vo, INPUT);
}

void loop() {
  digitalWrite(v_LED, LOW);
  delayMicroseconds(280);
  vo_value = analogRead(vo);
  delayMicroseconds(40);
  digitalWrite(v_LED, HIGH);
  delayMicroseconds(9680);

  voltage = vo_value * 5.0 / 1023.0;
  dustDensity = (voltage - 0.3) / 0.005;

  Serial.print("dust = ");
  Serial.println(dustDensity);

  delay(1000);
}
