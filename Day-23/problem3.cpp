#include <iostream>
using namespace std;
int main()
{
    char str1[100], str2[100];
    int freq[256] = {0};
    bool isAnagram = true;

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);
    for(int i = 0; str1[i] != '\0'; i++)
    {
        freq[(int)str1[i]]++;
    }
    for(int i = 0; str2[i] != '\0'; i++)
    {
        freq[(int)str2[i]]--;
    }
    for(int i = 0; i < 256; i++)
    {
        if(freq[i] != 0)
        {
            isAnagram = false;
            break;
        }
    }

    if(isAnagram)
        cout << "Strings are Anagrams";
    else
        cout << "Strings are Not Anagrams";

    return 0;
}
