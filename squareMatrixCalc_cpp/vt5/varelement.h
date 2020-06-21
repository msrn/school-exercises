#ifndef VARELEMENT_H_INCLUDED
#define VARELEMENT_H_INCLUDED 

#include <string>

#include "element.h"
#include "valuation.h"
class VariableElement : public Element {

	private:
		char val;
	public:
		VariableElement() : val('a') {};

		/**
		* Constructor
		* /param char v
		* 
		*/
		explicit VariableElement(char v);
		/**
		* Destructor
		*
		*/
		~VariableElement() final;

		/**
		* getVal
		* /return val
		*/
		char getVal() const;

		/**
		* setVal
		* /param val
		*/
		void setVal(char v);

		/**
		* clone Element
		* /return new VariableElement
		*/
		Element* clone() const final;

		/**
		* toString
		* /return str()
		*/
        std::string toString() const;

        /**
        * evaluate element
        * /param Valuation &val
        * /return int
        */
		int evaluate(const Valuation &val) const;

		/**
		* Equilevancy operator
		* /param VariableElement& i
		* /return val
		*/
		bool operator==(const VariableElement& i) const;

};

#endif