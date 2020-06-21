#define CATCH_CONFIG_MAIN
#include "greeter.h"
#include "catch.hpp"

Greeter greeter("Hello");

TEST_CASE("Greeter test") {
    REQUIRE(greeter.sayHello() == "Hello");
    REQUIRE_FALSE(greeter.sayHello() == "Yikes");
}
