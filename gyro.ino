 #define outputA 3
 #define outputB 4
 #define outputC 5
 #define outputD 6
 #define outputE 7
 #define outputF 8
 
 int counter1 = 0; 
 int counter2 = 0;
 int counter3 = 0;
 
 int aState1;
 int aState2;
 int aState3;
 
 int aLastState1;
 int aLastState2;
 int aLastState3;
 
 void setup() { 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode (outputC,INPUT);
   pinMode (outputD,INPUT);
   pinMode (outputE,INPUT);
   pinMode (outputF,INPUT);
   
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState1 = digitalRead(outputA);
   aLastState2 = digitalRead(outputC);
   aLastState3 = digitalRead(outputE);
 }

 
 void loop() { 
   aState1 = digitalRead(outputA); // Reads the "current" state of the outputA
   aState2 = digitalRead(outputC); // Reads the "current" state of the outputC
   aState3 = digitalRead(outputE); // Reads the "current" state of the outputE
   
   
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState1 != aLastState1){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState1) { 
       counter1 ++;
     } else {
       counter1 --;
     }
     
     Serial.print("Encoder 111: ");
     Serial.println(counter1);
   } 

   // If the previous and the current state of the outputC are different, that means a Pulse has occured
   if (aState2 != aLastState2){
     // If the outputD state is different to the outputC state, that means the encoder is rotating clockwise
     if (digitalRead(outputD) != aState2) { 
       counter2 ++;
     } else {
       counter2 --;
     }
     
     Serial.print("Encoder 222: ");
     Serial.println(counter2);
   }

   
   // If the previous and the current state of the outputE are different, that means a Pulse has occured
   if (aState3 != aLastState3){
     // If the outputD state is different to the outputE state, that means the encoder is rotating clockwise
     if (digitalRead(outputF) != aState3) { 
       counter3 ++;
     } else {
       counter3 --;
     }
     
     Serial.print("Encoder 333: ");
     Serial.println(counter3);
   } 
   
   aLastState1 = aState1; // Updates the previous state of the outputA with the current state
   aLastState2 = aState2; // Updates the previous state of the outputC with the current state
   aLastState3 = aState3; // Updates the previous state of the outputE with the current state
 }
