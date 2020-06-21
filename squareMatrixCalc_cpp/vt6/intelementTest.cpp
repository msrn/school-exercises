#include "catch.hpp"
#include "intelement.h"

#include <sstream>
#include <memory>

TEST_CASE ("Addition test [IntElement]") {
	IntElement int1{1};
	IntElement int2{1};
	
	int1 += int2;
	CHECK(int1.getVal() == 2);
}

TEST_CASE ("Subtraction test [IntElement]") {
	IntElement int1{1};
	IntElement int2{1};
	
	int1 -= int2;
	CHECK(int1.getVal() == 0);
}

TEST_CASE ("Multiply test [IntElement]") {
	IntElement int1{3};
	IntElement int2{1};
	
	int1 *= int2;
	CHECK(int1.toString() == "3");
}

TEST_CASE ("Addition test two [IntElement]") {
	IntElement int1{1};
	IntElement int2{1};
	IntElement int3{};

	int3 = int1 + int2;
	CHECK(int3.getVal() == 2);
}

TEST_CASE ("Subtraction test two [IntElement]") {
	IntElement int1{1};
	IntElement int2{1};
	IntElement int3{};

	int3 = int1 - int2;
	CHECK(int3.getVal() == 0);
}

TEST_CASE ("Multiply test two [IntElement]") {
	IntElement int1{3};
	IntElement int2{1};
	IntElement int3{};
	
	int3 = int1 * int2;
	CHECK(int3.getVal() == 3);
}

TEST_CASE ("Insert << operator [IntElement]") {
	std::stringstream out;
	IntElement int1{3};

	out << int1.getVal();
	CHECK(out.str() == "3");
}
TEST_CASE ("setVal test [IntElement]") {
	IntElement int1{3};
	int1.setVal(4);

	CHECK(int1.getVal() == 4);
}

TEST_CASE ("Equality test [IntElement]") {
	IntElement int1{1};
	IntElement int2{1};
	IntElement int3{2};

	
	CHECK(int1 == int2);
	CHECK_FALSE(int1 == int3);
}


TEST_CASE("IntElement: Test Element Interface [IntElement]") {
    Valuation val{{'a',100}};
    Element* elem = new IntElement();
    Element* cp = elem->clone();

    CHECK(elem->toString() == "0");
    CHECK(cp->toString() == "0");
    CHECK(elem->evaluate(val) == 0);

    delete(elem);
    delete(cp);
}