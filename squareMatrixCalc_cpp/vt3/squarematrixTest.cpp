#define CATCH_CONFIG_MAIN
#include "squarematrix.h"
#include "catch.hpp"



TEST_CASE ("Addition test") {
	SquareMatrix matrix1{"[[1,2][2,3]]"};
	SquareMatrix matrix2{"[[4,5][6,7]]"};
	matrix1 += matrix2;

	CHECK(matrix1.toString() == "[[5,7][8,10]]");
	CHECK_FALSE(matrix1.toString() == "[[35,7][8,10]]");

}

TEST_CASE ("Addition test 2") {
	SquareMatrix matrix1{"[[1,2][2,3]]"};
	SquareMatrix matrix2{"[[4,5][6,7]]"};
	
	SquareMatrix matrix3 = matrix1 + matrix2;

	CHECK(matrix3.toString() == "[[5,7][8,10]]");
	CHECK_FALSE(matrix3.toString() == "[[35,7][8,10]]");

}



TEST_CASE ("Subtraction test") {

	SquareMatrix matrix1{"[[1,2][2,3]]"};
	SquareMatrix matrix2{"[[4,5][6,7]]"};
	matrix1 -= matrix2;

	CHECK(matrix1.toString() == "[[-3,-3][-4,-4]]");
	CHECK_FALSE(matrix1.toString() == "[[5,1137][84,103]]");

}

TEST_CASE ("Subtraction test 2") {
	SquareMatrix matrix1{"[[1,2][2,3]]"};
	SquareMatrix matrix2{"[[4,5][6,7]]"};
	
	SquareMatrix matrix3 = matrix1 - matrix2;

	CHECK(matrix3.toString() == "[[-3,-3][-4,-4]]");
	CHECK_FALSE(matrix3.toString() == "[[5,1137][84,103]]");

}

TEST_CASE ("Multiply test") {
	SquareMatrix matrix1{"[[1,2][2,3]]"};
	SquareMatrix matrix2{"[[4,5][6,7]]"};

	matrix1 *= matrix2;

	CHECK(matrix1.toString() == "[[16,19][26,31]]");
	CHECK_FALSE(matrix1.toString() == "[[534,7][8,1220]]");
}

TEST_CASE ("Multiply test 2") {
	SquareMatrix matrix1{"[[1,2][2,3]]"};
	SquareMatrix matrix2{"[[4,5][6,7]]"};
	
	SquareMatrix matrix3 = matrix1 * matrix2;

	CHECK(matrix3.toString() == "[[16,19][26,31]]");
	CHECK_FALSE(matrix3.toString() == "[[534,7][8,1220]]");

}

TEST_CASE ("print") {
	SquareMatrix matrix1{"[[1,2,3][4,5,6][7,8,9]]"};
	CHECK(matrix1.toString() == "[[1,2,3][4,5,6][7,8,9]]");
}

TEST_CASE("transpose") {

	SquareMatrix matrix1{"[[1,2][3,4]]"};
  	SquareMatrix transpose = matrix1.transpose();
  	CHECK(transpose.toString() == "[[1,3][2,4]]");

}

TEST_CASE ("Insert << operator SquareMatrix") {
	std::stringstream out;
	SquareMatrix matrix1{"[[1,2][2,3]]"};

	out << matrix1.toString();
	CHECK(out.str() == "[[1,2][2,3]]");
}

TEST_CASE ("Equality test SquareMatrix") {
	SquareMatrix matrix1{"[[1,2][2,3]]"};
	SquareMatrix matrix2{"[[1,2][2,3]]"};

	
	CHECK(matrix1 == matrix2);
}

TEST_CASE("Invalid string") {
    CHECK_THROWS(SquareMatrix(""));
    CHECK_THROWS(SquareMatrix("9"));
    CHECK_THROWS(SquareMatrix("[3]"));
    CHECK_THROWS(SquareMatrix("[[1,2][1,2,3]]"));
    CHECK_THROWS(SquareMatrix("[[34,55][34,67"));
    CHECK_THROWS(SquareMatrix("[[$€,asd][66y,78][34,34]]"));
    CHECK_THROWS(SquareMatrix("[[34,56,7][78,4,5][67,7,7]]]]"));
    CHECK_THROWS(SquareMatrix("[[1][1,2,3][1,2,3][1,2,3]]"));
    CHECK_THROWS(SquareMatrix("[[1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10]]"));
}

