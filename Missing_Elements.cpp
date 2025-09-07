#include<bits/stdc++.h>
using namespace std;
void findMissingCount()
{
    int N;
    cin >> N;
    unordered_set<int> elements;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        elements.insert(num);
    }

    int missingCount = 0;
    for (int i = 1; i <= N; i++)
    {
        if (elements.find(i) == elements.end())
        {
            missingCount++;
        }
    }

    cout << missingCount << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        findMissingCount();
    }

    return 0;
}
