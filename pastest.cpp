// defines pins numbers
const int trigPinA = 4;
const int trigPinB = 5;
const int echoPin = 6;
// defines variables
long duration;
int distance;
// timing vars
unsigned long starttime;
unsigned long endtime;
void setup() {
  pinMode(trigPinA, OUTPUT); // Sets the trigPins as Outputs
  pinMode(trigPinB, OUTPUT);
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  //Run SONAR in order, 45 degs
  runSONAR(false);
  endtime = micros(); //save end time
  delayMicroseconds(3945-(endtime-starttime)); //The phase shift for 45 degs, account for delay 
  runSONAR(true);
  delayMicroseconds(50); //Allow the signal to propogate before measurement
  readSONAR();
  //Delay for good measure
  delay(500);
}
void runSONAR(boolean isRight) {
  // Clears the trigPin
  digitalWrite((isRight?trigPinB:trigPinA), LOW);
  delayMicroseconds(2);
  starttime = micros(); //Save the start time
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite((isRight?trigPinB:trigPinA), HIGH);
  delayMicroseconds(10);
  digitalWrite((isRight?trigPinB:trigPinA), LOW);
}
void readSONAR() {
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}


