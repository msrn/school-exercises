#include "greeter.h"

Greeter::Greeter(const std::string& str) {
    this->greetings.push_back(std::unique_ptr<std::string>(new std::string(str)));
}

Greeter::Greeter (const Greeter& other) {
    for (const auto& greet : other.greetings) {
        this->greetings.push_back(std::unique_ptr<std::string>(new std::string(*greet)));
    }
}

Greeter::Greeter (Greeter&& other) {
    this->greetings = std::move(other.greetings);
}


Greeter& Greeter::operator=(const Greeter& g) {
    if (this == &g) {
        return *this;
    }

    Greeter copy{g};
    std::swap(this->greetings, copy.greetings);
    return *this;
}
Greeter& Greeter::operator=(Greeter&& g) {
    if (this == &g) {
        return *this;
    }
    this->greetings = std::move(g.greetings);
    return *this;
}


void Greeter::addGreet(const std::string& g) {
    this->greetings.push_back(std::unique_ptr<std::string>(new std::string(g)));
}

std::string Greeter::sayHello() const{
    std::stringstream str;

    for(const auto & greet : this->greetings) {
        str << *greet;

        if (greet != greetings.back()) {
            str << "\n";
        }
    }

    return str.str();
}
