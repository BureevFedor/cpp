#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define MAX 200000

int color[MAX]; // 0 - no color for now, 1 - color1, 2 - color2
vector<int> arr[MAX];
int b = 0;

void dfs (int v, int c)
{
    color[v] = c;

    for (int i = 0; i < arr[v].size(); ++i)
    {
        int to = arr[v][i];

        if (color[to] == 0)
        {
            if(c == 1)
                dfs(to, 2);
            else if (c == 2)
                dfs(to, 1);
        }
        else if(color[to] == c)
            b = 1;
    }
}

int main()
{
    ifstream fin("bipartite.in");
    ofstream fout("bipartite.out");

    int n, m, i1, j1;
    fin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        fin >> i1 >> j1;
        i1--;
        j1--;
        arr[i1].push_back(j1);
        arr[j1].push_back(i1);
    }

    for (int i = 0; i < n; i++)
        color[i] = 0;

    for (int i = 0; i < n; i++)
        if ((color[i] == 0) && (b == 0))
            dfs(i, 1);

    if(b == 0)
        fout << "YES";
    else if(b == 1)
        fout << "NO";

    return 0;
}
