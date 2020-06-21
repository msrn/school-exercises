#ifndef GREETER_H_INCLUDE
#define GREETER_H_INCLUDE
#include <string>
#include <vector>
#include <sstream>
class Greeter {

private:
    std::vector<std::string> greetings;
public:
    Greeter (const std::string&);
    void addGreet(const std::string&);
    std::string sayHello() const;
};
#endif
