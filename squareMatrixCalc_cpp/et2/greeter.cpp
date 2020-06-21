#include "greeter.h"

Greeter::Greeter(const std::string& str) {
    this->greetings = str;
}

std::string Greeter::sayHello() const{

    return this->greetings;
}
