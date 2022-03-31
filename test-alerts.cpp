#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("sendToController_function") {
  sendToController(TOO_LOW);
}

TEST_CASE("checkAndAlert_function") {
  BatteryCharacter test_obj{PASSIVE_COOLING,0};
  checkAndAlert(0, test_obj, 0);
}
