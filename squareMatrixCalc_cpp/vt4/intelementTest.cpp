#include "intelement.h"
#include "catch.hpp"

#include <sstream>

TEST_CASE ("Addition test intElement") {
	IntElement int1{1};
	IntElement int2{1};
	
	int1 += int2;
	CHECK(int1.getVal() == 2);
}

TEST_CASE ("Subtraction test intElement") {
	IntElement int1{1};
	IntElement int2{1};
	
	int1 -= int2;
	CHECK(int1.getVal() == 0);
}

TEST_CASE ("Multiply test intElement") {
	IntElement int1{3};
	IntElement int2{1};
	
	int1 *= int2;
	CHECK(int1.getVal() == 3);
}

TEST_CASE ("Addition test two intElement") {
	IntElement int1{1};
	IntElement int2{1};
	IntElement int3{};

	int3 = int1 + int2;
	CHECK(int3.getVal() == 2);
}

TEST_CASE ("Subtraction test two intElement") {
	IntElement int1{1};
	IntElement int2{1};
	IntElement int3{};

	int3 = int1 - int2;
	CHECK(int3.getVal() == 0);
}

TEST_CASE ("Multiply test two intElement") {
	IntElement int1{3};
	IntElement int2{1};
	IntElement int3{};
	
	int3 = int1 * int2;
	CHECK(int3.getVal() == 3);
}

TEST_CASE ("Insert << operator intElement") {
	std::stringstream out;
	IntElement int1{3};

	out << int1.getVal();
	CHECK(out.str() == "3");
}
TEST_CASE ("setVal test intElement") {
	IntElement int1{3};
	int1.setVal(10);

	CHECK(int1.getVal() == 10);
}

TEST_CASE ("Equality test") {
	IntElement int1{3};
	IntElement int2{3};

	
	CHECK(int1 == int2);
}

TEST_CASE ("Clone -function test") {
	IntElement int1{3};
	IntElement int2 = *int1.clone();

	
	CHECK(int1 == int2);
}