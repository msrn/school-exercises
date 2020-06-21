#include "catch.hpp"
#include "compositeelement.h"
#include "element.h"
#include "intelement.h"
#include "varelement.h"
#include <functional>
#include <memory>

TEST_CASE("Element [CompositeElement]") {
    Valuation val{{'a',100}};
    IntElement inte{100};
    VariableElement vale{'a'};

    Element* elem = new CompositeElement{inte, vale, [](int lhs, int rhs) -> int{return lhs + rhs;}, '+'};
    Element* cp = elem->clone();
    

    CHECK(elem->toString() == "(100+a)");
    CHECK(cp->toString() == "(100+a)");
    CHECK(elem->evaluate(val) == 200);


    delete(elem);
    delete(cp);
}

