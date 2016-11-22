#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 64 

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 7
#define CLOCK_PIN 13


CRGB leds[NUM_LEDS];

int ledArray[NUM_LEDS];

void setup() {
  LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  LEDS.setBrightness(84);
}

void loop() {
    //We want an array of Hue values... zero to 255, size of number of led's
    //we will randomly assign and then sort, calling an update to led table at each step
    //Fill our hue array with random integers < 255
    for(int i=0; i<NUM_LEDS; i++){
      ledArray[i] = rand() % 255;
    }

    setHue();
    bubblesort(ledArray); 
}



void setHue(){
  for(int i = 0; i < NUM_LEDS; i++) {
    //Set led to hue in sorting array 
    leds[i] = CHSV(ledArray[i], 255, 255);
    //Show
    FastLED.show(); 
    // Give some delay
    delay(10);  
  }
}

void bubblesort(int ledArray[]){
  bool swap = 0;
  for (int i=0; i<NUM_LEDS-1; i++){
    if (ledArray[i] > ledArray[i+1]){
      swap = 1;
      int temp = ledArray[i];
      ledArray[i]=ledArray[i+1];
      ledArray[i+1]=temp;
    }
  }

  if (swap){
    bubblesort(ledArray);
  }
}



