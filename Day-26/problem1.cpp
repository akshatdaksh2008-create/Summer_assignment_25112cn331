#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int number, guess;
    srand(time(0));
    number = rand() % 100 + 1;
    cout << "Guess the number (1 to 100):\n";
    while(true)
    {
        cin >> guess;
        if(guess > number)
        {
            cout << "Too high, try again: ";
        }
        else if(guess < number)
        {
            cout << "Too low, try again: ";
        }
        else
        {
            cout << "Correct! You guessed it.";
            break;
        }
    }

    return 0;
}
