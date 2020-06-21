#include <string>
#include <sstream>
#include <iostream>
#include "issqmatrix.h"

bool isSquareMatrix(const std::string& string) {
    std::stringstream input(string);

    char c;
    int num;

    int temp = 0;
    int row = 0;
    int column;

    input >> c;
    if (!input.good() || c != '[') {
        return false;
    }
    //std::cout << "rivi 19" << std::endl;
    
    while (input.peek() != ']') {

       //std::cout << "rivi 23" << std::endl;
        input >> c;
        if(!input.good() || c != '[') {
            return false;
        }

        temp = 0;
        //std::cout << "rivi 27" << std::endl;

        while (c != ']') {

            input >> num;
            if (!input.good()) {
                return false;
            }

            temp++;
            //std::cout << "rivi 38" << std::endl;

            input >> c;
            if (!input.good() || (c != ','&& c!=']')) {
                return false;
            }

            //std::cout << "rivi 45" << std::endl;

        }

        if (row == 0) { //jotta saataisiin selville sarakkaiden oikea määrä
            column = temp;
        }

        if (temp != column) { //jotta sarakkeita olisi aina tasamäärä
            return false;
        }

        row++;
        
    }

    //std::cout << "rivi 56" << std::endl;
    
    //katsotaan onko merkkijono varmasti lopussa
    input >> c;
    if (!input.good() || c != ']' || input.peek() != EOF) {
        return false;
    }
   
    //std::cout << "rivi 62" << std::endl;
    if (column != row) {
        return false;
    }
    std::cout << "Annoit:" << column << " x " << row << std::endl;

    return true;


}




