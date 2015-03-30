

/* Board Definitions */
#define LR2 16
#define LY2 17
#define LG2 4
#define LG1 5
#define LY1 6
#define LR1 7
#define POT 0
#define IN  1
#define SW1 2
#define SW2 3

/* Program definitions */
#define T_D 200

void led_test();
void set_scala();
void set_tone();
extern uint8_t escale_select;
extern uint8_t escale_tone;

void UI_Init(){
 pinMode(LR2,OUTPUT); 
 pinMode(LR1,OUTPUT);
 pinMode(LY2,OUTPUT);
 pinMode(LY1,OUTPUT);
 pinMode(LG2,OUTPUT);
 pinMode(LG1,OUTPUT);
 pinMode(SW2,INPUT_PULLUP);
 pinMode(SW1,INPUT_PULLUP);
 led_test();
 attachInterrupt(1,set_scala,RISING);
 attachInterrupt(0,set_tone,RISING);
 
}

void led_test(){
 digitalWrite(LR1,LOW);
 digitalWrite(LR2,HIGH);
 digitalWrite(LY1,LOW);
 digitalWrite(LY2,LOW);
 digitalWrite(LG1,LOW);
 digitalWrite(LG2,LOW);
 delay(T_D);
 digitalWrite(LY2,HIGH);
 delay(T_D);
 digitalWrite(LG2,HIGH);
 delay(T_D);
 digitalWrite(LR1,HIGH);
 delay(T_D);
 digitalWrite(LY1,HIGH);
 delay(T_D);
 digitalWrite(LG1,HIGH);
 delay(T_D);
 digitalWrite(LR2,LOW);
 delay(T_D);
 digitalWrite(LY2,LOW);
 delay(T_D);
 digitalWrite(LG2,LOW);
 delay(T_D);
 digitalWrite(LR1,LOW);
 delay(T_D);
 digitalWrite(LY1,LOW);
 delay(T_D);
 digitalWrite(LG1,LOW);
 delay(T_D);
 }
 
 void set_scala(){
  noInterrupts();
  digitalWrite(LR2,LOW);
  digitalWrite(LY2,LOW);
  digitalWrite(LG2,LOW);
  escale_select++;
  if (escale_select>4) escale_select=0;
    
  switch (escale_select){
   case 1:
     digitalWrite(LR2,HIGH);
     break;
   case 2:
     digitalWrite(LY2,HIGH);
     break;
   case 3:
     digitalWrite(LG2,HIGH);
     break;
  }
  interrupts();
 }
 
  void set_tone(){
  noInterrupts();
  digitalWrite(LR1,LOW);
  digitalWrite(LY1,LOW);
  digitalWrite(LG1,LOW);
  escale_tone++;
  if (escale_tone>7) escale_tone=0;
    
  switch (escale_tone){
   case 1:
     digitalWrite(LR1,HIGH);
     break;
   case 2:
     digitalWrite(LY1,HIGH);
     break;
   case 3:
     digitalWrite(LR1,HIGH);
     digitalWrite(LY1,HIGH);
     break;
   case 4:
     digitalWrite(LG1,HIGH);
     break;
   case 5:
     digitalWrite(LR1,HIGH);
     digitalWrite(LG1,HIGH);
     break;
   case 6:
     digitalWrite(LY1,HIGH);
     digitalWrite(LG1,HIGH);
     break;    
   case 7:
     digitalWrite(LR1,HIGH);
     digitalWrite(LY1,HIGH);
     digitalWrite(LG1,HIGH);
     break;        
  }
  interrupts();
 }
