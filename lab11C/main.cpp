#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;
#define MAXVAL 10001

int main()
{
    ifstream fin("pathbgep.in");
    ofstream fout("pathbgep.out");

    int n, m, i1, j1, c, v = 0;

    fin >> n >> m;

    int used[n], res[n];
    vector<int> arr[n], edges[n];
    int minidx, minidx_val;

    multiset <int> minvalues;
    int temp;

    for(int i = 0; i < n; i++)
        res[i] = -1;

    for(long i = 0; i < m; i++)
    {
        fin >> i1 >> j1 >> c;
        i1--;
        j1--;

        edges[i1].push_back(c);
        arr[i1].push_back(j1);

        edges[j1].push_back(c);
        arr[j1].push_back(i1);

        minvalues.insert(c);
    }

    res[0] = 0;

    while(v != -1)
    {
        used[v] = 1;

        for(int i = 0; i < arr[v].size(); i++)
        {
            int u = arr[v][i];
            int k = edges[v][i];

            if(res[u] != -1)
                res[u] = min(res[v] + k, res[u]);
            else
                res[u] = res[v] + k;

            if(used[u] != 2)
                used[u] = 1;
        }

        used[v] = 2;

        minidx = -1;
        minidx_val = MAXVAL;

        for(int i = 0; i < n; i++)
            if( (used[i] == 1) && (minidx_val >= res[i]) )
            {
                minidx = i;
                minidx_val = res[i];
            }

        v = (minidx != -1) ? minidx : -1;
    }

    for(int i = 0; i < n; i++)
        fout << res[i] << ' ';

    fin.close();
    fout.close();
    return 0;
}
