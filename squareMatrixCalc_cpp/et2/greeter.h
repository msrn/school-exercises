#ifndef GREETER_H_INCLUDE
#define GREETER_H_INCLUDE
#include <string>
class Greeter {

private:
    std::string greetings;
public:
    Greeter (const std::string&);
    std::string sayHello() const;
};
#endif
