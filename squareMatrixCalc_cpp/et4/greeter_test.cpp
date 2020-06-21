#define CATCH_CONFIG_MAIN
#include "greeter.h"
#include "catch.hpp"

Greeter greeter("Hello");

TEST_CASE("Greeter test") {
    REQUIRE(greeter.sayHello() == "Hello");
    REQUIRE_FALSE(greeter.sayHello() == "Yikes");

}


TEST_CASE("Greeter test 2") {

    Greeter greeter("Hello");
    greeter.addGreet("hi");
    CHECK(greeter.sayHello() == "Hello\nhi");
}

TEST_CASE("Greeter copy test ") {

    Greeter greeter("Hello");
    Greeter greeter2(greeter);

    REQUIRE(greeter2.sayHello() == "Hello");

}

TEST_CASE("Greeter copy 2 test ") {

    Greeter greeter("Hello");
    Greeter greeter2 = greeter;

    REQUIRE(greeter2.sayHello() == "Hello");

}