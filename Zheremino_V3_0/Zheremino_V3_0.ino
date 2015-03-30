



#include <MIDI.h>


#include "UI.h"
#include "scalas.h"

#define Nmedidas  15	// Define el número de medidas del sensor que utiliza para realizar la media de la medida
#define notaBaja  48	// Define la nota mas grave que debe ser tocada
#define MIDI_CH    1    // MIDI channel to send data
#define IN_SENSOR  5    // Analog input to read Sensor data 

MIDI_CREATE_DEFAULT_INSTANCE();

/* Variable that point what's the state  */
uint8_t state=0;
int note, f_note;
uint8_t velocity=100; 

uint8_t escale_select;
uint8_t escale_tone;


void setup() {
 UI_Init(); 
 MIDI.begin();   
}

void loop() {

velocity=(analogRead(POT)>>3);
note=ReadNote();


/* If is in initial state (No sound)... */
if(!state){
  if(note>=0){
    MIDI.sendNoteOn(note+notaBaja+escale_tone,velocity+scales[escale_select][f_note],MIDI_CH);
    f_note=note;
    state=1;
  }
}

/* else state is playing something */
else {
  if (note>=0){
    if(note!=f_note){
      MIDI.sendNoteOff(f_note+notaBaja+escale_tone+scales[escale_select][f_note],0,MIDI_CH);
      MIDI.sendNoteOn(note+notaBaja+escale_tone+scales[escale_select][note],velocity,MIDI_CH);
      f_note=note;
      state=1;
    }
  }
  else {
    MIDI.sendNoteOff(f_note+notaBaja+escale_tone+scales[escale_select][f_note],0,MIDI_CH);
    state=0;
  }
 }
}




int ReadNote(){
/* Reads analog input and maps note and checks that is a right one */
 int     sum;
 int     nota;
 
// Lee el sensor y hace la media (avg) de Nmedidas
sum=0;
for (int i=0; i<Nmedidas; i++){
   sum +=analogRead(IN_SENSOR);
   delayMicroseconds(10);
   }  
   
nota=(int)map( sum / Nmedidas,80,350,0, 16); 

if ((nota < 0) || (nota > 16)) return -1;
else return nota;
}
