#include <string>
#include <cctype>
#include <sstream>

#include "varelement.h"


/**
* Destructor
*
*/
VariableElement::~VariableElement() = default;

/**
* Constructor
* /param char v
* 
*/
VariableElement::VariableElement(char v) {
	if (std::isalpha(v)) {
		this->val = v;
	} else {
		 throw std::invalid_argument("Not char");
	}
}

/**
* getVal
* /return val
*/
char VariableElement::getVal() const { 
	return this->val; 
}

/**
* setVal
* /param val
*/
void VariableElement::setVal(char v) {
	 if (std::isalpha(v)) {
		this->val = v;
	} else {
		 throw std::invalid_argument("Not char");
	}
}

/**
* clone Element
* /return new VariableElement
*/
Element* VariableElement::clone() const  {

	return new VariableElement(*this);

}

/**
* toString
* /return str()
*/
std::string VariableElement::toString() const {
	std::stringstream ss;
	ss << this->val;
	return ss.str();
}

/**
* evaluate element
* /param Valuation &val
* /return int
*/
int VariableElement::evaluate(const Valuation &val) const {
	int integer;
	return integer = val.at(this->val);

}

/**
* Equilevancy operator
* /param VariableElement& i
* /return val
*/
bool VariableElement::operator==(const VariableElement& i) const {
	return this->val == i.val;
}	

