/**
 * element.h
*/
#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED 

#include "valuation.h"

class Element {

	public:
		
		virtual ~Element() = 0;

		virtual Element* clone() const = 0;
		virtual std::string toString() const = 0;

		virtual int evaluate(const Valuation &val) const = 0;
	
};

#endif
