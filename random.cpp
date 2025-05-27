#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    int lowerBound, upperBound, secretNumber, guess;
    int maxAttempts, attempts;
    char playAgain;

    do {
        int difficulty;
        cout << "Choose your difficulty level (1- Easy, 2- Medium, 3- Hard): ";
        cin >> difficulty;

        // Set bounds and max attempts based on difficulty
        switch (difficulty) {
            case 1:
                lowerBound  = 1;   // Easy: Low range
                upperBound  = 10;  // Easy: High range
                maxAttempts = 5;   // Easy: Fewer attempts
                break;
            case 2:
                lowerBound = 1;    // Medium: Medium low
                upperBound = 50;   // Medium: Medium high
                maxAttempts = 7;   // Medium: More attempts than Easy
                break;
            case 3:
                lowerBound = 1;    // Hard: Lowest value
                upperBound = 100;  // Hard: Highest value
                maxAttempts = 10;  // Hard: Maximum attempts
                break;
            default:
                cout << "Invalid difficulty level! Setting to Easy." << endl;
                lowerBound = 1;
                upperBound = 10;
                maxAttempts = 5;
        }

        // Generate secret number between lowerBound and upperBound
        secretNumber = rand() % (upperBound - lowerBound + 1) + lowerBound;

        attempts = 0;
        bool hasGuessedCorrectly = false;

        cout << "I have selected a number between " << lowerBound << " and " << upperBound << ". You have " << maxAttempts << " attempts to guess it!" << endl;

        while (attempts < maxAttempts && !hasGuessedCorrectly) { // Loop condition
            cout << "Enter your guess: ";
            cin >> guess;

            // Add input validation for the guess
            if (cin.fail() || guess < lowerBound || guess > upperBound) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please guess a number between " << lowerBound << " and " << upperBound << "." << endl;
                continue;
            }

            attempts++;

            if (guess < secretNumber) {  // Too low
                cout << "Too low! Try again." << endl;
            } else if (guess > secretNumber) { // Too high
                cout << "Too high! Try again." << endl;
            } else {
                cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts!" << endl;
                hasGuessedCorrectly = true;
            }

            // Provide hints based on proximity
            if (!hasGuessedCorrectly && attempts < maxAttempts) {
                if (abs(guess - secretNumber) <= 10) {
                    cout << "You're very close!" << endl;
                } else if (abs(guess - secretNumber) <= 20) {
                    cout << "You're getting there!" << endl;
                }
            }
        }

        if (!hasGuessedCorrectly) {
            cout << "Sorry! You've used all your attempts. The correct number was " << secretNumber << "." << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!" << endl;

    return 0;
}