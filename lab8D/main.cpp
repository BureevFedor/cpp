#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000

int n, cnt;
vector<int> arr[MAX];
int used[MAX];
int res[MAX];

void dfs(int v)
{
    used[v] = 1;

    for(int i = 0; i < arr[v].size(); i++)
    {
        int u = arr[v][i];
        if (used[u] == 0)
        {
            res[u] = res[v];
            dfs(u);
        }
    }
}

int main(void)
{
    ifstream fin("components.in");
    ofstream fout("components.out");

    int m, i1, j1;
    fin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        res[i] = 0;
        used[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        fin >> i1 >> j1;
        i1--;
        j1--;
        arr[i1].push_back(j1);
        arr[j1].push_back(i1);
    }

    cnt = 1;

    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            fout << (*arr)[i][j] << ' ';
        fout << endl;
    }
    fout << endl;*/

    for(int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            res[i] = cnt;
            cnt++;
            dfs(i);
        }
    }

    fout << cnt - 1 << endl;
    for(int i = 0; i < n; i++)
        fout << res[i] << ' ';

    return 0;
}
