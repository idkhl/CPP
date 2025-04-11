#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <ctime>
#include <climits>
#include <sstream>

template <typename Container>
void jacobsthalSequence(Container &sequence, size_t limit);

void vectorMerge(std::vector<int> &arr);
void dequeMerge(std::deque<int> &arr);


#endif