#ifndef SQUAREMATRIX_H_INCLUDED
#define SQUAREMATRIX_H_INCLUDED

#include "intelement.h"
#include <ostream>
#include <vector>
#include <string>
/**
 * SquareMatrix class
 */
class SquareMatrix {

    private:
        int n;
        std::vector<std::vector<IntElement>> elements;
    public:
        SquareMatrix() = default;
        SquareMatrix(const std::string& s);
        SquareMatrix(const SquareMatrix& m) = default;
        virtual ~SquareMatrix() = default;

        SquareMatrix transpose();
        SquareMatrix& operator=(const SquareMatrix& m);
        SquareMatrix& operator+=(const SquareMatrix& m);
        SquareMatrix& operator-=(const SquareMatrix& m);
        SquareMatrix& operator*=(const SquareMatrix& m);
        bool operator==(const SquareMatrix& m);
        void print(std::ostream& os) const;
        std::string toString() const;
};

#endif
