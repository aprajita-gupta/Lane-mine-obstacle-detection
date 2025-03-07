int motor1 = 5;
int motor2 = 4;
int motor3 = 3;
int motor4 = 2;
int ENA = 9;
int ENB = 6;

int trigPin = A0;    // TRIG pin
int echoPin = A1;    // ECHO pin

#define LEFT_SEN A2
#define RIGHT_SEN A3

float duration_us, distance_cm;

void setup() 
{
  Serial.begin(9600);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);  
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(LEFT_SEN, INPUT); 
  pinMode(RIGHT_SEN,INPUT); 
  analogWrite(ENA, 150); 
  analogWrite(ENB, 150); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
}

void loop() 
{
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration_us = pulseIn(echoPin, HIGH);

  distance_cm = 0.017 * duration_us;

  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  int right_sen = digitalRead(A2);
  int lef_sen  = digitalRead(A3);
  Serial.println("left sensor value = ");
  Serial.print(lef_sen);
  Serial.println("\n");
  Serial.println("right sensor value = ");
  Serial.print(right_sen);
  Serial.println("\n");

  if(distance_cm < 25)
  {
    Stop(); 
  }
  else
  {
    if(right_sen==0  && lef_sen==0) 
    {
      forward();
    }

    else if(right_sen==0  && lef_sen==1) 
    {
      right();
    }

    else if(right_sen==1  && lef_sen==0) 
    {
      left(); 
    }

    else if(right_sen==1  && lef_sen==1) 
    {
      Stop(); 
    }
  }
}

void backward()
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
  analogWrite(ENA, 250); 
  analogWrite(ENB, 250); 
}

void forward()
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, 80);
  digitalWrite(motor3, 80);
  digitalWrite(motor4, LOW);
  analogWrite(ENA, 250); 
  analogWrite(ENB, 250); 
}

void right()
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, 80);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
  analogWrite(ENA, 250); 
  analogWrite(ENB, 250); 
}

void left()
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, 80);
  digitalWrite(motor4, LOW);
  analogWrite(ENA, 250); 
  analogWrite(ENB, 250); 
}

void Stop()
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
}


