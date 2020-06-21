#include "catch.hpp"
#include "varelement.h"
#include "valuation.h"

TEST_CASE("Valuation tests [Valuation]") {
    Valuation val;
    val['a'] = 1;
    VariableElement varl{'a'};
    VariableElement var2{'z'};
    CHECK(varl.evaluate(val) == 1);
    CHECK_THROWS(var2.evaluate(val));
}
 