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

bool isValidDate(const std::string& date);
bool isValidValue(const std::string& value);
std::string trim(const std::string& str);
void BitcoinExchange(std::ifstream &file, std::ifstream &dataBase);

#endif