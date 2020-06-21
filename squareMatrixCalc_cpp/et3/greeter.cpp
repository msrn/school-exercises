#include "greeter.h"

Greeter::Greeter(const std::string& str) : greetings{str} {}


void Greeter::addGreet(const std::string& g) {
    this->greetings.push_back(g);
}

std::string Greeter::sayHello() const{
    std::stringstream str;
    std::vector<std::string>::const_iterator it;

    for(it = std::begin(greetings); it !=std::end(greetings); it++) {
        str << (*it);

        if (*it != greetings.back()) {
            str << "\n";
        }
    }

    return str.str();
}
