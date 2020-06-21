/**
 * squarematrix.h
 */

#ifndef SQUAREMATRIX_H_INCLUDED
#define SQUAREMATRIX_H_INCLUDED

#include "intelement.h"
#include <ostream>
#include <vector>
#include <memory>
/**
 * SquareMatrix class
 */
class SquareMatrix {

    private:
        int n;
        std::vector <std::vector <std::unique_ptr<IntElement>> >  elements;
    public:
        SquareMatrix() = default;


        /**
        * Constructor
        * Checks for string validity
        * /param std::string& s
        * /throws std::invalid_argument 
        */
        SquareMatrix(const std::string& s);


        /**
        * Copy constructor
        * /param SquareMatrix& m
        */
        SquareMatrix(const SquareMatrix& m);


        /**
        * Move constructor
        * /param SquareMatrix& m
        */
        SquareMatrix(SquareMatrix&& m);


        virtual ~SquareMatrix() = default;


        /**
        * Operator=
        * /param SquareMatrix& m
        * /return *this
        * /throws std::invalid_argument 
        */
        SquareMatrix& operator=(const SquareMatrix& m);


        /**
        * Operator=
        * Assignment operator
        * /param SquareMatrix&& m
        * /return *this
        * /throws std::invalid_argument 
        */
        SquareMatrix& operator=(SquareMatrix&& m);


        /**
         * Operator+=
         * /param SquareMatrix& m
         * /return *this
         * /throws std::invalid_argument 
        */
        SquareMatrix& operator+=(const SquareMatrix& m);


        /**
         * Operator-=
         * /param SquareMatrix& m
         * /return *this
         * /throws std::invalid_argument 
        */
        SquareMatrix& operator-=(const SquareMatrix& m);


        /**
         * Operator*=
         * /param SquareMatrix& m
         * /return *this
         * /throws std::invalid_argument 
        */
        SquareMatrix& operator*=(const SquareMatrix& m);


        /**
         * Operator==
         * Equivilance operator
         * /param SquareMatrix& m
         * /return false or ture
         * /throws std::invalid_argument 
        */
        bool operator==(const SquareMatrix& m) const;


        /**
         * Operator==
         * Inequivilance operator
         * /param SquareMatrix& m
         * /return false or ture
         * /throws std::invalid_argument 
        */
        bool operator!=(const SquareMatrix& m) const;


        /**
         * Return tranpose of a square matrix
         * /param 
         * /return transpose
         * 
        */
        SquareMatrix transpose() const;


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
};
        SquareMatrix operator+(const SquareMatrix&, const SquareMatrix&);
        SquareMatrix operator-(const SquareMatrix&, const SquareMatrix&);
        SquareMatrix operator*(const SquareMatrix&, const SquareMatrix&);
        std::ostream& operator<<(std::ostream&, const SquareMatrix&);
#endif
