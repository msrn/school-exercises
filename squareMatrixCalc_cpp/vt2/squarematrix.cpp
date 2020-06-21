/**
 * SquareMatrix implementation
 */
#include "squarematrix.h"

#include <sstream>

/**
 * Contstructor
 * /param e11, e12, e21, e22
 *
 */

SquareMatrix::SquareMatrix(const IntElement& e11, const IntElement& e12, const IntElement& e21, const IntElement& e22) : e11{e11}, e12{e12}, e21{e21}, e22{e22} {}

/**
 * Operator+=
 * /param m
 * /return *this
 */
SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& m) {
    this->e11 += m.e11;
    this->e12 += m.e12;
    this->e21 += m.e21;
    this->e22 += m.e22;
    return *this;
}

/**
 * Operator-=
 * /param m
 * /return *this
 */
SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& m) {
    this->e11 -= m.e11;
    this->e12 -= m.e12;
    this->e21 -= m.e21;
    this->e22 -= m.e22;
    return *this;
}

/**
 * Operator*-=
 * /param m
 * /return *this
 */
SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& m) {
    SquareMatrix mtrx{*this}; //content of current object
    this->e11=(mtrx.e11*m.e11)+(mtrx.e12*m.e21);
    this->e12=(mtrx.e11*m.e12)+(mtrx.e12*m.e22);
    this->e21=(mtrx.e21*m.e11)+(mtrx.e22*m.e21);
    this->e22=(mtrx.e21*m.e12)+(mtrx.e22*m.e22);
    return *this;

}

/**
 * Print squarematrix
 * /param os
 */
void SquareMatrix::print(std::ostream& os) const{
    os << "[[" << this->e11 << "," << this->e12 << "][" <<
        this->e21 << "," << this->e22 << "]]";
}

/**
 * Return Squarematrix string
 * /return String value
 */
std::string SquareMatrix::toString() const {
    std::stringstream strm;
    print(strm);
    return strm.str();
}

        
