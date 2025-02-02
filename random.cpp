#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main()
{
    // Create a vector representing 52 items
    std::vector<int> items(52);
    for (int i = 0; i < 52; ++i)
    {
        items[i] = i + 1; // Items numbered 1 to 52
    }

    // Initialize random device and generator
    std::random_device rd;  // Seed for randomness
    std::mt19937 gen(rd()); // Mersenne Twister random number generator

    // Shuffle the vector
    std::shuffle(items.begin(), items.end(), gen);

    // Print the shuffled items
    std::cout << "Shuffled order: ";
    for (int item : items)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}
