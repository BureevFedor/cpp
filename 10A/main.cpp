#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100000

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, i1, j1;
    fin >> n >> m;
    int arr[n];

    for(int i = 0; i < n; i++)
        arr[i] = 0;

    for (int i = 0; i < m; i++)
    {
        fin >> i1 >> j1;
        arr[i1-1]++;
        arr[j1-1]++;
    }

    for(int i = 0; i < n; i++)
        fout << arr[i] << ' ';

    fin.close();
    fout.close();
}
