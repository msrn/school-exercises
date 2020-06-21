/**
 * IntElement implementation
 */
#include "catch.hpp"

#include "intelement.h"

#include <ostream>


/**
 * Contstructor
 * Assint parameter to value
 * /param v
 */

IntElement::IntElement(int v) {
    this->val = v;
}

/**
 * Operator+=
 * /param i
 * /return *this
 */

IntElement& IntElement::operator+=(const IntElement& i) {
    this->val += i.val;
    return *this;
}

/**
 * Operator-=
 * /param i
 * /return *this
 */

IntElement& IntElement::operator-=(const IntElement& i) {
    this->val -= i.val;
    return *this;
}

/**
 * Operator*=
 * /param i
 * /return *this
 */

IntElement& IntElement::operator*=(const IntElement& i) {
    this->val *= i.val;
    return *this;
}
/**
 * Operator==
 * /param i
 * /return *this
 */

bool IntElement::operator==(const IntElement& i) const {
    if (this->val != i.val) {
        return false;
    }
    return true;
}

/**
 * Operator+
 * /param lhs, rhs
 * /return intElement
 */

IntElement operator+(const IntElement& lhs, const IntElement& rhs) {
    IntElement intElem{lhs};
    intElem+=rhs;
    return intElem;
}

/**
 * Operator-
 * /param lhs, rhs
 * /return intElement
 */

IntElement operator-(const IntElement& lhs, const IntElement& rhs) {

    IntElement intElem{lhs};
    intElem-=rhs;
    return intElem;
}

/**
 * Operator*
 * /param lhs, rhs
 * /return intElement
 */


IntElement operator*(const IntElement& lhs, const IntElement& rhs) {
    IntElement intElem{lhs};
    intElem*=rhs;
    return intElem;
}

/**
 * Operator>>
 * /param os, i
 * /return output stream
 */

std::ostream& operator<<(std::ostream& os, const IntElement& i) {
    os << i.getVal();
    return os;
}

