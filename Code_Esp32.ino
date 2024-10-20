/*
 * Code crafted with care by Chirrenthen P
 * 
 * 🛠️ Connect all components precisely as per the provided schematic diagram.
 *
 * 🚀 Upload this code to your ESP32 and get ready for a smooth test run.
 *
 * ✅ Once everything's in place, test your setup, watch the magic unfold, and enjoy the result!
 * 
 * For detailed guidance and project breakdown, check out:
 * 📄 IoT Hub post: https://chirrenthen13.wixsite.com/iothub/post/interfacing-ultrasonic-sensor-hc-sr04-with-esp32
 *
 * 💻 Source Code on GitHub: https://github.com/Chirrenthen/Ultrasonic-Sensor
 * 
 * 🎉 Support my work and explore exclusive content on Patreon: https://www.patreon.com/Chirrenthen
 */

// Define pins for the ultrasonic sensor
const int trigPin = 26;  // Trigger pin for sending signal
const int echoPin = 27; // Echo pin for receiving signal
long duration;          // Variable to store the time taken for the echo to return
int distance;         // Variable to store the calculated distance in cm

void setup() {
// Initialize serial communication at 115200 baud rate
Serial.begin(115200);

// Project Title
Serial.print("Interfacing HC-SR04 with ESP32");
Serial.print("Ensure to connect all components precisely as per the provided schematic diagram");
Serial.print("---------------------------------------------------------------------------------");
Serial.print("Distance values from Ultrasonic Sensor:");

// Define the ultrasonic sensor pins as output and input
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}
void loop() {
// Ensure the trigger pin is set to low for 2 microseconds before sending the pulse
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
  
// Set the trigger pin high for 10 microseconds to send out an ultrasonic pulse
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
  
// Measure the time taken for the echo to return to the echo pin
duration = pulseIn(echoPin, HIGH);
  
// Calculate the distance in cm (speed of sound = 343 m/s or 29.1 µs/cm)
distance = duration * 0.034 / 2;
  
// Print the distance to the serial monitor
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
  
// Small delay between readings
delay(500);

}