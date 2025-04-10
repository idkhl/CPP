#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <limits>

class RPN {
public:
    static double calc(const std::string& expression);
};

#endif