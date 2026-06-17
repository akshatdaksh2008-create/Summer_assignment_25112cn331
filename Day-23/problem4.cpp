#include <iostream>
using namespace std;
int main()
{
    char str[200];
    int freq[256] = {0};

    cout << "Enter a string: ";
    cin.getline(str, 200);
    for(int i = 0; str[i] != '\0'; i++)
    {
        freq[(int)str[i]]++;
    }

    char maxChar = str[0];
    int maxCount = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(freq[(int)str[i]] > maxCount)
        {
            maxCount = freq[(int)str[i]];
            maxChar = str[i];
        }
    }

    cout << "Maximum occurring character = " << maxChar << endl;
    cout << "Frequency = " << maxCount;

    return 0;
}
