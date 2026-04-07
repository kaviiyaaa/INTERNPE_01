#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int MIN = 1, MAX = 100, MAX_ATTEMPTS = 7;
    char playAgain = 'y';

    cout << "============================\n";
    cout << "   GUESS THE NUMBER GAME\n";
    cout << "============================\n";

    while (playAgain == 'y' || playAgain == 'Y') {
        int secret = rand() % MAX + MIN;
        int guess   = 0;
        int attempts = 0;
        int rangeLow = MIN, rangeHigh = MAX;
        bool won = false;

        cout << "\nI've picked a number between " << MIN << " and " << MAX << ".\n";
        cout << "You have " << MAX_ATTEMPTS << " attempts. Good luck!\n\n";

        while (attempts < MAX_ATTEMPTS) {
            cout << "Attempt " << (attempts + 1) << "/" << MAX_ATTEMPTS;
            cout << "  [Range: " << rangeLow << " - " << rangeHigh << "]\n";
            cout << "Your guess: ";

            // Input validation
            while (!(cin >> guess) || guess < MIN || guess > MAX) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter a number between "
                     << MIN << " and " << MAX << ": ";
            }

            attempts++;

            if (guess == secret) {
                cout << "\n*** Correct! The number was " << secret << ". ***\n";
                cout << "You got it in " << attempts
                     << " attempt" << (attempts > 1 ? "s" : "") << "!\n";
                won = true;
                break;
            } else if (guess < secret) {
                cout << "Too low!";
                rangeLow = guess + 1;
            } else {
                cout << "Too high!";
                rangeHigh = guess - 1;
            }

            int left = MAX_ATTEMPTS - attempts;
            if (left > 0)
                cout << " " << left << " attempt" << (left > 1 ? "s" : "") << " remaining.\n\n";
        }

        if (!won) {
            cout << "\nOut of attempts! The number was " << secret << ". Better luck next time!\n";
        }

        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nThanks for playing! Goodbye.\n";
    return 0;
}