int led_verde = 8;
int led_amar = 9;
int led_verme = 10;
int button1 = 2;
int button2 = 3;
int button3 = 4;
int buz = 13;
int qtd=0;
int senha[] = {0,0,0};
#define DEBUG
 
void setup(){
  //pinMode(led, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_amar, OUTPUT);
  pinMode(led_verme, OUTPUT);
  pinMode(buz, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  Serial.begin(9600);
}
 
void loop(){
  
  int pass[] = {3,3,3};
  digitalWrite(led_verde,LOW);
  digitalWrite(led_amar, LOW);
  digitalWrite(led_verme, LOW);
  if(digitalRead(button1) == LOW){
     digitalWrite(buz, HIGH);
     digitalWrite(led_amar,HIGH);
     delay(100);
     digitalWrite(buz, LOW);
     digitalWrite(led_amar,LOW);
     senha[qtd] = 1;
     
     
     qtd=qtd+1;
     delay(500);
   
  }

  if(digitalRead(button2) == LOW){
     digitalWrite(buz, HIGH);
     digitalWrite(led_amar,HIGH);
     delay(100);
     digitalWrite(buz, LOW);
     digitalWrite(led_amar,LOW);
     senha[qtd] = 2;
     
     qtd++;
     delay(500);
     
  }

  if(digitalRead(button3) == LOW){
     digitalWrite(buz, HIGH);
     digitalWrite(led_amar,HIGH);
     delay(100);
     digitalWrite(buz, LOW);
     digitalWrite(led_amar,LOW);
     senha[qtd] = 3;
     
     qtd++;
     delay(500);
     
  
  }
 
  if (qtd==3 && senha[0] == pass[0] && senha[1] == pass[1] && senha[2] == pass[2]){
    Serial.println("SENHA DIGITADA:");
    for(int i=0;i<3;i++){
      Serial.print(senha[i]);
    }
    Serial.println(" ");
    Serial.println("ENTRADA LIBERADA");
    Serial.println("-----------------");
    digitalWrite(led_verde, HIGH);
    digitalWrite(buz, HIGH);
    delay(100);
    digitalWrite(led_verde, LOW);
    digitalWrite(buz, LOW);
    delay(100);
    digitalWrite(led_verde, HIGH);
    digitalWrite(buz, HIGH);
    delay(100);
    digitalWrite(led_verde, LOW);
    digitalWrite(buz, LOW);
    delay(100);
    digitalWrite(led_verde, HIGH);
    digitalWrite(buz, HIGH);
    delay(100);
    digitalWrite(led_verde, LOW);
    digitalWrite(buz, LOW);
    qtd=0;
    for(int i=0;i<3;i++){
      senha[i]=0;
    }
  } 
  if (qtd==3 && senha[0] != pass[0] or qtd==3 && senha[1] != pass[1] or qtd==3 && senha[2] != pass[2]) {

    Serial.println("SENHA DIGITADA:");
    for(int i=0;i<3;i++){
      Serial.print(senha[i]);
    }
    Serial.println(" ");
    Serial.println("SENHA INCORRETA");
    Serial.println("-----------------");

    digitalWrite(led_verme, HIGH);
    digitalWrite(buz, HIGH);
    delay(500);
    digitalWrite(led_verme, LOW);
    digitalWrite(buz, LOW);

    for(int i=0;i<3;i++){
      senha[i]=0;
    }
   
    qtd=0;
  }

    
}
