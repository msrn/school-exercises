#ifndef GREETER_H_INCLUDE
#define GREETER_H_INCLUDE
#include "greet.h"
#include <string>
#include <vector>
#include <sstream>
#include <memory>
class Greeter {

private:
    std::vector<std::unique_ptr<Greet>> greetings;
public:
    Greeter (Greet* g);

    virtual ~Greeter() = default;

    void addGreet(Greet* g);
    std::string sayHello() const;
};
#endif
