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
/**
 * Operator==
 * /param const Element&
 * /return boolean
 */
bool operator==(const Element& lhs, const Element& rhs) {
	if (lhs.toString() == rhs.toString()) {
		return true;
	}
	return false;
}