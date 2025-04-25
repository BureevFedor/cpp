#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    long long from, to, length;
};

int main()
{
    //ifstream fin("cycle.in");
    //ofstream fout("cycle.out");
    ifstream fin("pathmgep.in");
    ofstream fout("pathmgep.out");

    long long n, m, len, x = -1, a, b;

    fin >> n >> m;

    vector<edge> matrix;
    long long res[n], parent[n];
    vector<int> path;

    for(int i = 0; i < n; i++)
    {
        res[i] = 1000000000;
        parent[i] = -1;
    }

    for (int j = 0; j < m; j++)
    {
        fin >> a >> b;
        matrix.push_back({a, b, 1});
    }

    res[0] = 0;

    for (int i = 0; i < n; i++)
    {
        x = -1;

        for (auto & j : matrix)
        {
            if (res[j.from] + j.length < res[j.to])
            {
                res[j.to] = res[j.from] + j.length;
                parent[j.to] = j.from;

                if (i == n - 1)
                    x = j.to;
            }
        }
    }

    if (x != -1)
    {
        fout << "YES" << endl;

        int y = x;
        for (int i = 0; i < n; ++i)
            y = parent[y];

        int cur = y;

        while( (cur != y) || (path.size() <= 1) )
        {
            path.push_back(cur);
            cur = parent[cur];
        }

        path.push_back(y);

        reverse(path.begin(), path.end());

        fout << path.size() << endl;
        for (int i = 0; i < path.size(); ++i)
            fout << path[i] + 1 << ' ';
    }
    else
        fout << "NO" << endl;

    fin.close();
    fout.close();
    return 0;
}
