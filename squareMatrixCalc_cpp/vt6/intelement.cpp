/**
 * IntElement implementation
 */
#include <string>
#include <sstream>
#include "catch.hpp"

#include "intelement.h"

/**
 * Contstructor
 * Assint parameter to value
 * /param v
 */
IntElement::IntElement(int v) {
    this->val = v;
}

/**
 * clone function, return pointer to created object
 * /return *this
 */
Element* IntElement::clone() const {
    return new IntElement(*this);
}
/*
 * toString functions
 * \return str()
*/
std::string IntElement::toString() const {
	std::stringstream ss;
	ss << this->val;
	return ss.str();
}

/**
 * Evaluate element
 * /return val
 */
int IntElement::evaluate(const Valuation &val) const {
	return this->val;
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
 * Operator<<
 * /param os, i
 * /return output stream
 */
std::ostream& operator<<(std::ostream& os, const IntElement& i) {
    os << i.getVal();
    return os;
}

