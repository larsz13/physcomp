//uart communication
char recUART;

void setup() {
  pinMode(3, INPUT); // set push button pin as input
  pinMode(13, OUTPUT);      // set LED pin as output
  digitalWrite(13, LOW);    // switch off LED pin
  Serial.begin(9600);       // initialize UART with baud rate of 9600 bps
}

void loop() {
  if (Serial.available()) {
    recUART = Serial.read();    // read one byte from serial buffer and save to data_rcvd

    if (recUART == '1') {     // switch LED On
      digitalWrite(13, HIGH);
    } 
    
    if (recUART == '0') {     // switch LED Off
      digitalWrite(13, LOW);
    }

  if (digitalRead(3) <= 125) {
    Serial.write('0'); 
  }else {
    Serial.write('1'); 
  }
  }   
}