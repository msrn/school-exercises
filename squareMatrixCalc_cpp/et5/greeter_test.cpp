#define CATCH_CONFIG_MAIN
#include "greeter.h"
#include "greet.h"
#include "catch.hpp"


/*
Greeter greeter("Hello");

TEST_CASE("Greeter test") {
    REQUIRE(greeter.sayHello() == "Hello");
    REQUIRE_FALSE(greeter.sayHello() == "Yikes");

}
*/


TEST_CASE("Greeter test 1") {

    Greeter greeter (new MoroGreet{});

    greeter.addGreet(new HelloGreet{});
    CHECK(greeter.sayHello() == "Moro\nHello");
}
/*
TEST_CASE("Greeter copy test ") {

    Greeter greeter("Hello");
    Greeter greeter2(greeter);

    REQUIRE(greeter2.sayHello() == "Hello");

}
*/
