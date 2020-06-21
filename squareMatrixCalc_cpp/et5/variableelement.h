#ifndef VARIABLEELEMENT_H_INCLUDED
#define VARIABLEELEMENT_H_INCLUDED 

#include <string>

#include "element.h"
#include "valuation.h"
class VariableElement : public Element {

	private:
		char var;
	public:
		VariableElement();
		VariableElement(char v);
		~VariableElement() = default;

		char getVal() const { return this->var; }
		void setVal(char v) { this->var = v; }

		Element* clone() const final;

        std::string toString() const;

		int evaluate(const Valuation &val) const;

		bool operator==(const VariableElement& i) const;

};

#endif