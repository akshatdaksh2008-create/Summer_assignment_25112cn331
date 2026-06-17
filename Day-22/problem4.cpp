#include <iostream>
using namespace std;
int main()
{
    char str[200], result[200];
    int j = 0;
    cout << "Enter a string: ";
    cin.getline(str, 200);
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ')
        {
            result[j] = str[i];
            j++;
        }
    }
    result[j] = '\0';
    cout << "String without spaces: " << result;
    return 0;
}
