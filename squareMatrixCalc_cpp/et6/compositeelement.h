#ifndef COMPOSITEELEMENT_H_INCLUDED
#define COMPOSITEELEMENT_H_INCLUDED

#include "element.h"
#include "valuation.h"

class CompositeElement : public Element {

	private:
		Element* oprnd1;
		Element* oprnd2;
		std::function<int(int,int)> op_fun;
		char op_ch;

	public:

		/**
        * Constructor
        * /param Element&, std::function<int(int,int)>&, char
        * /throws std::invalid_argument 
        */
		CompositeElement(const Element& e1, const Element& e2, const std::function<int(int,int)>& op, char opc);

		/**
		* Copy constructor
		* /param CompositeElement&
		*/
		CompositeElement(const CompositeElement& e);


		/**
		* Operator=
		* Copy assignment operator
		* /param CompositeElement% e
		* /return *this
		* /throws std::invalid_argument 
		*/
		CompositeElement& operator=(const CompositeElement% e);

		/**
        * Destructor
         */
        ~CompositeElement() = default;

        /**
         * Clone function, return pointer to created object
         * /return *this
         */
        Element* clone() const final;

         /**
         * Return CompositeElement string
         * /return std::tring value
         */
        std::string toString() const;

        /**
        * evaluate element
        * /param Valuation &val
        * /return int
        */
        int evaluate(const Valuation& v);		
}

#endif