#include "concretematrix.h"


#include <sstream>
#include <iostream>
#include <iterator>


ConcreteSquareMatrix::ConcreteSquareMatrix() {
    this->n = 0;
}
/**
* Constructor
* Checks for string validity
* /param std::string& str_m
* /throws std::invalid_argument 
*/
ConcreteSquareMatrix::ConcreteSquareMatrix(const std::string& str_m) {
    std::stringstream input(str_m);

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

/**
* Copy constructor
* /param ConcreteSquareMatrix& m
*/
ConcreteSquareMatrix::ConcreteSquareMatrix(const ConcreteSquareMatrix& m) {
    this->n = m.n;
    
    for (const auto& row : m.elements) {
        this->elements.emplace_back();
        for (const auto& col : row) {
            this->elements.back().push_back(std::unique_ptr<IntElement>{new IntElement (*col)});
        }
    }
}

/**
* Move constructor
* /param ConcreteSquareMatrix& m
*/
ConcreteSquareMatrix::ConcreteSquareMatrix(ConcreteSquareMatrix&& m){
    this->n = m.n;
    this->elements = std::move(m.elements);
}

/**
* Operator=
* Copy assignment operator
* /param ConcreteSquareMatrix& m
* /return *this
* /throws std::invalid_argument 
*/
ConcreteSquareMatrix& ConcreteSquareMatrix::operator=(const ConcreteSquareMatrix& m) {
    

    if (this == &m) {
        return *this;
    }

    ConcreteSquareMatrix copy{m};
    std::swap(this->n, copy.n);
    std::swap(this->elements, copy.elements);
    return *this;

}

/**
* Operator=
* Move assignment operator
* /param ConcreteSquareMatrix&& m
* /return *this
* /throws std::invalid_argument 
*/
ConcreteSquareMatrix& ConcreteSquareMatrix::operator=(ConcreteSquareMatrix&& m)  {
    

    if (this == &m) {
        return *this;
    }

    this->n = m.n;
    this->elements = std::move(m.elements);
    return *this;
}

/**
 * Operator+=
 * /param ConcreteSquareMatrix& m
 * /return *this
 * /throws std::invalid_argument 
*/
ConcreteSquareMatrix& ConcreteSquareMatrix::operator+=(const ConcreteSquareMatrix& m) {
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

/**
 * Operator-=
 * /param ConcreteSquareMatrix& m
 * /return *this
 * /throws std::invalid_argument 
*/
ConcreteSquareMatrix& ConcreteSquareMatrix::operator-=(const ConcreteSquareMatrix& m) {
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


/**
 * Operator*=
 * /param ConcreteSquareMatrix& m
 * /return *this
 * /throws std::invalid_argument 
*/
ConcreteSquareMatrix& ConcreteSquareMatrix::operator*=(const ConcreteSquareMatrix& m) {
    if (this->n != m.n) {
        throw std::invalid_argument("Matrix differ in size");
    }

    ConcreteSquareMatrix temp{*this};
    ConcreteSquareMatrix mtrx = m.transpose();
  
     for(auto row = this->elements.begin(); row != this->elements.end(); row++){
       for(auto column = row->begin(); column != row->end(); column++){
         **column = IntElement{0};
         auto a = std::distance(this->elements.begin(), row);
         auto b = std::distance(row->begin(), column);
         for(int k = 0; k < n; k++){
               **column += *temp.elements[a][k] * *mtrx.elements[b][k]; 
           
         }
       }
     } 

       return *this;
  
}

/**
 * Operator==
 * Equivilance operator
 * /param ConcreteSquareMatrix& m
 * /return false or ture
 * /throws std::invalid_argument 
*/
bool ConcreteSquareMatrix::operator==(const ConcreteSquareMatrix& m) const {

    if (this->n != m.n) {
        return false;
    }

    if (m.toString() == this->toString()) {
        return true;
    }
    return false;
}



/**
 * Return tranpose of a square matrix
 * /param 
 * /return transpose
 * 
*/
ConcreteSquareMatrix ConcreteSquareMatrix::transpose() const {
    ConcreteSquareMatrix transpose{};

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

/**
 * Print ConcreteSquareMatrix
 * /param os
 */
 void ConcreteSquareMatrix::print(std::ostream& os) const{

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

 /**
  * Return ConcreteSquareMatrix string
  * /return String value
  */
 std::string ConcreteSquareMatrix::toString() const {
     std::stringstream strm;
     this->print(strm);
     return strm.str();
 }

 /**
  * Operator+
  * /param lhs, rhs
  * /return ConcreteSquareMatrix
  */
ConcreteSquareMatrix operator+(const ConcreteSquareMatrix& lhs, const ConcreteSquareMatrix& rhs) {
    ConcreteSquareMatrix sq{lhs};
    sq += rhs;
    return sq;
}

/**
 * Operator-
 * /param lhs, rhs
 * /return ConcreteSquareMatrix
 */
ConcreteSquareMatrix operator-(const ConcreteSquareMatrix& lhs, const ConcreteSquareMatrix& rhs) {

    ConcreteSquareMatrix sq{lhs};
    sq -= rhs;
    return sq;
}

/**
 * Operator*
 * /param lhs, rhs
 * /return ConcreteSquareMatrix
 */
ConcreteSquareMatrix operator*(const ConcreteSquareMatrix& lhs, const ConcreteSquareMatrix& rhs) {

    ConcreteSquareMatrix sq{lhs};
    sq *= rhs;
    return sq;
}

/**
 * Operator<<
 * /param ostream, ConcreteSquareMatrix&
 * /return ostream
 */
std::ostream& operator<<(std::ostream& os, const ConcreteSquareMatrix& m) {
    os << m.toString();
    return os;
} 