#include <Led.h>

String command = "";
int x,y;

Led led1(10);
Led led2(11);
Led led3(12);

void setup() {
  led1.setLed(10);
  led2.setLed(11);
  led3.setLed(12);

  Serial.begin(9600);
}

void loop() {
  Serial.print("Led ");
  Serial.print(led1.getLed());
  Serial.print(led1.isAceso());

  Serial.println();
  
  Serial.print("Led ");
  Serial.print(led2.getLed());
  Serial.print(led2.isAceso());

  Serial.println();
  
  Serial.print("Led ");
  Serial.print(led3.getLed());
  Serial.print(led3.isAceso());

  Serial.println();
  
}

void executar(String operacao, int porta, int brilho) {

  if(operacao.equals("ACENDER")){
    if(porta==-1){
      led1.acender(led1);
      led2.acender(led2);
      led3.acender(led3);
      }else{
      if (brilho > -1) {
         led1.acender(porta, brilho); 
      } else { 
         led1.acender(porta);
      }
    } 
  }
    
    if(operacao.equals("APAGAR")){
      if(porta==-1){;
      led1.apagar(led1);
      led2.apagar(led2);
      led3.apagar(led3);
      }else{
		led1.apagar(porta);
        }
    }
    if(operacao.equals("PISCAR")){
      led1.piscar(porta,x,y);
	  led2.piscar(porta,x,y);
	  led3.piscar(porta,x,y);
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
        led1.porta = command.substring(command.indexOf(";")+1 ,command.indexOf("?")).toInt();
        led2.brilho = command.substring(command.indexOf("?")+1).toInt();
     } else if (command.indexOf(";") != -1) {
        led1.porta = command.substring(command.indexOf(";")+1).toInt();
        led2.brilho = -1;
     }

     executar(operacao, porta, brilho);
     x = Serial.readString().toInt;
     y = Serial.readString().toInt;
  }
  
}
