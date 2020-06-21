/**
 * SquareMatrix.cpp 
 */
#include "squarematrix.h"

#include <sstream>
#include <iostream>
#include <iterator>
/*
SquareMatrix::SquareMatrix() {
    this->n = 1;
}

/**
 * Contstructor
 * Checks for string validity
 * /param std::string& s
 * /throws std::invalid_argument 
 */

SquareMatrix::SquareMatrix(const std::string& s) {
    std::stringstream input(s);

    char c;
    int num;

    int temp = 0;
    int row = 0;
    int column;

    input >> c;
    if (!input.good() || c != '[') {
        throw std::invalid_argument("Not Valid SquareMatrix");
    }
    
    while (input.peek() != ']') {

        input >> c;
        if(!input.good() || c != '[') {
            throw std::invalid_argument("Not Valid SquareMatrix");
        }
        

        temp = 0;

        std::vector <IntElement> vRow;
        vRow.clear();

        while (c != ']') {

            input >> num;
            if (!input.good()) {
                throw std::invalid_argument("Not Valid SquareMatrix");

            }

            temp++;

            vRow.push_back(IntElement(num));

            input >> c;
            if (!input.good() || (c != ','&& c!=']')) {
                throw std::invalid_argument("Not Valid SquareMatrix");
            }

        }

        if (row == 0) { //jotta saataisiin selville sarakkaiden oikea määrä
            column = temp;
        }

        if (temp != column) { //jotta sarakkeita olisi aina tasamäärä
            throw std::invalid_argument("Not Valid SquareMatrix");
        }
        this->elements.push_back(vRow);

        row++;
        
    }
    
    input >> c;
    if (!input.good() || c != ']' || input.peek() != EOF) {
        throw std::invalid_argument("Not Valid SquareMatrix");
    }
   
    if (column != row) {
        throw std::invalid_argument("Not Valid SquareMatrix");
    }
    std::cout << "Annoit:" << column << " x " << row << std::endl;
    this->n = column;

}


/**
 * Operator=
 * /param SquareMatrix& m
 * /return *this
 * /throws std::invalid_argument 
*/
SquareMatrix& SquareMatrix::operator=(const SquareMatrix& m) {
    if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
    }

    this->n = m.n;
    this->elements = std::move(m.elements);
    return *this;
}




/**
 * Operator+=
 * /param SquareMatrix& m
 * /return *this
 * /throws std::invalid_argument 
*/
SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& m) {
    if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
    }

    int i = 0;
    int j = 0;

    for (auto& row : this->elements) {

        for(auto& col : row) {
            col = col + m.elements[i][j];
            j++;
        }
        i++;
        j = 0;
    }

    return *this;
}

/**
 * Operator-=
 * /param SquareMatrix& m
 * /return *this
 * /throws std::invalid_argument 
*/

SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& m) {
    if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
    }

    int i = 0;
    int j = 0;

    for (auto& row : this->elements) {

        for(auto& col : row) {
            col = col - m.elements[i][j];
            j++;
        }
        i++;
        j = 0;
    }
    return *this;
}

/**
 * Operator*-=
 * /param SquareMatrix& m
 * /return *this
 * /throws std::invalid_argument 
*/

SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& m) {
    if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
    }

    SquareMatrix temp{*this};
    SquareMatrix mtrx = m.transpose();
  
     for(auto row = this->elements.begin(); row != this->elements.end(); row++){
       for(auto column = row->begin(); column != row->end(); column++){
         *column = 0;
         auto a = std::distance(this->elements.begin(), row);
         auto b = std::distance(row->begin(), column);
         for(int k = 0; k < n; k++){
               *column += temp.elements[a][k] * mtrx.elements[b][k]; 
           
         }
       }
     } 

       return *this;
  
}

SquareMatrix SquareMatrix::transpose() const {
    SquareMatrix transpose{};

    transpose.n = n;
    transpose.elements = std::vector <std::vector <IntElement> > (this->n);

    for (auto row = this->elements.begin(); row != this->elements.end(); row++) {
          
        auto rows = transpose.elements.begin();

        for (auto col = row->begin(); col != row->end(); col++) {
            rows->push_back(*col);
            rows++;
        }

    }
  
    return transpose;
}

bool SquareMatrix::operator==(const SquareMatrix& m) const {

    if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
    }

    if (m.toString() == this->toString()) {
        return true;
    }
    return false;
}

bool SquareMatrix::operator!=(const SquareMatrix& m) const {

     if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
     }

    if (*this != m) {
        return true;
    }
    return false;
    }


/**
 * Print squarematrix
 * /param os
 */
void SquareMatrix::print(std::ostream& os) const{

    os << "[";
   
    for (auto& row : this->elements) {
        os << "[";

        for (auto&col: row) {
            os << col;
            if (&col != &(row.back())) {
                os << "," ;
            }
        }
        os << "]";
    }

    os << "]";
}

/**
 * Return Squarematrix string
 * /return String value
 */
std::string SquareMatrix::toString() const {
    std::stringstream strm;
    print(strm);
    return strm.str();
}

SquareMatrix operator+(const SquareMatrix& lhs, const SquareMatrix& rhs) {
    SquareMatrix sq{lhs};
    sq += rhs;
    return sq;
}


SquareMatrix operator-(const SquareMatrix& lhs, const SquareMatrix& rhs) {

    SquareMatrix sq{lhs};
    sq -= rhs;
    return sq;
}

SquareMatrix operator*(const SquareMatrix& lhs, const SquareMatrix& rhs) {

    SquareMatrix sq{lhs};
    sq *= rhs;
    return sq;
}

std::ostream& operator<<(std::ostream& os, const SquareMatrix& m) {
    os << m.toString();
    return os;
} 
