#include <bits/stdc++.h>
using namespace std;

int graph[10][10]; // Adjacency matrix to represent the graph
vector<int> bestPath;    // Vector to store the best path
int bestCost = INT_MAX;  // Variable to store the best cost
int src;

void tspBacktracking(int current, vector<int> &path, int visited[], int n, int cost)
{
    if (path.size() == n)
    {
        // Add the first vertex to complete the cycle
        path.push_back(src);
        cost += graph[current][src];

        // Update the best path and cost if a better solution is found
        if (cost < bestCost)
        {
            bestCost = cost;
            bestPath = path;
        }

        // Remove the added vertex to backtrack
        path.pop_back();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = 1;
            path.push_back(i);
            tspBacktracking(i, path, visited, n, cost + graph[current][i]);
            path.pop_back();
            visited[i] = 0;
        }
    }
}

int main()
{

    int n, m, p, q, cost;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        cout << "Enter source: ";
        cin >> p;
        cout << "Enter destination: ";
        cin >> q;
        cout << "Enter cost: ";
        cin >> cost;
        graph[p][q] = cost;
        graph[q][p] = cost;
    }

    vector<int> path;               // Vector to store the current path
    int visited[n] = {0}; // Vector to track visited vertices

    cout << "enter starting vertex- ";
    cin >> src;

    path.push_back(src); // Start from vertex 0
    visited[src] = 1; // Mark vertex 0 as visited

    tspBacktracking(src, path, visited, n, 0);

    cout << "Best path: ";
    for (int i = 0; i < bestPath.size(); i++)
    {
        cout << bestPath[i] << " ";
    }
    cout << endl;

    cout << "Best cost: " << bestCost << endl;

    return 0;
}