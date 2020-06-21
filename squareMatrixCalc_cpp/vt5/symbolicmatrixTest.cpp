#include <sstream>
#include "catch.hpp"
#include "concretematrix.h"
#include "valuation.h"
#include "symbolicmatrix.h"



TEST_CASE(" Copy constructor[SymbolicSquareMatrix]") {
    SymbolicSquareMatrix matrix("[[a,2][c,4]]");
    SymbolicSquareMatrix copy{ matrix};
    CHECK(matrix.toString() == "[[a,2][c,4]]");
    CHECK(copy.toString() == "[[a,2][c,4]]");
}

TEST_CASE("Transpose [SymbolicSquareMatrix]") {
    
	SymbolicSquareMatrix matrix1{"[[1,2][3,4]]"};
  	SymbolicSquareMatrix transpose = matrix1.transpose();
  	CHECK(transpose.toString() == "[[1,3][2,4]]");
}

TEST_CASE("Invalid string [SymbolicSquareMatrix]") {
    CHECK_THROWS(SymbolicSquareMatrix(""));
    CHECK_THROWS(SymbolicSquareMatrix("9"));
    CHECK_THROWS(SymbolicSquareMatrix("[3]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,2][1,2,3]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,2,][1,2,3]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[34,55][34,67"));
    CHECK_THROWS(SymbolicSquareMatrix("[[$€,asd][66y,78][34,34]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[34,56,7][78,4,5][67,7,7]]]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1][1,2,3][1,2,3][1,2,3]]"));
    CHECK_THROWS(SymbolicSquareMatrix("[[1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10]]"));
}

TEST_CASE("Equivelancy [SymbolicSquareMatrix]") {
    SymbolicSquareMatrix matrix1{"[[1,2][2,3]]"};
	SymbolicSquareMatrix matrix2{"[[1,2][2,3]]"};
	SymbolicSquareMatrix matrix3{"[[1,2,3][1,2,3][1,2,3]]"};

	
	CHECK(matrix1 == matrix2);
	CHECK_FALSE(matrix1 == matrix3);
}

TEST_CASE("Move operator SymbolicSquareMatrix") {
    SymbolicSquareMatrix matrix1{"[[1,2][3,4]]"};
    SymbolicSquareMatrix matrix2{std::move(matrix1)};
    CHECK(matrix2.toString() == "[[1,2][3,4]]");
}

TEST_CASE("Copy operators [SymbolicSquareMatrix]") {
    SymbolicSquareMatrix matrix1{"[[1,2][1,1]]"};
    SymbolicSquareMatrix matrix2("[[1,2][3,4]]");
    SymbolicSquareMatrix matrix3("[[1,2][3,4]]");
    matrix1 = matrix2;
    matrix3 = matrix2;
    CHECK(matrix1.toString() == "[[1,2][3,4]]");
    CHECK(matrix3.toString() == "[[1,2][3,4]]");
}

TEST_CASE("Evaluate [SymbolicSquareMatrix]") {
    Valuation val{{'a',1}};
    SymbolicSquareMatrix matrix{"[[a,2][3,4]]"};
    CHECK(matrix.evaluate(val).toString() == "[[1,2][3,4]]");
}

TEST_CASE("operator << [SymbolicSquareMatrix]") {
    SymbolicSquareMatrix matrix{"[[1,2][3,4]]"};
    std::stringstream ss;
    ss << matrix;
    CHECK(ss.str() == "[[1,2][3,4]]");
}

TEST_CASE("Move assignment [SymbolicSquareMatrix]") {
    SymbolicSquareMatrix matrix1("[[1,2][1,1]]");
    SymbolicSquareMatrix matrix2("[[1,2][3,4]]");
    matrix1 = std::move(matrix2);
    CHECK(matrix1.toString() == "[[1,2][3,4]]");

}