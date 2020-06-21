#ifndef GREET_H_INCLUDE
#define GREET_H_INCLUDE

#include <string>

class Greet {
	public:
		virtual ~Greet() = default;

		virtual std::string greet()const = 0;
};

class HelloGreet : public Greet {
	
	public:
		std::string greet() const {return "Hello";}
};

class MoroGreet : public Greet {
	
	public:
		std::string greet() const {return "Moro";};
};

#endif