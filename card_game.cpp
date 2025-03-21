#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Function to generate a random card suite
std::string randomcard_suite() {
    int number = rand() % 4 + 1;
    if (number == 1) return "Hearts";
    else if (number == 2) return "Diamonds";
    else if (number == 3) return "Clubs";
    else return "Spades";
}

// Function to generate a random card value
int randomcard_value() {
    return rand() % 13 + 2;
}

// Function to print the card name based on its value
void cardname(const std::string& suite, int value) {
    if (value < 11) std::cout << value << " of " << suite << "\n";
    else if (value == 14) std::cout << "Ace of " << suite << "\n";
    else if (value == 11) std::cout << "Jack of " << suite << "\n";
    else if (value == 12) std::cout << "Queen of " << suite << "\n";
    else if (value == 13) std::cout << "King of " << suite << "\n";
}

// Function to convert user input into a numerical answer
int answer(const std::string& guess) {
    return (guess == "yes") ? 1 : 0;
}

int main() {
    srand(time(0)); // Seed the random number generator
    bool game_on = true;
    
    while (game_on) {
        // First card generation and guessing
        int value_1 = randomcard_value();
        std::string guess_input;
        
        std::cout << "Guess if a card is an image card (yes/no)?\n";
        std::cin >> guess_input;
        int guess = answer(guess_input);
        
        if ((value_1 > 10 && guess == 1) || (value_1 < 11 && guess == 0)) {
            std::cout << "Correct!\n";
        } else {
            std::cout << "Game over.\n";
            break;
        }
        
        // Second card generation and comparison
        std::string suite_2 = randomcard_suite();
        int value_2 = randomcard_value();
        
        std::cout << "Guess if a card is strictly larger than the previous card (yes/no)?\n";
        std::cin >> guess_input;
        int guess_2 = answer(guess_input);
        
        if ((value_2 > value_1 && guess_2 == 1) || (value_2 <= value_1 && guess_2 == 0)) {
            std::cout << "Correct!\n";
        } else {
            std::cout << "Game over.\n";
            break;
        }
        
        // Third card generation and range checking
        std::string suite_3 = randomcard_suite();
        int value_3 = randomcard_value();
        
        std::cout << "Guess if a card is between the last cards (yes/no)?\n";
        std::cin >> guess_input;
        guess = answer(guess_input);
        
        if ((value_3 <= value_2 && value_3 >= value_1 && guess == 1) || 
            (value_3 > value_2 || value_3 < value_1) && guess == 0) {
            std::cout << "Correct!\n";
        } else {
            std::cout << "Game over!\n";
            break;
        }
        
        // Checking if the last card has the same suite as the one before it
        std::cout << "Guess if the last card has the same suit as the one before it (yes/no)?\n";
        std::cin >> guess_input;
        guess = answer(guess_input);
        
        if (guess == 1 && suite_3 == suite_2) {
            std::cout << "Correct! You passed the game!\n";
        } else {
            std::cout << "Game over!\n";
            break;
        }
        
        game_on = false; // End the game after one round
    }
    
    return 0;
}
