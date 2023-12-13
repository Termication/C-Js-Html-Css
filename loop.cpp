#include <iostream>

int main()
{
    srand(time(NULL));

    int num = (rand() % 35) + 1;

    std::cout << num;
}