#include <iostream>
using namespace std;
int main()
{
    char str[200], result[200];
    int freq[256] = {0};
    int j = 0;
    cout << "Enter a string: ";
    cin.getline(str, 200);
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(freq[(int)str[i]] == 0)
        {
            result[j] = str[i];
            j++;
            freq[(int)str[i]] = 1;
        }
    }
    result[j] = '\0';
    cout << "String after removing duplicates: " << result;
    return 0;
}
