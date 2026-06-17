#include <iostream>
using namespace std;
int main()
{
    int score = 0;
    int answer;
    cout << "----- QUIZ GAME -----\n";
    cout << "\n1. What is the capital of India?\n";
    cout << "1) Mumbai  2) Delhi  3) Kolkata  4) Chennai\n";
    cout << "Enter answer: ";
    cin >> answer;
    if(answer == 2)
    {
        score++;
    }
    cout << "\n2. What is 2 + 2?\n";
    cout << "1) 3  2) 4  3) 5  4) 6\n";
    cout << "Enter answer: ";
    cin >> answer;
    if(answer == 2)
    {
        score++;
    }
    cout << "\n3. Which is a programming language?\n";
    cout << "1) HTML  2) CSS  3) C++  4) XML\n";
    cout << "Enter answer: ";
    cin >> answer;
    if(answer == 3)
    {
        score++;
    }
    cout << "\nYour Score = " << score << " out of 3";

    return 0;
}
