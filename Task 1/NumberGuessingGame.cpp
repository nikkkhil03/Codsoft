#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Generate a random number between 1 and 100
    int rand_num = rand() % 100 + 1;

    // Initialize variables
    int num;
    int chances= 0;
    char try_again;

    do {
        // Welcome message
        cout << "Number Guessing Game by Nikhil " << endl;
        cout << "Guess any number between 1 and 100." << endl;
        chances = 0;

        while (true) {
            // Ask the user for a guess
            cout << "Guess any Number: ";
            cin >> num;

            // Increment the number of attempts
            chances++;

            // Check if the guess is correct
            if (num == rand_num) {
                cout << "Congratulations! You guessed the correct number  in " << chances << " chances." << endl;
                break;
            } else if (num < rand_num) {
                cout << "The number you guessed is less than the correct number,You can try again" << endl;
            } else {
                cout << "The number you guessed is more than the correct number,You can try again" << endl;
            }
        }

        // Ask if the user wants to play again
        cout << "Do you want to play the again? (y/n): ";
        cin >> try_again;

        // Generate a new random number for the next round
        rand_num = rand() % 100 + 1;
    } while (try_again == 'y' || try_again == 'Y');

    cout << "Thank you for playing the game" << endl;

    return 0;
}

