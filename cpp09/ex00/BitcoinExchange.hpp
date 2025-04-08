#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <algorithm>
#include <cctype>

// Explanation: std::map is used because it provides efficient key-based lookup
// and maintains the keys in sorted order, which is essential for finding the closest lower date.

bool isValidDate(const std::string& date);
bool isValidValue(const std::string& value);
std::string trim(const std::string& str);

#endif