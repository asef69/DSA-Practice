#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == (size / 2) && j == (size / 2))
            {
                cout << "X";
            }
            else if (j == i)
            {
                cout << "\\";
            }
            else if (j == size - i - 1)
            {
                cout << "/";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}