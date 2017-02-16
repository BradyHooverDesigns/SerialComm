//code to establish serial communication control of an led

const int ledPin = 13;  //the button the ledpin is on, also capable of attaching an led to pin 13
int inByte = 0;   //a byte variable to store the incoming serial byte


void setup() {
  // put your setup code here, to run once:
  pinMode (ledPin, OUTPUT); //sets pin 13 as an output pin for the led triggering

  Serial.begin(9600); //sets the serial communication at 9600
  Serial.println("resetting");  //prints "resetting" to serial communication

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available() > 0) {
    inByte = Serial.read(); 
    
    //detects information in the serial monitor and writes it to the inByte variable
    
    if(inByte == 'a') { //if the available byte is "a"
      digitalWrite(ledPin, HIGH); //turn on the led pin
      Serial.println("LED - On"); //write LED - On to serial communication
    } else {
      digitalWrite(ledPin, LOW);  //otherwise turn off the led
      Serial.println("LED - Off");  //and write LED - Off to serial communication
    }
  }
}
