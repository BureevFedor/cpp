#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define MAX 100000

vector<int> matrix[MAX];
int color[MAX];

void dfs(int v, int k)
{
    color[v] = 1;

    for (int i = 0; i < matrix[v].size(); i++)
    {
        int to = matrix[v][i];

        if (color[to] == 0)
            dfs(to, k);
        if ((k == 0) && (color[v] == 2))
            break;

        if(color[to] == 1)
            color[v] = 2;
        else
            color[v] = 1;
    }
}

int main( void )
{
    ifstream fin("game.in");
    ofstream fout("game.out");

    int n, m, f, i1, j1;
    fin >> n >> m >> f;
    f -= 1;

    for (int i = 0; i < m; i++)
    {
        fin >> i1 >> j1;
        i1--;
        j1--;
        matrix[i1].push_back(j1);
    }

    for (int i = 0; i < n; i++)
        color[i] = 0;

    dfs(f, 0);

    if (color[f] == 2)
        fout << "First player wins";
    else
        fout << "Second player wins";

    fin.close();
    fout.close();
}
