#include "PmergeMe.hpp"

template <typename Container>
void jacobsthalSequence(Container &sequence, size_t limit)
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
    std::vector<int> followers;
    for (size_t i = 0; i < pairs.size(); i++)
        followers.push_back(pairs[i].second);

    //^ 4: Generate the insertion sequence for followers using Jacobsthal numbers
    std::vector<size_t> insertionSequence;
    jacobsthalSequence(insertionSequence, followers.size());

    //^ 5: Insert followers into the sorted leaders based on the insertion sequence
    std::vector<bool> inserted(followers.size(), false);
    for (size_t i = 0; i < insertionSequence.size(); i++)
    {
        size_t idx = insertionSequence[i];
        if (idx < followers.size() && !inserted[idx])
        {
            std::vector<int>::iterator pos = std::lower_bound(
                sorted_leaders.begin(), sorted_leaders.end(), followers[idx]);
            sorted_leaders.insert(pos, followers[idx]);
            inserted[idx] = true;
        }
    }

    //^ 6: Insert any remaining followers that weren't inserted via Jacobsthal
    for (size_t i = 0; i < followers.size(); i++)
    {
        if (!inserted[i])
        {
            std::vector<int>::iterator pos = std::lower_bound(
                sorted_leaders.begin(), sorted_leaders.end(), followers[i]);
            sorted_leaders.insert(pos, followers[i]);
        }
    }

    //^ 7: Insert the last unpaired element (if any) into the sorted array
    if (last_unpaired != -1)
	{
        std::vector<int>::iterator pos = std::lower_bound(sorted_leaders.begin(), sorted_leaders.end(), last_unpaired);
        sorted_leaders.insert(pos, last_unpaired);
    }

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

	std::deque<int> followers;
    for (size_t i = 0; i < pairs.size(); i++)
        followers.push_back(pairs[i].second);

    std::deque<size_t> insertionSequence;
    std::deque<size_t> tempSequence;
    jacobsthalSequence(tempSequence, followers.size());
    insertionSequence.assign(tempSequence.begin(), tempSequence.end());

    std::deque<bool> inserted(followers.size(), false);
    for (size_t i = 0; i < insertionSequence.size(); i++)
    {
        size_t idx = insertionSequence[i];
        if (idx < followers.size() && !inserted[idx])
        {
            std::deque<int>::iterator pos = std::lower_bound(
                sorted_leaders.begin(), sorted_leaders.end(), followers[idx]);
            sorted_leaders.insert(pos, followers[idx]);
            inserted[idx] = true;
        }
    }

    for (size_t i = 0; i < followers.size(); i++)
    {
        if (!inserted[i])
        {
            std::deque<int>::iterator pos = std::lower_bound(
                sorted_leaders.begin(), sorted_leaders.end(), followers[i]);
            sorted_leaders.insert(pos, followers[i]);
        }
    }

    if (last_unpaired != -1)
	{
        std::deque<int>::iterator pos = std::lower_bound(sorted_leaders.begin(), sorted_leaders.end(), last_unpaired);
        sorted_leaders.insert(pos, last_unpaired);
    }

    arr = sorted_leaders;
}