#include <iostream>
using namespace std;

const int maxi = 1e9;

void dijkstra(int graph[][100], int n, int src)
{
    int dist[n];
    bool visited[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = maxi;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int u = -1;                 // index of min dis[] element
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    cout << "Shortest distance from source " << src << " to all vertices:\n";
    for (int i = 0; i < n; i++)
    {
        cout << i << " : " << dist[i] << "\n";
    }
}

int main()
{
    cout << "count 0 as vertex\n";
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    int graph[100][100] = {0};

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cout << "Enter the source vertex, destination vertex, and weight of edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        graph[u][v] = w;
        // graph[v][u] = w;
    }

    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    dijkstra(graph, n, src);
}
