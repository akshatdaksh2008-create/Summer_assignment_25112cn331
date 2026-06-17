#include <iostream>
using namespace std;
int main()
{
    char str1[100], str2[100];
    int freq1[256] = {0}, freq2[256] = {0};
    cout << "Enter first string: ";
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 100);
    for(int i = 0; str1[i] != '\0'; i++)
    {
        freq1[(int)str1[i]]++;
    }
    for(int i = 0; str2[i] != '\0'; i++)
    {
        freq2[(int)str2[i]]++;
    }
    cout << "Common characters: ";
    for(int i = 0; i < 256; i++)
    {
        if(freq1[i] > 0 && freq2[i] > 0)
        {
            cout << (char)i << " ";
        }
    }

    return 0;
}
