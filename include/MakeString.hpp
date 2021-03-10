#ifndef MAKESTRING_HPP
#define MAKESTRING_HPP

#include <sstream>
#include <string>

class MakeString {
    public:
        template<class T>
        MakeString & operator << (const T & arg) {
            ss << arg;
            return *this;
        }

        operator std::string() const {
            return ss.str();
        }
    protected:
        std::stringstream ss;
};

#endif
