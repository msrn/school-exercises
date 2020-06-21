/**
 * squarematrix.h
 */

#ifndef SQUAREMATRIX_H_INCLUDED
#define SQUAREMATRIX_H_INCLUDED

#include "intelement.h"
#include <ostream>
#include <vector>
/**
 * SquareMatrix class
 */
class SquareMatrix {

    private:
        int n;
        std::vector <std::vector <IntElement> >  elements;
    public:
        SquareMatrix()= default;
        SquareMatrix(const std::string& s);
        SquareMatrix(const SquareMatrix& m) = default;
        virtual ~SquareMatrix() = default;

        SquareMatrix& operator=(const SquareMatrix& m);
        SquareMatrix& operator+=(const SquareMatrix& m);
        SquareMatrix& operator-=(const SquareMatrix& m);
        SquareMatrix& operator*=(const SquareMatrix& m);
        bool operator==(const SquareMatrix& m) const;
        bool operator!=(const SquareMatrix& m) const;
        SquareMatrix transpose() const;

        void print(std::ostream& os) const;
        std::string toString() const;
};
        SquareMatrix operator+(const SquareMatrix&, const SquareMatrix&);
        SquareMatrix operator-(const SquareMatrix&, const SquareMatrix&);
        SquareMatrix operator*(const SquareMatrix&, const SquareMatrix&);
        std::ostream& operator<<(std::ostream&, const SquareMatrix&);
#endif
