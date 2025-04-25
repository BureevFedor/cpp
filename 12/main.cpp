#include <iostream>
#include <fstream>
using namespace std;

int A[15][15];

void mark(int x, int y, int n, int m)
{
    A[x][y]++;

    if((x+2 <= n-1) && (y-1 >= 0))
        mark(x+2, y-1, n, m);
    if((x+2 <= n-1) && (y+1 <= m-1))
        mark(x+2, y+1, n, m);
    if((x+1 <= n-1) && (y+2 <= m-1))
        mark(x+1, y+2, n, m);
    if((x-1 >= 0) && (y+2 <= m-1))
        mark(x-1, y+2, n, m);
}


int main()
{
    ifstream fin("knight2.in");
    ofstream fout("knight2.out");

    int n, m;
    fin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            A[i][j] = 0;

    mark(0, 0, n, m);

    /*for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout << A[i][j] << ' ';
        cout << endl;
    }*/

    fout << A[n-1][m-1];

    fin.close();
    fout.close();
    return 0;
}
