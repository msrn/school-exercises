#define CATCH_CONFIG_MAIN
#include "squarematrix.h"
#include "catch.hpp"



TEST_CASE ("Addition test") {
	SquareMatrix matrix1{1,2,2,3};
	SquareMatrix matrix2{4,5,6,7};
	matrix1 += matrix2;

	CHECK(matrix1.toString() == "[[5,7][8,10]]");
	CHECK_FALSE(matrix1.toString() == "[[35,7][8,10]]");

}



TEST_CASE ("Subtraction test") {

	SquareMatrix matrix1{1,2,2,3};
	SquareMatrix matrix2{4,5,6,7};
	matrix1 -= matrix2;

	CHECK(matrix1.toString() == "[[-3,-3][-4,-4]]");
	CHECK_FALSE(matrix1.toString() == "[[5,1137][84,103]]");

}

TEST_CASE ("Multiply test") {
	SquareMatrix matrix1{1,2,2,3};
	SquareMatrix matrix2{4,5,6,7};

	matrix1 *= matrix2;

	CHECK(matrix1.toString() == "[[16,19][26,31]]");
	CHECK_FALSE(matrix1.toString() == "[[534,7][8,1220]]");
}