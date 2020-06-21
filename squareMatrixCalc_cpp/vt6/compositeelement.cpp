#include "compositeelement.h"

#include <string>
#include <sstream>

/**
* Constructor
* /param Element&, std::function<int(int,int)>&, char
*/
CompositeElement::CompositeElement(const Element& e1, 
	const Element& e2, 
	const std::function<int(int,int)>& op, 
	char opc) :
	oprnd1{std::unique_ptr<Element>{e1.clone()}},
	oprnd2{std::unique_ptr<Element>{e2.clone()}},
	op_fun{op},
	op_ch{opc} {}

/**
* Copy constructor
* /param CompositeElement&
*/
CompositeElement::CompositeElement(const CompositeElement& e) {
	this->oprnd1 = std::unique_ptr<Element>{e.oprnd1->clone()};
	this->oprnd2 = std::unique_ptr<Element>{e.oprnd2->clone()};
	this->op_fun = e.op_fun;
	this->op_ch = e.op_ch;
}

/**
* Operator=
* Copy assignment operator
* /param CompositeElement% e
* /return *this
* /throws std::invalid_argument 
*/
CompositeElement& CompositeElement::operator=(const CompositeElement& e) {
	this->oprnd1 = std::unique_ptr<Element>{e.oprnd1->clone()};
	this->oprnd2 = std::unique_ptr<Element>{e.oprnd2->clone()};
	this->op_fun = e.op_fun;
	this->op_ch = e.op_ch;

	
}

/**
 * Clone function, return pointer to created object
 * /return *this
 */
Element* CompositeElement::clone() const {
	return new CompositeElement{*this};
}

/**
* Return CompositeElement string
* /return std::tring value
*/
std::string CompositeElement::toString() const {
	std::stringstream ss;

	ss << "(" << this->oprnd1->toString() << op_ch << this->oprnd2->toString() << ")";

	return ss.str();
}

/**
* evaluate element
* /param Valuation &val
* /return int
*/
int CompositeElement::evaluate(const Valuation& v) const{
	    return this->op_fun(this->oprnd1->evaluate(v), this->oprnd2->evaluate(v));
}