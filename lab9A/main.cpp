#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define MAX 100000

int used[MAX];
vector<int> arr[MAX];
vector<int> ans;
int b = 0;

void dfs (int v)
{
	used[v] = 1;
	for (int i = 0; i < arr[v].size(); ++i)
    {
		int to = arr[v][i];

		if (used[to] == 0)
			dfs (to);
        else if(used[to] == 1)
            b = 1;
    }

    used[v] = 2;
	ans.push_back (v);
}

int main()
{
    ifstream fin("topsort.in");
    ofstream fout("topsort.out");

    int n, m, i1, j1;
    fin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        fin >> i1 >> j1;
        i1--;
        j1--;
        arr[i1].push_back(j1);
    }

    for (int i = 0; i < n; i++)
        used[i] = 0;

    for (int i = 0; i < n; i++)
        if (used[i] == 0)
            dfs(i);

    if(b == 0)
    {
        for(int i = ans.size() - 1; i >= 0; i--)
            fout << ans[i]+1 << ' ';
    }
    else
        fout << "-1";

    return 0;
}
