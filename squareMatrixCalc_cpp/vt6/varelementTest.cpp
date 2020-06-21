#include "catch.hpp"
#include "varelement.h"
#include "valuation.h"
#include <sstream>
#include <memory>


TEST_CASE("Element [VariableElement]") {
    Valuation val{{'a',100}};
    Element* elem = new VariableElement();
    Element* cp = elem->clone();
    

    CHECK(elem->toString() == "a");
    CHECK(cp->toString() == "a");
    CHECK(elem->evaluate(val) == 100);


    delete(elem);
    delete(cp);
}

TEST_CASE("getVal() setVal() [VariableElement]") {
    VariableElement elem{'b'};

    CHECK(elem.getVal() == 'b');
    elem.setVal('c');
    CHECK(elem.getVal() == 'c');
    CHECK_THROWS(elem.setVal('0'));
}


TEST_CASE("toString() [VariableElement]") {
    VariableElement elem{'a'};
    CHECK(elem.toString() == "a");
}

TEST_CASE("VarElement evaluate() test [VariableElement]") {
    Valuation val;
    val['a'] = 1;
    VariableElement elem{'a'};
    CHECK(elem.evaluate(val) == 1);
}

TEST_CASE("operator == [VariableElement]") {
    VariableElement elem1{'y'};
    VariableElement elem2{'y'};
    CHECK(elem1 == elem2);

}
