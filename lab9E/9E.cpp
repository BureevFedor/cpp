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
    ifstream fin("hamiltonian.in");
    ofstream fout("hamiltonian.out");

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

    /*for(int i = ans.size() - 1; i >= 0; i--)
        fout << ans[i] << ' ';
    fout << endl << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
            fout << arr[i][j] << ' ';
        fout << endl;
    }*/

    int b1 = 0;
    if(b == 0)
    {
        for(int i = ans.size() - 1; i > 0; i--)
        {
            for(int j = 0; j < arr[ans[i]].size(); j++)
            {
                if(b1 == 0)
                {
                    if(arr[ans[i]][j] == ans[i-1])
                        b1 = 1;
                }
            }

            if(b1 == 1)
                b1 = 0;
            else
                b = 1;
        }

        if(b == 0)
            fout << "YES";
        else
            fout << "NO";
    }
    else
        fout << "NO";

    return 0;
}



