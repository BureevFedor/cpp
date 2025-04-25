#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000

struct edge
{
	int l;
	int r;
	int length;
};

bool compare(edge a, edge b)
{
	return a.length < b.length;
}

int main()
{
    ifstream fin("spantree3.in");
    ofstream fout("spantree3.out");

	int n, m;
	fin >> n >> m;

	vector<edge> arr(m);
	vector<int> visited(n);

    for (int i = 0; i < m; i++)
		fin >> arr[i].l >> arr[i].r >> arr[i].length;

	sort(arr.begin(), arr.end(), compare);

	int weight = 0;

	for (int i = 0; i < m; i++)
	{
		if ((visited[arr[i].l] == 0) || (visited[arr[i].r] == 0))
		{
			weight += arr[i].length;
			visited[arr[i].l] = 1;
			visited[arr[i].r] = 1;
		}
	}

	fout << weight << endl;
}
