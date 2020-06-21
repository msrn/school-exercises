#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include "issqmatrix.h"

TEST_CASE("Is Square Matrix test one (valid)") {
    CHECK(isSquareMatrix("[[1]]"));
    CHECK(isSquareMatrix("[[1,2][1,342]]"));
    CHECK(isSquareMatrix("[[1,23,3][1,2,3][1,2,3]]"));
    CHECK(isSquareMatrix("[[1,22,3,4][1,2,333,4][1,2,33,4][1,2,-3,4]]"));;
    CHECK(isSquareMatrix("[[1,2,3,-4,5][1,2,3,44,5][1,2,3,-4,5][1,2,3,4,5][1,2,3,4,5]]"));
    CHECK(isSquareMatrix("[[1,2,3,4,5,6][1,2,3,674,5,6][1,2,3,4,5,6][1,2,3,4,5,654][1,2,3,4,54,6][1,2,3,4,5,6]]"));
    CHECK(isSquareMatrix("[[-4561]]"));
}
TEST_CASE("Is Square Matrix test two (invalid") {
    CHECK_FALSE(isSquareMatrix("[[1,2,3][1,2]]"));
    CHECK_FALSE(isSquareMatrix("[[1,2][1,2,3]]"));
    CHECK_FALSE(isSquareMatrix("[[1,2,3,4][1,2]]"));
    CHECK_FALSE(isSquareMatrix("[[1,2][1,2,4,5]]"));
    CHECK_FALSE(isSquareMatrix("[[1,2,3][1,2,3][1,2]]"));
    CHECK_FALSE(isSquareMatrix("[[1,2,3][1,2][1,2,3]]"));
    CHECK_FALSE(isSquareMatrix("[[1,3][1,2,3][1,2,3]]"));
    CHECK_FALSE(isSquareMatrix("[[1][1,2,3][1,2,3][1,2,3]]"));
    CHECK_FALSE(isSquareMatrix("[[1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10][1,2,3,4,5,6,7,8,9,10]]"));
}
TEST_CASE("Doesn't take invalid inputs") {
    CHECK_FALSE(isSquareMatrix("[[3a,3]]"));
    CHECK_FALSE(isSquareMatrix("[[a3,3]]"));
    CHECK_FALSE(isSquareMatrix("[[4b,5g][5a,4]]"));
    CHECK_FALSE(isSquareMatrix("[[3,45][45,5][aa,bb]]"));
    CHECK_FALSE(isSquareMatrix("[[$€,asd][66y,78][34,34]]"));
    CHECK_FALSE(isSquareMatrix("[[455,33.0][45.0,4]]"));
}
TEST_CASE("Accepts brackets in correct order and correct amount") {
    CHECK_FALSE(isSquareMatrix("[3,4][56,78]]"));
    CHECK_FALSE(isSquareMatrix("[[3,4[34,78]]"));
    CHECK_FALSE(isSquareMatrix("[[3,5]45,78]]"));
    CHECK_FALSE(isSquareMatrix("[[34,55][34,67]"));
    CHECK_FALSE(isSquareMatrix("[[34,55][34,67"));
    CHECK_FALSE(isSquareMatrix("[[1,23,3][1,2,3[1,2,3]]"));
    CHECK_FALSE(isSquareMatrix("[[1,23,3][1,2,3[1,2,3]"));
    CHECK_FALSE(isSquareMatrix("[[,][,]]"));
    CHECK_FALSE(isSquareMatrix("67,7][7,67]]"));
    CHECK_FALSE(isSquareMatrix("[[34,56,7][78,4,5][67,7,7]]]]"));
    CHECK_FALSE(isSquareMatrix("[[[[1,23,3][1,2,3][1,2,3]"));
    CHECK_FALSE(isSquareMatrix("[1,23,3]]]][1,2,3][[[[1,2,3]"));
}

/**
int main (int argc, char** argv) {
    std::string string= "";

    do {
        std::cout << "Merkijono >";

        std::cin >> string;

        if (isSquareMatrix(string)) {
            std::cout << "OK" << std::endl;
        } else {
            std::cout << "Not ok" << std::endl;
        }

        } while (string != "q");

        return 0;
}
**/        
