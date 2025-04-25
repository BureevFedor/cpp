#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> ans;
int A[300][300];
int w[10000];

void findAns(int k, int s)
{
    if (A[k][s] == 0)
        return;

    if (A[k - 1][s] == A[k][s])
        findAns(k - 1, s);
    else
    {
        findAns(k - 1, s - w[k]);
        ans.push_back(k);
    }
}

int main()
{
    ifstream fin("knapsack.in");
    ofstream fout("knapsack.out");

    int S, n;

    fin >> S >> n;

    int p[n];

    for(int i = 0; i < S; i++)
        A[0][i] = 0;

    for(int i = 0; i < n; i++)
    {
        A[i][0] = 0;
        fin >> p[i];
        w[i] = p[i];
    }

    /*fout << S << ' ' << n << ' ';
    for(int i = 0; i < n; i++)
        fout << w[i] << ' ' << p[i] << ' ';
    fout << endl;*/

    for(int k = 1; k < n; k++)
    {
        for(int s = 1; s < S; s++)
        {
            if (s >= w[k])
                A[k][s] = max(A[k - 1][s], A[k - 1][s - w[k]] + p[k]);
            else
                A[k][s] = A[k - 1][s];
        }
    }

    findAns(n, S);

    for(int i = 0; i < ans.size(); i++)
        fout << ans[i] << ' ';
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}


/*for i = 0 to w
  A[0][i] = 0
for i = 0 to n
  A[i][0] = 0                                               //Первые элементы приравниваем к 0
for k = 1 to n
  for s = 1 to w                                            //Перебираем для каждого k все вместимости
    if s >= w[k]                                            //Если текущий предмет вмещается в рюкзак
      A[k][s] = max(A[k - 1][s], A[k - 1][s - w[k]] + p[k]) //Выбираем класть его или нет
    else
      A[k][s] = A[k - 1][s]                                 //Иначе, не кладем
      */
