#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
  REQUIRE(inferBreach(30, 10, 20) == TOO_HIGH);
}

TEST_CASE("classifyTemperatureBreach_function") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 40) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 50) == TOO_HIGH);
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 42) == TOO_HIGH);
}

TEST_CASE("sendToController_function") {
  sendToController(TOO_LOW);
}

TEST_CASE("sendToEmail_function") {
  sendToEmail(TOO_LOW);
  sendToEmail(TOO_HIGH);
  sendToEmail(NORMAL);
}

// TEST_CASE("checkAndAlert_function") {
//   BatteryCharacter test_obj{PASSIVE_COOLING,0};
//   checkAndAlert(TO_EMAIL, test_obj, 0);
//   BatteryCharacter test_obj1{MED_ACTIVE_COOLING,0};
//   checkAndAlert(TO_EMAIL, test_obj1, 45);
// }

