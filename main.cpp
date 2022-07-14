#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int main(int argc, char **argv)
{
    int totalRuns = 1000;
    int survived = 0;

    int count = 100;
    std::vector<int> boxes(count);
    for (int i = 0; i < count; i++) {
        boxes[i] = i;
    }
    std::random_device device;
    std::mt19937 g(device());

    for (int i = 0; i < totalRuns; i++)
    {        
        std::shuffle(boxes.begin(), boxes.end(), g);

        bool success = true;
        for (int prisonerNumber = 0; prisonerNumber < count; prisonerNumber++) 
        {
            int opened = 0;
            int currentNumber = prisonerNumber;
            while (opened < 50)
            {
                currentNumber = boxes[currentNumber];
                if (currentNumber == prisonerNumber) {
                    break;
                }
                opened++;
            }
            success = currentNumber == prisonerNumber;
            if (!success) {
                break;
            }
        }
        if (success) {
            survived++;
        }
    }

    std::cout << survived << std::endl;
    return 0;
}
