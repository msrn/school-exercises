#include "greeter.h"

Greeter::Greeter(Greet* g) {
    this->greetings.push_back(std::unique_ptr<Greet>(g));
}


void Greeter::addGreet(Greet* g) {
    this->greetings.push_back(std::unique_ptr<Greet>(g));
}

std::string Greeter::sayHello() const{
    std::stringstream str;

    for(const auto & greet : this->greetings) {
        str << greet->greet();

        if (greet != greetings.back()) {
            str << "\n";
        }
    }

    return str.str();
}
