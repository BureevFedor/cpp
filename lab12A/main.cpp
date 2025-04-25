#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long n;

    cin >> n;

    long arr[n], d[n], parent[n];
    vector<long> res;

    for (long i = 0; i < n; ++i)
    {
        cin >> arr[i];
        d[i] = 1;
        parent[i] = -1;
    }

    for (long i = 0; i < n; ++i)
    {
        for (long j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])
            {
                if (1 + d[j] > d[i])
                {
                    d[i] = 1 + d[j];
                    parent[i] = j;
                }
            }
        }
    }

    long len = d[0], pos = 0;

    for (long i = 0; i < n; ++i)
        if (d[i] > len)
        {
            len = d[i];
            pos = i;
        }

    cout << len << endl;

    while (pos != -1)
    {
        res.push_back(pos);
        pos = parent[pos];
    }

    reverse (res.begin(), res.end());

    for(long i = 0; i < res.size(); ++i)
        cout << arr[res[i]] << ' ';

    return 0;
}
