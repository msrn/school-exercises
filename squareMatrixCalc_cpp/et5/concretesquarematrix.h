/**
 * concretesquarematrix.h
 */

#ifndef CONCRETESQUAREMATRIX_H_INCLUDED
#define CONCRETESQUAREMATRIX_H_INCLUDED

#include "element.h"
#include <ostream>
#include <vector>
#include <memory>
/**
 * ConcreteSquareMatrix class
 */
class ConcreteSquareMatrix {

    private:
        unsigned int n;
        std::vector <std::vector <std::unique_ptr<Element>> >  elements;
    public:
        ConcreteSquareMatrix() = default;


        /**
        * Constructor
        * Checks for string validity
        * /param std::string& str_m
        * /throws std::invalid_argument 
        */
        ConcreteSquareMatrix(const std::string& str_m);


        /**
        * Copy constructor
        * /param ConcreteSquareMatrix& m
        */
        ConcreteSquareMatrix(const ConcreteSquareMatrix& m);


        /**
        * Move constructor
        * /param ConcreteSquareMatrix& m
        */
        ConcreteSquareMatrix(ConcreteSquareMatrix&& m);


        ~ConcreteSquareMatrix() = default;


        /**
        * Operator=
        * /param ConcreteSquareMatrix& m
        * /return *this
        * /throws std::invalid_argument 
        */
        ConcreteSquareMatrix& operator=(const ConcreteSquareMatrix& m);


        /**
        * Operator=
        * Assignment operator
        * /param ConcreteSquareMatrix&& m
        * /return *this
        * /throws std::invalid_argument 
        */
        ConcreteSquareMatrix& operator=(ConcreteSquareMatrix&& m);


        /**
         * Operator+=
         * /param ConcreteSquareMatrix& m
         * /return *this
         * /throws std::invalid_argument 
        */
        ConcreteSquareMatrix& operator+=(const ConcreteSquareMatrix& m);


        /**
         * Operator-=
         * /param ConcreteSquareMatrix& m
         * /return *this
         * /throws std::invalid_argument 
        */
        ConcreteSquareMatrix& operator-=(const ConcreteSquareMatrix& m);


        /**
         * Operator*=
         * /param ConcreteSquareMatrix& m
         * /return *this
         * /throws std::invalid_argument 
        */
        ConcreteSquareMatrix& operator*=(const ConcreteSquareMatrix& m);


        /**
         * Operator==
         * Equivilance operator
         * /param ConcreteSquareMatrix& m
         * /return false or ture
         * /throws std::invalid_argument 
        */
        bool operator==(const ConcreteSquareMatrix& m) const;


        /**
         * Operator==
         * Inequivilance operator
         * /param ConcreteSquareMatrix& m
         * /return false or ture
         * /throws std::invalid_argument 
        */
        bool operator!=(const ConcreteSquareMatrix& m) const;


        /**
         * Return tranpose of a square matrix
         * /param 
         * /return transpose
         * 
        */
        ConcreteSquareMatrix transpose() const;


        /**
         * Print ConcreteSquareMatrix
         * /param os
         */
        void print(std::ostream& os) const;


        /**
         * Return ConcreteSquareMatrix string
         * /return String value
         */
        std::string toString() const;

        ConcreteSquareMatrix evaluate(const Valuation& val) const;
};
        ConcreteSquareMatrix operator+(const ConcreteSquareMatrix&, const ConcreteSquareMatrix&);
        ConcreteSquareMatrix operator-(const ConcreteSquareMatrix&, const ConcreteSquareMatrix&);
        ConcreteSquareMatrix operator*(const ConcreteSquareMatrix&, const ConcreteSquareMatrix&);
        std::ostream& operator<<(std::ostream&, const ConcreteSquareMatrix&);
#endif
