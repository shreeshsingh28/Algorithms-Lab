#include <bits/stdc++.h>
using namespace std;

void DFS(int src, int visited[], int n, int a[][10])
{
    stack<int> Q;
    visited[src] = 1;
    Q.push(src);
    cout << src << " ";

    while (!Q.empty())
    {
        int u = Q.top();
        Q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] == 1 && visited[v] == 0)
            {
                Q.push(v);
                visited[v] = 1;
                cout << v << " ";
            }
        }
    }
}

int main()
{
    int a[10][10], n, m, x, p, q;
    cout << "enter number of vertices- ";
    cin >> n;
    cout << "enter number of edges- ";
    cin >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << "enter source- ";
        cin >> p;
        cout << "enter destination- ";
        cin >> q;
        a[p][q] = 1;
        a[q][p]=1;
    }
    cout << "the matrix is- \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "enter starting vertex- ";
    int c;
    cin >> c;

    int visited[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    cout << "DFS- ";
    DFS(c, visited, n, a);
}
