/*
 * Simple Ultrasonic Serial
 * 
 * Connect an HC-SR04 ultrasonic distance sensor to 5V, GND, Pin 2 and Pin 3.
 * 
 * Distance values will be sent to the serial console.
 * 
 * Created by Adam Corrie on 29/07/2019
 * Licensed under the GNU General Public License v3.0
 * 
 */

#define triggerPin 2 // define triggerPin as Pin 2
#define echoPin 3 // define echoPin as Pin 3

void setup() {
  pinMode(triggerPin, OUTPUT); // configure triggerPin as an OUTPUT pin
  pinMode(echoPin, INPUT); // configure echoPin as an INPUT pin
  Serial.begin(9600); // start serial communication at 9,600 baud
}

void loop() {
  // briefly clear the triggerPin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // set the triggerPin HIGH for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  int duration = pulseIn(echoPin, HIGH); // read the echoPin
  int distance = duration * 0.034 / 2; // calculate the distance in cm
  // send a message to the serial port
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  // add a delay to throttle traffic
  delay(50);
}
