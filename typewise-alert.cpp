#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double f_value, double f_lowerLimit, double f_upperLimit) {
  if(f_value < f_lowerLimit) {
    return TOO_LOW;
  }
  if(f_value > f_upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

BreachType classifyTemperatureBreach(
    CoolingType f_coolingType, double f_temperatureInC) {
  int l_lowerLimit = 0;
  int l_upperLimit = 40;
  
  if(PASSIVE_COOLING == f_coolingType)
  {
    l_upperLimit = 35;
  }
  if(HI_ACTIVE_COOLING == f_coolingType)
  {
    l_upperLimit = 45;
  }
  return inferBreach(f_temperatureInC, l_lowerLimit, l_upperLimit);
}

void checkAndAlert(
    AlertTarget f_alertTarget, BatteryCharacter f_batteryChar, double f_temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    f_batteryChar.coolingType, f_temperatureInC
  );

  switch(f_alertTarget) {
    case TO_CONTROLLER:
      sendToController(breachType);
      break;
    case TO_EMAIL:
      sendToEmail(breachType);
      break;
  }
}

void sendToController(BreachType f_breachType) {
  const unsigned short l_header = 0xfeed;
  printf("%x : %x\n", l_header, f_breachType);
}

void sendToEmail(BreachType f_breachType) {
  const char* l_recepient = "a.b@c.com";
  if((TOO_LOW == f_breachType) || (TOO_HIGH == f_breachType))
  {
    printf("To: %s\n", l_recepient);
    printToEmail(f_breachType);
  }
  else
  {
    // do nothing
  }
}

void printToEmail(BreachType f_breachType) {
  if(TOO_LOW == f_breachType)
  {
    printf("Hi, the temperature is too low\n");
  }
  else
  {
    printf("Hi, the temperature is too high\n");
  }
}
