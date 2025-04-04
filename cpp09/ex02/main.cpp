#include "PmergeMe.hpp"

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

    //^ 4: Generate the insertion sequence for followers
    std::vector<size_t> insertionSequence;
    size_t k = 1;
    while (k - 1 < followerInsertionOrder.size())
	{
        insertionSequence.push_back(k - 1); // Generate indices based on powers of 2
        k *= 2;
    }

    //^ 5: Insert followers into the sorted leaders based on the insertion sequence
    for (size_t i = 0; i < insertionSequence.size(); i++)
	{
        if (insertionSequence[i] < followerInsertionOrder.size())
		{
            std::vector<int>::iterator pos = std::lower_bound(
                sorted_leaders.begin(), sorted_leaders.end(), followerInsertionOrder[insertionSequence[i]]);
            sorted_leaders.insert(pos, followerInsertionOrder[insertionSequence[i]]);
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
    size_t k = 1;
    while (k - 1 < followerInsertionOrder.size())
	{
        insertionSequence.push_back(k - 1);
        k *= 2;
    }

    for (size_t i = 0; i < insertionSequence.size(); i++)
	{
        if (insertionSequence[i] < followerInsertionOrder.size())
		{
            std::deque<int>::iterator pos = std::lower_bound(
                sorted_leaders.begin(), sorted_leaders.end(), followerInsertionOrder[insertionSequence[i]]);
            sorted_leaders.insert(pos, followerInsertionOrder[insertionSequence[i]]);
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

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Format: ./PmergeMe 1 2 3 4 5" << std::endl;
		return 1;
	}

	clock_t start = clock();

	std::vector<int> vectorArr;
	for (int i = 1; i < ac; i++)
		vectorArr.push_back(std::atoi(av[i]));

	std::cout << "Before: ";
	for (size_t i = 0; i < 10; i++)
		std::cout << vectorArr[i] << " ";
	std::cout << "[...]" << std::endl;

	vectorMerge(vectorArr);

	std::cout << "After: ";
	for (size_t i = 0; i < 10; i++)
		std::cout << vectorArr[i] << " ";
	std::cout << "[...]" << std::endl;

	if (checkIfSorted(vectorArr))
		std::cout << "Sorted: Yes" << std::endl;
	else
		std::cout << "Sorted: No " << std::endl;

	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector: ";

	clock_t end = clock();
	double timeTaken = double(end - start) / CLOCKS_PER_SEC;
	std::cout << timeTaken << " seconds" << std::endl;
	
	
	start = clock();
	std::deque<int> dequeArr;
	for (int i = 1; i < ac; i++)
		dequeArr.push_back(std::atoi(av[i]));

	std::cout << "Before: ";
	for (size_t i = 0; i < 10; i++)
		std::cout << dequeArr[i] << " ";
	std::cout << "[...]" << std::endl;

	dequeMerge(dequeArr);

	std::cout << "After: ";
	for (size_t i = 0; i < 10; i++)
		std::cout << dequeArr[i] << " ";
	std::cout << "[...]" << std::endl;

	if (checkIfSorted(dequeArr))
		std::cout << "Sorted: Yes" << std::endl;
	else
		std::cout << "Sorted: No " << std::endl;

	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque: ";
	end = clock();
	timeTaken = double(end - start) / CLOCKS_PER_SEC;
	std::cout << timeTaken << " seconds" << std::endl;


	return 0;
}