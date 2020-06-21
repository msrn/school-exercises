#ifndef SQUAREMATRIX_H_INCLUDED
#define SQUAREMATRIX_H_INCLUDED

#include "intelement.h"
#include <ostream>
/**
 * SquareMatrix class
 */
class SquareMatrix {

    private:
        IntElement e11;
        IntElement e12;
        IntElement e21;
        IntElement e22;
    public:
        SquareMatrix() = default;
        SquareMatrix(const IntElement& e11, const IntElement& e12, const IntElement& e21, const IntElement& e22);
        SquareMatrix(const SquareMatrix& m) = default;
        virtual ~SquareMatrix() = default;

        SquareMatrix& operator+=(const SquareMatrix& m);
        SquareMatrix& operator-=(const SquareMatrix& m);
        SquareMatrix& operator*=(const SquareMatrix& m);

        void print(std::ostream& os) const;
        std::string toString() const;
};

#endif
