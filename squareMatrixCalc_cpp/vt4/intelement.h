/**
 * intelement.h
 */
#ifndef INTELEMENT_H_INCLUDED
#define INTELEMENT_H_INCLUDED 

#include <ostream>
#include <memory>

/**
 * IntElement class
 */
class IntElement {

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


        virtual ~IntElement() = default;


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
        std::unique_ptr<IntElement> clone() const;


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
         * Operator>>
         * /param os, i
         * /return output stream
         */
        std::ostream& operator<<(std::ostream&, const IntElement&); 

#endif
