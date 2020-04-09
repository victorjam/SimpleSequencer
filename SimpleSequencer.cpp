#include "SimpleSequencer.h"

SimpleSequencer::SimpleSequencer(int8_t ns) {
  steps = new Step [ns];
  numSteps  = ns;
  currentStep = 0;
  running = false;
  for (int i=0; i<numSteps; i++ ) {
    steps[i].action = NULL;
    steps[i].duration = NULL;
  }
  onStart = NULL;
  onStop  = NULL;
}

void SimpleSequencer::setStep(uint8_t s, uint32_t t, stepAction a) {
  if ( s<numSteps ) {
    steps[s].action = a;
    steps[s].duration = t;
  }
}

void SimpleSequencer::start(uint8_t p=0) {
  if ( p<numSteps ) {
    if ( steps[p].action != NULL ) steps[p].action();
    currentStep = p;
    timer = millis();
    running = true;
    if ( onStart!=NULL ) onStart();
  }
}

void SimpleSequencer::stop() {
  currentStep = 0;
  timer = 0;
  running = false;
  if ( onStop!=NULL ) onStop();
}

void SimpleSequencer::update() {
  if ( running ) {
    if ( millis()-timer >= steps[currentStep].duration ) {
      timer = millis();
      currentStep++; if ( currentStep>=numSteps ) currentStep = 0;
      if ( steps[currentStep].action != NULL ) steps[currentStep].action();
    }
  }
}

void SimpleSequencer::setOnStart(stepAction a) {
  onStart = a;
}

void SimpleSequencer::setOnStop(stepAction a) {
  onStop = a;
}
