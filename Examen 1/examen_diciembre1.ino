#define PIN_LED_R 3    
#define PIN_LED_G 6    
#define PIN_LED_B 5    
#define PIN_LDR A0     
#define PIN_BUZZER 8   

void setup() {
  pinMode(PIN_LED_R, OUTPUT);  
  pinMode(PIN_LED_G, OUTPUT);  
  pinMode(PIN_LED_B, OUTPUT);  
  pinMode(PIN_BUZZER, OUTPUT); 
  Serial.begin(9600);          
}

void loop() {
  int LDR_Value = analogRead(PIN_LDR);
  int lightPercentage = map(LDR_Value, 0, 30, 0, 100);
  
  Serial.print("Luz: ");
  Serial.print(lightPercentage);
  Serial.println("%");

  if (lightPercentage < 40) {
    analogWrite(PIN_LED_R, 0);    
    analogWrite(PIN_LED_G, 255);  
    analogWrite(PIN_LED_B, 0);    
    noTone(PIN_BUZZER);           
  } 
  else if (lightPercentage >= 40 && lightPercentage < 60) {
    analogWrite(PIN_LED_R, 255);  
    analogWrite(PIN_LED_G, 0);    
    analogWrite(PIN_LED_B, 255);  
    noTone(PIN_BUZZER);           
  } 
  else if (lightPercentage >= 60) {
    analogWrite(PIN_LED_R, 255);  
    analogWrite(PIN_LED_G, 0);    
    analogWrite(PIN_LED_B, 0);    
    tone(PIN_BUZZER, 1000);       
    delay(500);                   
    noTone(PIN_BUZZER);           
    delay(500);                   
  }
  
  delay(500);  
}
