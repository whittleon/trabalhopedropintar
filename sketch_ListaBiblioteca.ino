#include <Led.h>

int led1 = 10;
int led2 = 11;
int led3 = 12;

String command = "";
int x,y;

void setup() {
  setLed(led1);
  setLed(led2);
  setLed(led3);

  Serial.begin(9600);
}

void loop() {
  Serial.print("Led " + led1 +" :" + isAceso(led1));
  Serial.print("Led " + led2 +" :" + isAceso(led2));
  Serial.print("Led " + led3 +" :" + isAceso(led3));
  
  Serial.print("Led " + led1 +" PWM? " + isPwm(led1));
  Serial.print("Led " + led2 +" PWM? " + isPwm(led2));
  Serial.print("Led " + led3 +" PWM? " + isPwm(led3));
  
}

void executar(String operacao, int porta, int brilho) {

  if(operacao.equals("ACENDER")){
    if(porta==-1){
      acender(led1);
      acender(led2);
      acender(led3);
      }else{
      if (brilho > -1) {
         acender(porta, brilho); 
      } else { 
         acender(porta);
      }
    } 
  }
    
    if(operacao.equals("APAGAR")){
      if(porta==-1){;
      apagar(led1);
      apagar(led2);
      apagar(led3);
      }else{
      apagar(porta);
        }
    }
    if(operacao.equals("PISCAR")){
      piscar(porta,x,y);
    }
}
 


void serialEvent(){
  if (Serial.available()){
     command=Serial.readString();
     // String valores[] = command.split(";"); // ACENDER;13
     String operacao = command.substring(0, command.indexOf(";"));

     int porta=-1;
     int brilho=-1;

     if (command.indexOf("?") != -1) {
        porta = command.substring(command.indexOf(";")+1 ,command.indexOf("?")).toInt();
        brilho = command.substring(command.indexOf("?")+1).toInt();
     } else if (command.indexOf(";") != -1) {
        porta = command.substring(command.indexOf(";")+1).toInt();
        brilho = -1;
     }

     executar(operacao, porta, brilho);
     x = Serial.readString().toInt;
     y = Serial.readString().toInt;
  }
  
}
