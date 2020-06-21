/**
 * symbolicmatrix.h
 */

#ifndef SYMBOLICMATRIX_H_INCLUDED
#define SYMBOLICMATRIX_H_INCLUDED

#include "element.h"
#include "intelement.h"
#include "valuation.h"
#include "concretematrix.h"
#include "varelement.h"
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

        /**
         * Constructor initialize n
         */
        SymbolicSquareMatrix();


        /**
        * Constructor
        * Checks for string validity
        * /param std::string& str_m
        * /throws std::invalid_argument 
        */
        explicit SymbolicSquareMatrix(const std::string& str_m);


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
        * Copy assignment operator
        * /param SymbolicSquareMatrix& m
        * /return *this
        * /throws std::invalid_argument 
        */
        SymbolicSquareMatrix& operator=(const SymbolicSquareMatrix& m);


        /**
        * Operator=
        * Move Assignment operator
        * /param SymbolicSquareMatrix&& m
        * /return *this
        * /throws std::invalid_argument 
        */
        SymbolicSquareMatrix& operator=(SymbolicSquareMatrix&& m);




        /**
         * Operator==
         * Equivilance operator
         * /param SymbolicSquareMatrix& m
         * /return false or ture
         * /throws std::invalid_argument 
        */
        bool operator==(const SymbolicSquareMatrix& m) const;

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

        /**
         * Evaluate objectg
         * /param String value
         * /return ConcreteSquareMatrix
         */
        ConcreteSquareMatrix evaluate(const Valuation& val) const;
};

/**
 * operator<<
 * /param std::ostream&,SymbolicSquareMatrix&
 * /return ostream
 */
std::ostream& operator<<(std::ostream&, const SymbolicSquareMatrix&);
#endif
