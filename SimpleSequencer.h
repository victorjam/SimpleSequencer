#ifndef _SimpleSequencer_h_
#define _SimpleSequencer_h_

#include <Arduino.h>

typedef void (*stepAction)();

typedef struct {
  stepAction action;
  uint32_t duration;
} Step;


class SimpleSequencer
{
  private:
    Step *steps;
    int8_t numSteps;
    int8_t currentStep;
    bool   running;
    uint32_t timer;

    stepAction onStart;
    stepAction onStop;
  public:
    SimpleSequencer(int8_t ns);
    void setStep(uint8_t s, uint32_t t, stepAction a);
    void update();
    void start(uint8_t p=0);
    void stop();
    void setOnStart(stepAction a);
    void setOnStop(stepAction a);
    bool isRunning() { return running; }
};

#endif