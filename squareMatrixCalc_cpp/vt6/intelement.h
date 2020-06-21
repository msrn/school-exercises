/**
 * intelement.h
 */
#ifndef INTELEMENT_H_INCLUDED
#define INTELEMENT_H_INCLUDED 

#include "valuation.h"
#include "element.h"

#include <ostream>
#include <memory>

/**
 * IntElement class
 */
class IntElement : public Element {

    private:
        int val;
    public:
        IntElement() = default;

        /**
         * Contstructor
         * Assint parameter to value
         * /param v
         */
        IntElement(int v);

        /**
         * Destructor
         * Assint parameter to value
         * 
         */
        ~IntElement() = default;


        /**
        * Getter for val -variable
        * /return val
        */
        int getVal() const { return this->val; }

        /**
        * Setter for val -variable
        * /param v
        */
        void setVal(int v) { this->val = v; }


        /**
         * clone function, return pointer to created object
         * /return *this
         */
        Element* clone() const final;

        /**
         * toString functions
         * \return str()
        */
        std::string toString() const;

        /**
         * Evaluate element
         * /return val
         */
		int evaluate(const Valuation &val) const;


        /**
         * Operator+=
         * /param i
         * /return *this
         */
        IntElement& operator+=(const IntElement& i);

        /**
         * Operator-=
         * /param i
         * /return *this
         */
        IntElement& operator-=(const IntElement& i);

        /**
         * Operator*=
         * /param i
         * /return *this
         */
        IntElement& operator*=(const IntElement& i);

        /**
         * Operator==
         * /param i
         * /return *this
         */
        bool operator==(const IntElement& i) const;
};


        /**
        * Operator+
        * /param lhs, rhs
        * /return intElement
        */
        IntElement operator+(const IntElement&, const IntElement&);

        /**
         * Operator-
         * /param lhs, rhs
         * /return intElement
         */
        IntElement operator-(const IntElement&, const IntElement&);

        /**
         * Operator*
         * /param lhs, rhs
         * /return intElement
         */
        IntElement operator*(const IntElement&, const IntElement&);

        /**
         * Operator<<
         * /param os, i
         * /return output stream
         */
        std::ostream& operator<<(std::ostream&, const IntElement&); 

#endif
