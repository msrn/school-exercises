/**
 * symbolicsquarematrix.h
 */

#ifndef SYMBOLICSQUAREMATRIX_H_INCLUDED
#define SYMBOLICSQUAREMATRIX_H_INCLUDED

#include "element.h"
#include "valuation.h"
#include "concretesquarematrix.h"
#include <ostream>
#include <vector>
#include <memory>
/**
 * SymbolicSquareMatrix class
 */
class SymbolicSquareMatrix {

    private:
        unsigned int n;
        std::vector <std::vector <std::unique_ptr<Element>>>  elements;
    public:
        SymbolicSquareMatrix();


        /**
        * Constructor
        * Checks for string validity
        * /param std::string& str_m
        * /throws std::invalid_argument 
        */
        SymbolicSquareMatrix(const std::string& str_m);


        /**
        * Copy constructor
        * /param SymbolicSquareMatrix& m
        */
        SymbolicSquareMatrix(const SymbolicSquareMatrix& m);


        /**
        * Move constructor
        * /param SymbolicSquareMatrix& m
        */
        SymbolicSquareMatrix(SymbolicSquareMatrix&& m);


        ~SymbolicSquareMatrix() = default;


        /**
        * Operator=
        * /param SymbolicSquareMatrix& m
        * /return *this
        * /throws std::invalid_argument 
        */
        SymbolicSquareMatrix& operator=(const SymbolicSquareMatrix& m);


        /**
        * Operator=
        * Assignment operator
        * /param SymbolicSquareMatrix&& m
        * /return *this
        * /throws std::invalid_argument 
        */
        SymbolicSquareMatrix& operator=(SymbolicSquareMatrix&& m);


        /**
         * Operator+=
         * /param SymbolicSquareMatrix& m
         * /return *this
         * /throws std::invalid_argument 
        */
        SymbolicSquareMatrix& operator+=(const SymbolicSquareMatrix& m);


        /**
         * Operator-=
         * /param SymbolicSquareMatrix& m
         * /return *this
         * /throws std::invalid_argument 
        */
        SymbolicSquareMatrix& operator-=(const SymbolicSquareMatrix& m);


        /**
         * Operator*=
         * /param SymbolicSquareMatrix& m
         * /return *this
         * /throws std::invalid_argument 
        */
        SymbolicSquareMatrix& operator*=(const SymbolicSquareMatrix& m);


        /**
         * Operator==
         * Equivilance operator
         * /param SymbolicSquareMatrix& m
         * /return false or ture
         * /throws std::invalid_argument 
        */
        bool operator==(const SymbolicSquareMatrix& m) const;


        /**
         * Operator==
         * Inequivilance operator
         * /param SymbolicSquareMatrix& m
         * /return false or ture
         * /throws std::invalid_argument 
        */
        bool operator!=(const SymbolicSquareMatrix& m) const;


        /**
         * Return tranpose of a square matrix
         * /param 
         * /return transpose
         * 
        */
        SymbolicSquareMatrix transpose() const;


        /**
         * Print squarematrix
         * /param os
         */
        void print(std::ostream& os) const;


        /**
         * Return Squarematrix string
         * /return String value
         */
        std::string toString() const;

        ConcreteSquareMatrix evaluate(const Valuation& val) const;
};
#endif
