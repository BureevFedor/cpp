#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define MAX 30000

using namespace std;
int main()
{
    ifstream fin("pathbge1.in");
    ofstream fout("pathbge1.out");

    int n, m, i1, j1, v, w, cur = 0;
    fin >> n >> m;

    vector<int> arr[n];
    int used[n];
    int res[n];

    for (int i = 0; i < m; i++)
    {
        fin >> i1 >> j1;
        i1--;
        j1--;
        arr[i1].push_back(j1);
        arr[j1].push_back(i1);
    }

    for(int i = 0; i < n; i++)
    {
        res[i] = -1;
        used[i] = 0;
    }

    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < arr[i].size(); j++)
            fout << arr[i][j] << ' ';
        fout << endl;
    }
    fout << endl;*/

    queue <int> qu;
    qu.push(0);

    res[0] = 0;

    while (!qu.empty())
    {
        v = qu.front();
        qu.pop();

        used[v] = 1;
        if(v == 0)
            res[v] = 0;

        for(int i = 0; i < arr[v].size(); i++)
        {
            w = arr[v][i];

            if(used[w] == 0)
            {
                qu.push(w);
                used[w] = 1;
                res[w] = res[v] + 1;
                //fout << w << endl;
            }
        }

        /*fout << "used:" << endl;
        for(int i = 0; i < n; i++)
            fout << used[i] << ' ';
        fout << endl;

        fout << "res:" << endl;
        for(int i = 0; i < n; i++)
            fout << res[i] << ' ';
        fout << endl;*/
    }

    for(int i = 0; i < n; i++)
        fout << res[i] << ' ';
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}
