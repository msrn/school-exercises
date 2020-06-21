#include "symbolicmatrix.h"

#include <sstream>
#include <iostream>
#include <iterator>
#include <cctype>

/**
 * Constructor initialize n
 */
SymbolicSquareMatrix::SymbolicSquareMatrix() {
	this->n = 0;
}


/**
* Constructor
* Checks for string validity
* /param std::string& str_m
* /throws std::invalid_argument 
*/
SymbolicSquareMatrix::SymbolicSquareMatrix(const std::string& str_m) {
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
        std::vector <std::unique_ptr<Element>> vRow;

        while (c != ']') {

        	if (std::isalpha(input.peek())) {
        		input >> c;
        		vRow.push_back(std::unique_ptr<Element>(new VariableElement {c}));
        	} else {
        		input >> num;

        		if (!input.good()) {
        		   throw std::invalid_argument("Not Valid SquareMatrix");

        		}
        		vRow.push_back(std::unique_ptr<Element>(new IntElement {num}));

        	}
           
            temp++;

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
* /param SymbolicSquareMatrix& m
*/
SymbolicSquareMatrix::SymbolicSquareMatrix(const SymbolicSquareMatrix& m) {
    this->n = m.n;
    
    for (const auto& row : m.elements) {
        this->elements.emplace_back();
        for (const auto& col : row) {
            this->elements.back().push_back(std::unique_ptr<Element>{col->clone()});
        }
    }
}
/**
* Move constructor
* /param SymbolicSquareMatrix& m
*/
SymbolicSquareMatrix::SymbolicSquareMatrix(SymbolicSquareMatrix&& m){
    this->n = m.n;
    this->elements = std::move(m.elements);
}

/**
* Operator=
* Copy assignment operator
* /param SymbolicSquareMatrix& m
* /return *this
* /throws std::invalid_argument 
*/
SymbolicSquareMatrix& SymbolicSquareMatrix::operator=(const SymbolicSquareMatrix& m) {   

    if (this == &m) {
        return *this;
    }

    SymbolicSquareMatrix copy{m};
    std::swap(this->n, copy.n);
    std::swap(this->elements, copy.elements);
    return *this;

}

/**
* Operator=
* Move Assignment operator
* /param SymbolicSquareMatrix&& m
* /return *this
* /throws std::invalid_argument 
*/
SymbolicSquareMatrix& SymbolicSquareMatrix::operator=(SymbolicSquareMatrix&& m)  {


    if (this == &m) {
        return *this;
    }

    this->n = m.n;
    this->elements = std::move(m.elements);
    return *this;
}

/**
 * Operator==
 * Equivilance operator
 * /param SymbolicSquareMatrix& m
 * /return false or ture
 * /throws std::invalid_argument 
*/
bool SymbolicSquareMatrix::operator==(const SymbolicSquareMatrix& m) const {

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
SymbolicSquareMatrix SymbolicSquareMatrix::transpose() const {
    SymbolicSquareMatrix transpose{};

    transpose.n = n;
    transpose.elements = std::vector <std::vector <std::unique_ptr<Element>> > (this->n);

    for (const auto& row : this->elements) {
          
        auto rows = transpose.elements.begin();

        for (auto& col : row) {
            rows->push_back(std::unique_ptr<Element>{col->clone()});
            rows++;
        }

    }
  
    return transpose;
}

/**
 * Print squarematrix
 * /param os
 */
void SymbolicSquareMatrix::print(std::ostream& os) const{

    os << "[";
   
    for (auto& row : this->elements) {
        os << "[";

        for (auto&col: row) {
            os << col->toString();
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
std::string SymbolicSquareMatrix::toString() const {
    std::stringstream strm;
    print(strm);
    return strm.str();
}

/**
 * Evaluate objectg
 * /param String value
 * /return ConcreteSquareMatrix
 */
ConcreteSquareMatrix SymbolicSquareMatrix::evaluate(const Valuation& val) const {

	std::stringstream strm;
	strm << "[";
   
    for (auto& row : this->elements) {
        strm << "[";

        for (auto&col: row) {
            strm << col->evaluate(val);
            if (col != row.back()) {
                strm << "," ;
            }
        }
        strm << "]";
    }

    strm << "]";

    return ConcreteSquareMatrix{strm.str()};

}

/**
 * operator<<
 * /param std::ostream&,SymbolicSquareMatrix&
 * /return ostream
 */
std::ostream& operator<<(std::ostream& os, const SymbolicSquareMatrix& m) {

    os << m.toString();
    return os;

}
