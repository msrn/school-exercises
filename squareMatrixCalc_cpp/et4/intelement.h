#ifndef INTELEMENT_H_INCLUDED
#define INTELEMENT_H_INCLUDED 

#include <ostream>

/**
 * IntElement class
 */
class IntElement {

    private:
        int val;
    public:
        IntElement() = default;
        IntElement(int v);
        virtual ~IntElement() = default;

        int getVal() const { return this->val; }
        void setVal(int v) { this->val = v; }

        IntElement& operator+=(const IntElement& i);
        IntElement& operator-=(const IntElement& i);
        IntElement& operator*=(const IntElement& i);
        bool operator==(const IntElement& i);
};

IntElement operator+(const IntElement&, const IntElement&);
IntElement operator-(const IntElement&, const IntElement&);
IntElement operator*(const IntElement&, const IntElement&);
std::ostream& operator<<(std::ostream&, const IntElement&); 

#endif
