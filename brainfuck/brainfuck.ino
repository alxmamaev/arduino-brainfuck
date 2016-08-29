

void BrainFuck(const char code[]){
  int codeCursor = 0;
  
  byte memory[255] = {0};
  byte memCursor;

  int stack[255] = {0};
  byte stackCursor = 0;
  
  Serial.begin(9600);
  
  while (code[codeCursor] != 0){
    switch(code[codeCursor]){
      case '>':
        memCursor++;  
        break;
        
      case '<':
        memCursor--;
        break;

      case '+':
        memory[memCursor]++;
        break;
      
      case '-':
        memory[memCursor]--;
        break;

      case '.':
        Serial.print(char(memory[memCursor]));
        break;

      case ',': 
        while(true){
          if(Serial.available() >0){
            memory[memCursor] = Serial.read();
            break;
          }
        }
        break;
      case '[':
        if(memory[memCursor]){
          stackCursor++;
          stack[stackCursor] = codeCursor;
        }
        else{
          while(code[codeCursor] != ']'){
            codeCursor++;
          }
        }
        break;

      case ']':
        if(memory[memCursor])
          codeCursor = stack[stackCursor];
        else
          stackCursor--;
        break;
    }
    
    codeCursor++;
  }  
}

void setup() {
}

void loop() {
}
