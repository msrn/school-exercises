/**
 * SquareMatrix.cpp 
 */
#include "squarematrix.h"

#include <sstream>
#include <iostream>
#include <iterator>

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

        std::vector <std::unique_ptr<IntElement>> vRow;
        vRow.clear();

        while (c != ']') {

            input >> num;
            if (!input.good()) {
                throw std::invalid_argument("Not Valid SquareMatrix");

            }

            temp++;

            vRow.push_back(std::unique_ptr<IntElement>(new IntElement {num}));

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
        this->elements.push_back(std::move(vRow));

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


SquareMatrix::SquareMatrix(const SquareMatrix& m) {
    this->n = m.n;
    
    for (const auto& row : m.elements) {
        this->elements.emplace_back();
        for (const auto& col : row) {
            this->elements.back().push_back(std::unique_ptr<IntElement>{new IntElement (*col)});
        }
    }
}


SquareMatrix::SquareMatrix(SquareMatrix&& m){
    this->n = m.n;
    this->elements = std::move(m.elements);
}


SquareMatrix& SquareMatrix::operator=(const SquareMatrix& m) {
    if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
    }

    if (this == &m) {
        return *this;
    }

    SquareMatrix copy{m};
    std::swap(this->n, copy.n);
    std::swap(this->elements, copy.elements);
    return *this;

}


SquareMatrix& SquareMatrix::operator=(SquareMatrix&& m)  {
    if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
    }

    if (this == &m) {
        return *this;
    }

    this->n = m.n;
    this->elements = std::move(m.elements);
    return *this;
}


SquareMatrix& SquareMatrix::operator+=(const SquareMatrix& m) {
    if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
    }

    int i = 0;
    int j = 0;

    for (auto& row : this->elements) {

        for(auto& col : row) {
            *col = *col + *m.elements[i][j];
            j++;
        }
        i++;
        j = 0;
    }

    return *this;
}


SquareMatrix& SquareMatrix::operator-=(const SquareMatrix& m) {
    if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
    }

    int i = 0;
    int j = 0;

    for (auto& row : this->elements) {

        for(auto& col : row) {
            *col = *col - *m.elements[i][j];
            j++;
        }
        i++;
        j = 0;
    }
    return *this;
}



SquareMatrix& SquareMatrix::operator*=(const SquareMatrix& m) {
    if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
    }

    SquareMatrix temp{*this};
    SquareMatrix mtrx = m.transpose();
  
     for(auto row = this->elements.begin(); row != this->elements.end(); row++){
       for(auto column = row->begin(); column != row->end(); column++){
         **column = 0;
         auto a = std::distance(this->elements.begin(), row);
         auto b = std::distance(row->begin(), column);
         for(int k = 0; k < n; k++){
               **column += *temp.elements[a][k] * *mtrx.elements[b][k]; 
           
         }
       }
     } 

       return *this;
  
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


SquareMatrix SquareMatrix::transpose() const {
    SquareMatrix transpose{};

    transpose.n = n;
    transpose.elements = std::vector <std::vector <std::unique_ptr<IntElement>> > (this->n);

    for (const auto& row : this->elements) {
          
        auto rows = transpose.elements.begin();

        for (auto& col : row) {
            rows->push_back(std::unique_ptr<IntElement>{new IntElement (*col)});
            rows++;
        }

    }
  
    return transpose;
}


void SquareMatrix::print(std::ostream& os) const{

    os << "[";
   
    for (auto& row : this->elements) {
        os << "[";

        for (auto&col: row) {
            os << *col;
            if (&col != &(row.back())) {
                os << "," ;
            }
        }
        os << "]";
    }

    os << "]";
}


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
