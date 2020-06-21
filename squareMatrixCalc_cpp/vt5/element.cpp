#include "element.h"
#include <ostream>


/**
 * Operator<<
 * /param ostream, ConcreteSquareMatrix&
 * /return ostream
 */
std::ostream& operator<<(std::ostream& os, const Element& e) {

	os << e.toString();
	return os;

}