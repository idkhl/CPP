#include "PmergeMe.hpp"

void jacobsthalSequence(std::vector<size_t> &sequence, size_t limit)
{
    size_t j0 = 0, j1 = 1;
    sequence.push_back(j0);
    if (limit > 1)
        sequence.push_back(j1);

    while (true)
    {
        size_t next = j1 + 2 * j0;
        if (next >= limit)
            break;
        sequence.push_back(next);
        j0 = j1;
        j1 = next;
    }
}

void jacobsthalSequence(std::deque<size_t> &sequence, size_t limit)
{
    size_t j0 = 0, j1 = 1;
    sequence.push_back(j0);
    if (limit > 1)
        sequence.push_back(j1);

    while (true)
    {
        size_t next = j1 + 2 * j0;
        if (next >= limit)
            break;
        sequence.push_back(next);
        j0 = j1;
        j1 = next;
    }
}

void vectorMerge(std::vector<int> &arr)
{
    if (arr.size() < 2)
        return;

    //^ 1: Pair elements and sort each pair in descending order
    std::vector<std::pair<int, int> > pairs;
    int last_unpaired = -1;
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
        if (arr[i] < arr[i + 1])
            std::swap(arr[i], arr[i + 1]); // Ensure the first element is larger
        pairs.push_back(std::make_pair(arr[i], arr[i + 1])); // Store the pair
    }
    if (arr.size() % 2 != 0)
        last_unpaired = arr[arr.size() - 1]; // Handle the last unpaired element if the size is odd

    //^ 2: Extract the "leaders" (larger elements of each pair) and sort them
    std::vector<int> sorted_leaders;
    for (size_t i = 0; i < pairs.size(); i++)
        sorted_leaders.push_back(pairs[i].first);
    std::sort(sorted_leaders.begin(), sorted_leaders.end()); // Sort leaders in ascending order

    //^ 3: Extract the "followers" (smaller elements of each pair) in insertion order
    std::vector<int> followerInsertionOrder;
    for (size_t i = 0; i < pairs.size(); i++)
        followerInsertionOrder.push_back(pairs[i].second);

    //^ 4: Generate the insertion sequence for followers using Jacobsthal numbers
    std::vector<size_t> insertionSequence;
    jacobsthalSequence(insertionSequence, followerInsertionOrder.size());

    //^ 5: Insert followers into the sorted leaders based on the insertion sequence
    std::vector<bool> inserted(followerInsertionOrder.size(), false);
    for (size_t i = 0; i < insertionSequence.size(); i++)
    {
        size_t idx = insertionSequence[i];
        if (idx < followerInsertionOrder.size() && !inserted[idx])
        {
            std::vector<int>::iterator pos = std::lower_bound(
                sorted_leaders.begin(), sorted_leaders.end(), followerInsertionOrder[idx]);
            sorted_leaders.insert(pos, followerInsertionOrder[idx]);
            inserted[idx] = true;
        }
    }

    //Insert any remaining followers that weren't inserted via Jacobsthal
    for (size_t i = 0; i < followerInsertionOrder.size(); i++)
    {
        if (!inserted[i])
        {
            std::vector<int>::iterator pos = std::lower_bound(
                sorted_leaders.begin(), sorted_leaders.end(), followerInsertionOrder[i]);
            sorted_leaders.insert(pos, followerInsertionOrder[i]);
        }
    }

    //^ 6: Insert the last unpaired element (if any) into the sorted array
    if (last_unpaired != -1)
	{
        std::vector<int>::iterator pos = std::lower_bound(sorted_leaders.begin(), sorted_leaders.end(), last_unpaired);
        sorted_leaders.insert(pos, last_unpaired);
    }

    //^ 7: Update the original array with the sorted result
    arr = sorted_leaders;
}

void dequeMerge(std::deque<int> &arr)
{
	if (arr.size() < 2)
        return;

    std::deque<std::pair<int, int> > pairs;
    int last_unpaired = -1;
    for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
        if (arr[i] < arr[i + 1])
            std::swap(arr[i], arr[i + 1]);
        pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
    }
    if (arr.size() % 2 != 0)
        last_unpaired = arr[arr.size() - 1];

    std::deque<int> sorted_leaders;
    for (size_t i = 0; i < pairs.size(); i++)
        sorted_leaders.push_back(pairs[i].first);
    std::sort(sorted_leaders.begin(), sorted_leaders.end());

	std::deque<int> followerInsertionOrder;
    for (size_t i = 0; i < pairs.size(); i++)
        followerInsertionOrder.push_back(pairs[i].second);

    std::deque<size_t> insertionSequence;
    std::deque<size_t> tempSequence;
    jacobsthalSequence(tempSequence, followerInsertionOrder.size());
    insertionSequence.assign(tempSequence.begin(), tempSequence.end());

    std::deque<bool> inserted(followerInsertionOrder.size(), false);
    for (size_t i = 0; i < insertionSequence.size(); i++)
    {
        size_t idx = insertionSequence[i];
        if (idx < followerInsertionOrder.size() && !inserted[idx])
        {
            std::deque<int>::iterator pos = std::lower_bound(
                sorted_leaders.begin(), sorted_leaders.end(), followerInsertionOrder[idx]);
            sorted_leaders.insert(pos, followerInsertionOrder[idx]);
            inserted[idx] = true;
        }
    }

    for (size_t i = 0; i < followerInsertionOrder.size(); i++)
    {
        if (!inserted[i])
        {
            std::deque<int>::iterator pos = std::lower_bound(
                sorted_leaders.begin(), sorted_leaders.end(), followerInsertionOrder[i]);
            sorted_leaders.insert(pos, followerInsertionOrder[i]);
        }
    }

    if (last_unpaired != -1)
	{
        std::deque<int>::iterator pos = std::lower_bound(sorted_leaders.begin(), sorted_leaders.end(), last_unpaired);
        sorted_leaders.insert(pos, last_unpaired);
    }

    arr = sorted_leaders;
}

bool checkIfSorted(const std::deque<int> &arr)
{
	for (size_t i = 1; i < arr.size(); i++)
	{
		if (arr[i] < arr[i - 1])
			return false;
	}
	return true;
}

bool checkIfSorted(const std::vector<int> &arr)
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
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); ++i)
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
        if (!isValidNumber(av[i]))
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        long val = std::atol(av[i]);
        if (val < 0 || val > INT_MAX)
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        numbers.push_back(static_cast<int>(val));
    }
    return numbers;
}


int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> input = parseArguments(ac, av);

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

    return 0;
}
