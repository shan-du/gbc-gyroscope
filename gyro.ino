#define output1A 3
#define output1B 4
#define output2A 5
#define output2B 6
#define output3A 7
#define output3B 8
#define numberOfEncoders 3

int counter[] = {0, 0, 0};
int outputACurrentState[numberOfEncoders];
int outputAPreviousState[numberOfEncoders];

int outputA[] = {output1A, output2A, output3A};
int outputB[] = {output1B, output2B, output3B};
int basePadding = 1000;

void setup() { 
  pinMode (output1A,INPUT);
  pinMode (output1B,INPUT);
  pinMode (output2A,INPUT);
  pinMode (output2B,INPUT);
  pinMode (output3A,INPUT);
  pinMode (output3B,INPUT);
  
  Serial.begin (9600);
  // Reads the initial state of all the outputs
  for (int i=0; i<numberOfEncoders; i++) {
    outputAPreviousState[i] = digitalRead(outputA[i]);
  }
}

void encoderLoop(int index) {
  // Reads the "current" state of all the outputs
  outputACurrentState[index] = digitalRead(outputA[index]);
  int c = 0;
   
  // If the previous and the current state of the output are different, that means a Pulse has occured
  if (outputACurrentState[index] != outputAPreviousState[index]){     
    // If the post-output state is different to the pre-output state, that means the encoder is rotating clockwise
    if (digitalRead(outputB[index]) != outputACurrentState[index]) {
      c = 1;
    }

    // pad encoder output with big number to identify each encoder
    // e.g encoder 1: 1000/1001, encoder 2: 2000/2001, encoder 3: 3000/3001
    int paddedOutput = basePadding * (index + 1) + c;
    Serial.println(paddedOutput);
  
   // Compose the message for printing
   // pad encoder output with big number to identify each encoder
   // e.g encoder 1: 5000, encoder 2: 10000, encoder 3: 15000
   // int paddedOutput = basePadding * (index + 1) + counter[index];
   // Serial.println(paddedOutput);
  }
  
  // Updates the previous state of all the outputs with the current state
  outputAPreviousState[index] = outputACurrentState[index];
}

void loop() { 
  for (int i=0; i<numberOfEncoders; i++) {
    encoderLoop(i);
  }
}
