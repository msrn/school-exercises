/**
 * IntElement implementation
 */
#include "catch.hpp"

#include "intelement.h"


IntElement::IntElement(int v) {
    this->val = v;
}



std::unique_ptr<IntElement> IntElement::clone() const {
    return std::unique_ptr<IntElement>(new IntElement(*this));
}



IntElement& IntElement::operator+=(const IntElement& i) {
    this->val += i.val;
    return *this;
}


IntElement& IntElement::operator-=(const IntElement& i) {
    this->val -= i.val;
    return *this;
}



IntElement& IntElement::operator*=(const IntElement& i) {
    this->val *= i.val;
    return *this;
}


bool IntElement::operator==(const IntElement& i) const {
    if (this->val != i.val) {
        return false;
    }
    return true;
}



IntElement operator+(const IntElement& lhs, const IntElement& rhs) {
    IntElement intElem{lhs};
    intElem+=rhs;
    return intElem;
}



IntElement operator-(const IntElement& lhs, const IntElement& rhs) {

    IntElement intElem{lhs};
    intElem-=rhs;
    return intElem;
}




IntElement operator*(const IntElement& lhs, const IntElement& rhs) {
    IntElement intElem{lhs};
    intElem*=rhs;
    return intElem;
}



std::ostream& operator<<(std::ostream& os, const IntElement& i) {
    os << i.getVal();
    return os;
}

