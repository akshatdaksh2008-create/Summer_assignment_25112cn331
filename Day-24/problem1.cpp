#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[100], str2[100], temp[200];

    cin.getline(str1, 100);
    cin.getline(str2, 100);

    if(strlen(str1) != strlen(str2))
    {
        cout << "Not Rotation";
        return 0;
    }

    strcpy(temp, str1);
    strcat(temp, str1);

    if(strstr(temp, str2) != NULL)
        cout << "Rotation";
    else
        cout << "Not Rotation";

    return 0;
}
