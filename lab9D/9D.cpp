#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> g[20000], gr[20000];
vector<bool> used;
vector<int> tops, comp;

void dfs1 (int v)
{
    used[v] = true;

    for (size_t i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]])
            dfs1(g[v][i]);

    tops.push_back (v);
}

void dfs2 (int v)
{
    used[v] = true;

    comp.push_back (v);

    for (size_t i = 0; i < gr[v].size(); ++i)
        if (!used[gr[v][i]])
            dfs2 (gr[v][i]);
}

int main()
{
    ifstream fin("cond.in");
    ofstream fout("cond.out");

    int n, m, i, a, b, res[20000], num=1;
    fin >> n >> m;

    for (i = 0; i < m; i++)
    {
        fin >> a >> b;
        a -= 1;
        b -= 1;
        g[a].push_back (b);
        gr[b].push_back (a);
    }

    used.assign (n, false);
    for (i = 0; i < n; ++i)
        if (!used[i])
            dfs1 (i);

    used.assign (n, false);
    for (i = 0; i < n; ++i)
    {
        int v = tops[n - 1 - i];

        if (!used[v])
        {
            dfs2 (v);

            vector<int>::iterator I;
            for(I = comp.begin(); I != comp.end(); I++)
                res[*I]=num;
            num++;

            comp.clear();
        }
    }

    fout << num - 1 << endl;
    for(i = 0; i < n; i++)
        fout << res[i] << ' ';

    fin.close();
    fout.close();
    return 0;
}
