// defines pins numbers
const int trigPinA = 4;
const int trigPinB = 5;
const int echoPin = 6;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPinA, OUTPUT); // Sets the trigPins as Outputs
  pinMode(trigPinB, OUTPUT);
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  //Run SONAR in order, 180 deg phase shift
  runSONAR(false);
  delayMicroseconds(4287);
  runSONAR(true);
  delayMicroseconds(100);
  readSONAR();
}
void runSONAR(isRight) {
  // Clears the trigPin
  digitalWrite((isRight?trigPinB:trigPinA), LOW);
  delayMicroseconds(2);
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
