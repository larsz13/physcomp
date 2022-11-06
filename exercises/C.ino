#define MOTOR_PIN_A 5
#define MOTOR_PIN_B 6

#define inputBut 8
int state = 1;

void setup() 
{
  Serial.begin(9600);
  pinMode(MOTOR_PIN_A, OUTPUT);
  pinMode(MOTOR_PIN_B, OUTPUT);

  pinMode(inputBut,INPUT_PULLUP);
}
void loop() 
{
  Serial.println(state);
  // CHANGE ON BUTTON CLICK
  int buttonVal = digitalRead(inputBut);
  if(buttonVal==0){
    if(state==0){
      state=1;
    }else if(state==1){
      state=0;
      }
      
      delay(500);
    }

  if(state==0){
    digitalWrite(MOTOR_PIN_A, HIGH);
    digitalWrite(MOTOR_PIN_B, LOW);
  }else if(state==1){
    digitalWrite(MOTOR_PIN_A, LOW);
    digitalWrite(MOTOR_PIN_B, HIGH);
  }
}
