#ifndef GREETER_H_INCLUDE
#define GREETER_H_INCLUDE
#include <string>
#include <vector>
#include <sstream>
#include <memory>
class Greeter {

private:
    std::vector<std::unique_ptr<std::string>> greetings;
public:
    Greeter (const std::string&);
    Greeter (const Greeter&);
    Greeter (Greeter&&);
    virtual ~Greeter() = default;

    Greeter& operator=(const Greeter&);
    Greeter& operator=(Greeter&&);

    void addGreet(const std::string&);
    std::string sayHello() const;
};
#endif
