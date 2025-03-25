// C++ code
//

#define TRIG 12
#define ECHO 11

#define led_r 13
#define led_g 9

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  long duration,distance;

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW); 

  duration = pulseIn(ECHO, HIGH);

  distance = duration * 17 / 1000;

  Serial.println(duration);
  Serial.println("Distance : ");
  Serial.print(distance);
  Serial.println(" Cm");
  
  digitalWrite(led_r, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(led_g, HIGH);

  digitalWrite(led_r, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(led_g, LOW);
}
