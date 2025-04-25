#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;
#define MAX 9999999

struct point
{
    int x;
    int y;
};

int n, used[MAX];
long double result = 0, k, res[MAX];
point arr[MAX];
vector<int> avv[MAX];

void dfs (int v)
{
    used[v] = 1;

    for(int i = 0; i < avv[v].size(); i++)
    {
        int u = avv[v][i];
        k = sqrt( pow((arr[v].x - arr[u].x), 2) + pow((arr[v].y - arr[u].y), 2) );

        if(res[u] > k)
            res[u] = k;

        if (used[u] == 0)
            dfs (u);
    }

    used[v] = 2;
}

int main()
{
    ifstream fin("spantree.in");
    ofstream fout("spantree.out");

    setprecision(10);

    fin >> n;

    for (int i = 0; i < n; i++)
    {
        fin >> arr[i].x >> arr[i].y;

        res[i] = MAX;
        used[i] = 0;

        for(int j = 0; j < n; j++)
            if(i != j)
                avv[i].push_back(j);
    }

    res[0] = 0;
    dfs(0);

    for(int i = 0; i < n; i++)
    {
        //fout << res[i] << endl;
        result += res[i];
    }

    fout << fixed << result << setprecision(10);

    fin.close();
    fout.close();
}
