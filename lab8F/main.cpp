#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;
int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, i1, j1, iS, jS, iT, jT;
    fin >> n >> m;
    char c[n*m];

    vector<int> arr[n*m];
    vector<int> directions[n*m]; // все точки на пути к данной точке от начальной точки
    int used[n*m];
    int res[n*m]

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            used[i * m + j] = 0;
            res[i * m + j] = 0;

            fin >> c[i * m + j];

            if(c[i * m + j] == 'S')
            {
                iS = i;
                jS = j;
            }
            if(c[i * m + j] == 'T')
            {
                iT = i;
                jT = j;
            }

            if(c[i * m + j] == '.')
            {
                if((i == 0) && (j == 0))
                {
                    arr[0].push_back(1);
                    arr[1].push_back(0);

                    arr[0].push_back(m);
                    arr[m].push_back(0);
                }
                else if((i == n) && (j == 0))
                {
                    arr[n].push_back(1);
                    arr[1].push_back(n);

                    arr[0].push_back(n-1);
                    arr[n-1].push_back(0);
                }
                else if((i == 0) && (j == m))
                {
                    arr[n].push_back(1);
                    arr[1].push_back(n);

                    arr[0].push_back(n-1);
                    arr[n-1].push_back(0);
                }


            }

        }
    }








    /*for (int i = 0; i < m; i++)
    {
        fin >> i1 >> j1;
        i1--;
        j1--;
        arr[i1].push_back(j1);
        arr[j1].push_back(i1);
    }*/

    for(int i = 0; i < n*m; i++)
    {
        res[i] = -1;
        used[i] = 0;
    }

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
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            fout << res[i * n + j * m] << ' ';
        }
        fout << endl;
    }
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}
