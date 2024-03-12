#include <bits/stdc++.h>
using namespace std;

bool isValidEdge(int u, int v, vector<bool> inMST)
{
    if (u == v)
        return false;
    if (inMST[u] == false && inMST[v] == false)
        return false;
    else if (inMST[u] == true && inMST[v] == true)
        return false;
    return true;
}

void primMST(int cost[][10], int n)
{
    vector<bool> inMST(n, false);
    inMST[0] = true;

    int edge_count = 0, mincost = 0;
    while (edge_count < n - 1)
    {

        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < min && isValidEdge(i, j, inMST))
                {
                        min = cost[i][j];
                        a = i;
                        b = j;
                }
            }
        }
        if (a != -1 && b != -1)
        {
            printf("Edge %d:(%d, %d) cost: %d \n",
                   edge_count++, a, b, min);
            mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }
    }
    cout << "\n Minimum cost= " << mincost;
}

int main()
{
    cout << "count 0 as vertex\n";
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    int cost[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cost[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cout << "Enter the source vertex, destination vertex, and weight of edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        cost[u][v] = w;
        cost[v][u] = w;
    }

    primMST(cost, n);

    return 0;
}