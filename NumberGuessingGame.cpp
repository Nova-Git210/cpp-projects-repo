#include<iostream> 
#include<ctime>
using namespace std;

int main() {
    char response;

    do {
        int num;
        int guess;
        int tries = 0;

        srand(time(NULL));
        num = (rand() % 100) + 1;

        // Game Title
        cout << "\n========================================\n";
        cout << "     WELCOME TO NUMBER GUESSING GAME\n";
        cout << "========================================\n\n";
        cout << "INSTRUCTIONS:\n";
        cout << "- Guess the number between 1 and 100.\n";
        cout << "- You will get hints whether it's too high or too low.\n\n";
        cout << " Let's begin! \n";
        cout << "----------------------------------------\n";

        // Game Loop
        do {
            cout << "\nEnter your guess (1-100): ";
            cin >> guess;
            tries++;

            if (guess > num) {
              cout << "Too High! Try a smaller number.\n";
            }
            else if (guess < num) {                
              cout << "Too Low! Try a bigger number.\n";
            }
            else {
                cout << "\n CORRECT!!  You guessed it in " << tries << " tries!\n";
            }

        } while (guess != num);

        // Result Message
        cout << "\n----------------------------------------\n";
        if (tries <= 5) {
            cout << " Excellent! You have a sharp guessing ability!\n";
        } else if (tries <= 10) {
            cout << " Good job! That was fun, right?\n";
        } else {
            cout << " Finally! That was tough, huh?\n";
        }

        cout << "Thanks for playing the Number Guessing Game! \n";
        cout << "========================================\n";

        // If the user wants to play again
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> response;

        if (response == 'N' || response == 'n') {
            cout << "\nThen we will see you soon!\n";
        }

    } while (response == 'Y' || response == 'y');

    return 0;
}
