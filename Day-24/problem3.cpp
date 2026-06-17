#include <iostream>
using namespace std;
int main()
{
    char str[200];
    char word[50], longest[50];

    int i = 0, j = 0, maxLen = 0;
    cout << "Enter a sentence: ";
    cin.getline(str, 200);
    while(true)
    {
        if(str[i] != ' ' && str[i] != '\0')
        {
            word[j] = str[i];
            j++;
        }
        else
        {
            word[j] = '\0';

            if(j > maxLen)
            {
                maxLen = j;

                for(int k = 0; k <= j; k++)
                {
                    longest[k] = word[k];
                }
            }

            j = 0;
        }

        if(str[i] == '\0')
            break;

        i++;
    }

    cout << "Longest word = " << longest;

    return 0;
}
