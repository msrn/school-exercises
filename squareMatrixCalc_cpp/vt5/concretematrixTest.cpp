#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "concretematrix.h"
#include "varelement.h"
#include "valuation.h"
#include "symbolicmatrix.h"



TEST_CASE("Transpose [ConcreteSquareMatrix]") {
    
	ConcreteSquareMatrix matrix1{"[[1,2][3,4]]"};
  	ConcreteSquareMatrix transpose = matrix1.transpose();
  	CHECK(transpose.toString() == "[[1,3][2,4]]");
}

TEST_CASE ("operator += [ConcreteSquareMatrix]") {
	ConcreteSquareMatrix matrix1{"[[1,2][2,3]]"};
	ConcreteSquareMatrix matrix2{"[[4,5][6,7]]"};
	matrix1 += matrix2;

	CHECK(matrix1.toString() == "[[5,7][8,10]]");
	CHECK_FALSE(matrix1.toString() == "[[35,7][8,10]]");

}

TEST_CASE ("operator + [ConcreteSquareMatrix]") {
	ConcreteSquareMatrix matrix1{"[[1,2][2,3]]"};
	ConcreteSquareMatrix matrix2{"[[4,5][6,7]]"};
	
	ConcreteSquareMatrix matrix3 = matrix1 + matrix2;

	CHECK(matrix3.toString() == "[[5,7][8,10]]");
	CHECK_FALSE(matrix3.toString() == "[[35,7][8,10]]");

}

TEST_CASE ("operator -= [ConcreteSquareMatrix]") {

	ConcreteSquareMatrix matrix1{"[[1,2][2,3]]"};
	ConcreteSquareMatrix matrix2{"[[4,5][6,7]]"};
	matrix1 -= matrix2;

	CHECK(matrix1.toString() == "[[-3,-3][-4,-4]]");
	CHECK_FALSE(matrix1.toString() == "[[5,1137][84,103]]");

}

TEST_CASE ("operator - [ConcreteSquareMatrix]") {
	ConcreteSquareMatrix matrix1{"[[1,2][2,3]]"};
	ConcreteSquareMatrix matrix2{"[[4,5][6,7]]"};
	
	ConcreteSquareMatrix matrix3 = matrix1 - matrix2;

	CHECK(matrix3.toString() == "[[-3,-3][-4,-4]]");
	CHECK_FALSE(matrix3.toString() == "[[5,1137][84,103]]");

}

TEST_CASE("operator* [ConcreteSquareMatrix]") {
    ConcreteSquareMatrix matrix1{"[[1,2][2,3]]"};
	ConcreteSquareMatrix matrix2{"[[4,5][6,7]]"};
	
	ConcreteSquareMatrix matrix3 = matrix1 * matrix2;

	CHECK(matrix3.toString() == "[[16,19][26,31]]");
	CHECK_FALSE(matrix3.toString() == "[[534,7][8,1220]]");
}

TEST_CASE ("operator*= [ConcreteSquareMatrix]") {
	ConcreteSquareMatrix matrix1{"[[1,2][2,3]]"};
	ConcreteSquareMatrix matrix2{"[[4,5][6,7]]"};

	matrix1 *= matrix2;

	CHECK(matrix1.toString() == "[[16,19][26,31]]");
	CHECK_FALSE(matrix1.toString() == "[[534,7][8,1220]]");
}


TEST_CASE("Invalid string [ConcreteSquareMatrix]") {
    CHECK_THROWS(ConcreteSquareMatrix(""));
    CHECK_THROWS(ConcreteSquareMatrix("9"));
    CHECK_THROWS(ConcreteSquareMatrix("[3]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1,2][1,2,3]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1,2,][1,2,3]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[34,55][34,67"));
    CHECK_THROWS(ConcreteSquareMatrix("[[$€,asd][66y,78][34,34]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[34,56,7][78,4,5][67,7,7]]]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1][1,2,3][1,2,3][1,2,3]]"));
    CHECK_THROWS(ConcreteSquareMatrix("[[1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10]]"));
}

TEST_CASE("Equivelancy [ConcreteSquareMatrix]") {
    ConcreteSquareMatrix matrix1{"[[1,2][2,3]]"};
	ConcreteSquareMatrix matrix2{"[[1,2][2,3]]"};

	
	CHECK(matrix1 == matrix2);
}

TEST_CASE("Move operator [ConcreteSquareMatrix") {
    ConcreteSquareMatrix matrix1{"[[1,2][3,4]]"};
    ConcreteSquareMatrix matrix2{std::move(matrix1)};
    CHECK(matrix2.toString() == "[[1,2][3,4]]");
}

TEST_CASE("Copy operators [ConcreteSquareMatrix]") {
    ConcreteSquareMatrix matrix1{"[[1,2][1,1]]"};
    ConcreteSquareMatrix matrix2("[[1,2][3,4]]");
    ConcreteSquareMatrix matrix3("[[1,2][3,4]]");
    matrix1 = matrix2;
    matrix3 = matrix2;
    CHECK(matrix1.toString() == "[[1,2][3,4]]");
    CHECK(matrix3.toString() == "[[1,2][3,4]]");
}

TEST_CASE("Move assignment [ConcreteSquareMatrix]") {
    ConcreteSquareMatrix matrix1("[[1,2][1,1]]");
    ConcreteSquareMatrix matrix2("[[1,2][3,4]]");
    matrix1 = std::move(matrix2);
    CHECK(matrix1.toString() == "[[1,2][3,4]]");
}

TEST_CASE("operator << [ConcreteSquareMatrix]") {
    ConcreteSquareMatrix matrix{"[[1,2][3,4]]"};
    std::stringstream ss;
    ss << matrix;
    CHECK(ss.str() == "[[1,2][3,4]]");
}