#include <iostream>  // for std::cout and std::cin
#include <cstdlib>   // For rand() and srand()
#include <ctime>
#include <string>

// Function to convert choice number to game value
std::string choiceToGameValue(int choice) {
    if (choice == 1) {
        return "rock";
    } else if (choice == 2) {
        return "paper";
    } else if (choice == 3) {
        return "scissors";
    }
    return "invalid";
}

int main()
{
    int choice{};
    std::string choiceOutput{};
    std::string oppOutput{};
    std::string result{};

    std::srand(std::time(0));
    int opponent = 1 + std::rand() % 3;

    std::cout << "Choose one\n";
    std::cout << "1. Rock\n2. Paper\n3. Scissors\n";
    std::cin >> choice;

    std::cout << "You entered " << choice << '\n';

    // Converts number choice to game value using function
    choiceOutput = choiceToGameValue(choice);
    if (choiceOutput == "invalid") {
        std::cout << "You didn't enter a valid input. Try Again!";
        return 1;
    }
    // Converts random number to game value using function
    oppOutput = choiceToGameValue(opponent);

    if (choice == opponent) {
        result = "It's a Tie!";
    } else if ((choice == 1 and opponent == 2) or (choice == 2 and opponent == 3) or (choice == 3 and opponent == 1)) {
        result = "You Lose!";
    } else {
        result = "You Win!";
    }

    std::cout << "You chose " << choiceOutput << ".\n";
    std::cout << "Computer chose " << oppOutput << ".\n";
    std::cout << result;

    return 0;
}
