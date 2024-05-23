/*
Physics & Electronics
Website : www.physicsandelectronics.com

Project : Interfacing Ultrasonic Sensor (HC-SR04) with Arduino

YouTube -> Physics And Electronics - Saurabh Salvi
Instagram -> @physics_and_electronics

*/

int Trig = 7;
int Echo = 6;
int Led = 12;

//time and distance values can be in decimals
float time;
float distance;

void setup()
{
  pinMode(Trig, OUTPUT); //transmitter emits, hence OUTPUT
  pinMode(Echo, INPUT);  //receiver receives, hence INPUT
  pinMode(Led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(Trig, LOW);// Clearing purpose -Removing any existing signal
  delayMicroseconds(10);
  
  //Sending a Trigger
  digitalWrite(Trig, HIGH); //Turned On the Trig pin
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);  //And quickly turned it OFF
  delayMicroseconds(10);
  
  //Storing the time value noted by Echo Pin
  time = pulseIn(Echo, HIGH);
  
  //Calculating the distance (sensor to obstacle)
  distance = (time * 0.034)/2 ;
  
  Serial.println(distance);
  
  //Conditions for controlling LED based on the proximity of obstacle
  if(distance <= 100){  
  		digitalWrite(Led, HIGH);//if distance<=100cm, then LED turns ON
    	
  } 
  else{
  		digitalWrite(Led, LOW); //or else, LED remains OFF
  }
}
