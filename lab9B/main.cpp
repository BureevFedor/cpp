#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
using namespace std;
#define MAX 100000

int color[MAX], parent[MAX], start_node, end_node;
vector<int> arr[MAX], cycle;

void dfs(int v)
{
	color[v] = 1;

	for (int i = 0; i < arr[v].size(); i++)
    {
        int u = arr[v][i];

		if (color[u] == 0)
		{
			parent[u] = v;
			dfs(u);
		}
		else if (color[u] == 1)
		{
			start_node = u;
			end_node = v;
        }
	}

	color[v] = 2;
}

int main()
{
    ifstream fin("cycle.in");
    ofstream fout("cycle.out");

    int n, m, i1, j1;
    fin >> n >> m;

    for (int i = 0; i < m; i++)
    {
		fin >> i1 >> j1;
		i1 -= 1;
		j1 -= 1;
		arr[i1].push_back(j1);
	}

    dfs(0);

	if (start_node == -1)
        fout << "NO";
	else
	{
		for (int i = end_node; i != start_node; i = parent[i])
        	cycle.push_back(i);

		cycle.push_back(start_node);

        if(cycle.size() == 1)
            fout << "NO" << endl;
        else
        {
            fout << "YES" << endl;
            for(int i = cycle.size() - 1; i >= 0; i--)
                fout << cycle[i] + 1 << ' ';
        }
	}

    fin.close();
    fout.close();

    return 0;
}
