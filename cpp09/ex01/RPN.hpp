#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>
#include <limits>

class RPN {
public:
    static double evaluate(const std::string& expression);
};

#endif