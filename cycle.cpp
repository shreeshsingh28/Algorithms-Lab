#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int adjMatrix[MAXN][MAXN]; // adjacency matrix
int visited[MAXN];         // visited array to keep track of visited nodes

bool DFS(int u, int parent, int N)
{
    visited[u] = 1;
    for (int v = 0; v < N; v++)
    {
        if (adjMatrix[u][v])
        { // there's an edge between u and v
            if (!visited[v])
            { // if v is not visited yet
                if (DFS(v, u, N))
                {                // call DFS on v and its parent is u
                    return true; // if cycle found, return true
                }
            }
            else if (v != parent)
            {                // if v is visited but not the parent of u
                return true; // cycle found, return true
            }
        }
    }
    return false; // no cycle found
}

bool hasCycle(int N)
{
    for (int i = 0; i < N; i++)
        visited[i] = 0; // initialize visited array to 0

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        { // if i is not visited yet
            if (DFS(i, -1, N))
            {                // call DFS on i with parent -1
                return true; // if cycle found, return true
            }
        }
    }
    return false; // no cycle found
}

int main()
{
    int N, m, x, p, q;
    cout << "enter number of vertices- ";
    cin >> N;
    cout << "enter number of edges- ";
    cin >> m;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << "enter source- ";
        cin >> p;
        cout << "enter destination- ";
        cin >> q;
        adjMatrix[p][q] = 1;
        // a[q][p]=1;
    }
    if (hasCycle(N))
    {
        cout << "The graph has a cycle" << endl;
    }
    else
    {
        cout << "The graph does not have a cycle" << endl;
    }
    return 0;
}
