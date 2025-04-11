#include "PmergeMe.hpp"

template <typename Container>
bool checkIfSorted(const Container &arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}

bool isValidNumber(const std::string& str)
{
    if (str.empty() || (str[0] == '-' && str.length() == 1))
        return false;
    for (size_t i = (str[0] == '-' ? 1 : 0); i < str.length(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

std::vector<int> parseArguments(int ac, char **av)
{
    std::vector<int> numbers;
    for (int i = 1; i < ac; ++i)
    {
        std::istringstream iss(av[i]);
        std::string token;
        while (std::getline(iss, token, ' '))
        {
            if (token.empty())
                continue;
            if (!isValidNumber(token))
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
            long val = std::atol(token.c_str());
            if (val < 0 || val > INT_MAX)
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
            numbers.push_back(static_cast<int>(val));
        }
    }
    return numbers;
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: no input" << std::endl;
        return 1;
    }

    std::vector<int> input = parseArguments(ac, av);
    if (input.empty())
    {
        std::cerr << "Error: no input" << std::endl;
        return 1;
    }

    std::cout << std::setw(8) << "Before: ";
    for (size_t i = 0; i < input.size() && i < 10; ++i)
        std::cout << std::setw(6) << input[i] << " ";
    if (input.size() > 10) std::cout << "[...]";
    std::cout << std::endl;

    std::vector<int> vectorArr = input;
    clock_t start = clock();
    vectorMerge(vectorArr);
    clock_t end = clock();
    double timeVector = double(end - start) / CLOCKS_PER_SEC;

    std::cout << std::setw(8) << "After: ";
    for (size_t i = 0; i < vectorArr.size() && i < 10; ++i)
        std::cout << std::setw(6) << vectorArr[i] << " ";
    if (vectorArr.size() > 10) std::cout << "[...]";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << input.size()
            << " elements with std::vector: "
            << std::fixed << std::setprecision(5)
            << (timeVector * 1e6) / 1000 << " ms" << std::endl;

    std::deque<int> dequeArr(input.begin(), input.end());
    start = clock();
    dequeMerge(dequeArr);
    end = clock();
    double timeDeque = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << input.size()
            << " elements with std::deque: "
            << std::fixed << std::setprecision(5)
            << (timeDeque * 1e6) / 1000 << " ms" << std::endl;

    std::cout << "Vector sorted: " << checkIfSorted(vectorArr) << std::endl;
    std::cout << "Deque sorted: " << checkIfSorted(dequeArr) << std::endl;

    return 0;
}
