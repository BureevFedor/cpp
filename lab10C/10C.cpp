#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;
 
struct edge
{
    edge(int l, int r, int w) : l(l), r(r), len(w) {};
 
    int l;
    int r;
    int len;
};
 
int find_set(vector<int>& parent, int v)
{
    if (v == parent[v])
        return v;
 
    return parent[v] = find_set(parent, parent[v]);
}
 
bool compare(edge a, edge b)
{
    return a.len < b.len;
}
 
int main()
{
    ifstream fin ("spantree3.in");
    ofstream fout ("spantree3.out");
 
    int n, m;
    int i1, j1, length;
    long long weight = 0;
 
    fin >> n >> m;
 
    vector<edge> edges;
    vector<int> parent(n);
 
    for (int i = 0; i < m; i++)
    {
        fin >> i1 >> j1 >> length;
        i1 -= 1;
        j1 -= 1;
        edges.push_back(edge(i1, j1, length));
    }
 
    sort(edges.begin(), edges.end(), compare);
 
    for (int i = 0; i < n; i++)
        parent[i] = i;
 
    for (int i = 0; i < m; i++)
    {
        if (find_set(parent, edges[i].l) != find_set(parent, edges[i].r))
        {
            weight += edges[i].len;
 
            edges[i].l = find_set(parent, edges[i].l);
            edges[i].r = find_set(parent, edges[i].r);
 
            if (edges[i].l != edges[i].r)
                parent[edges[i].l] = edges[i].r;
        }
    }
 
    fout << weight << endl;
 
    fin.close();
    fout.close();
    return 0;
}