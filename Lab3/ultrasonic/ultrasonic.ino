#undef min
#undef max
#include <algorithm>

const int trigPin = 32;  //This is Port Pin 3.5 on the MSP432 Launchpad
const int echoPin = 33; //This is Port Pin 5.1 on the MSP432 Launchpad 

constexpr size_t SAMPLE_IDX = 5;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);      
   
  Serial.begin(9600);
  Serial.println("HC-SR04 Testing...");  
}

long get_sonar_val() {
  long samples[SAMPLE_IDX];
  long centimeters;
  
  for (int i = 0; i < SAMPLE_IDX; ++i) {
    digitalWrite(trigPin, LOW);            // send low to get a clean pulse
    delayMicroseconds(5);                  // let it settle
    digitalWrite(trigPin, HIGH);           // send high to trigger device
    delayMicroseconds(10);                 // let it settle

    samples[i] = pulseIn(echoPin, HIGH);
      
    centimeters = samples[i] / 58;  
  
    Serial.print("Distance = ");
    Serial.print("       ");
    Serial.print(centimeters);
    Serial.println(" centimeters");
    
    delay(1000);
  }

  std::sort(samples, samples + SAMPLE_IDX);

  if (SAMPLE_IDX % 2 == 1) {
    return samples[(SAMPLE_IDX / 2) + 1];
  } else {
    return ( samples[(SAMPLE_IDX / 2) + 1] + samples[(SAMPLE_IDX / 2) + 1] ) / 2;
  }
}

void loop() {
  long pulseLength; 
  long inches;
  long centimeters; 
  
  pulseLength = get_sonar_val();
  centimeters = pulseLength / 58; 
                                  
  Serial.print("Median distance = ");
  Serial.print("       ");
  Serial.print(centimeters);
  Serial.println(" centimeters");
  delay(5000);
}
