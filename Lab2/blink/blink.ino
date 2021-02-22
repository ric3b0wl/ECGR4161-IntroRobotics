

#define RED 75        // Define RED of the tri-color LED as pin 75
#define GREEN 76      // Define GREEN of the tri-color LED as pin 76
#define BLUE 77       // Define BLUE of the tri-color LED as pin 77
#define BLANK 0

int ledToggle(int color1, int color2, int color3) { 
  digitalWrite(color1, HIGH);
  digitalWrite(color2, HIGH);
  digitalWrite(color3, HIGH);   
  delay(500);               
  digitalWrite(color1, LOW);
  digitalWrite(color2, LOW); 
  digitalWrite(color3, LOW); 
  delay(500);   
}

void setup() {        // put your setup code here, to run once:
  // initialize one digital pin as outputs.
  pinMode(RED, OUTPUT);      //RED LED
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {    // put your main code here, to run repeatedly: 
  ledToggle (RED, BLANK, BLANK);
  ledToggle (BLUE, BLANK, BLANK);
  ledToggle (GREEN, BLANK, BLANK);
  ledToggle (RED, BLANK, BLUE);
  ledToggle (RED, BLANK, GREEN);
  ledToggle (BLUE, BLANK, GREEN);
  ledToggle (RED, BLUE, GREEN);
  
}
