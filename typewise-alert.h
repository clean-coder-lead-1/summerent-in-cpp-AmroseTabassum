#pragma once

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH
} BreachType;

BreachType inferBreach(double f_value, double f_lowerLimit, double f_upperLimit);
BreachType classifyTemperatureBreach(CoolingType f_coolingType, double f_temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget f_alertTarget, BatteryCharacter f_batteryChar, double f_temperatureInC);

void sendToController(BreachType f_breachType);
void sendToEmail(BreachType f_breachType);
void printToEmail(BreachType f_breachType);
