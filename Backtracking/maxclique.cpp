#include <iostream>
using namespace std;

int n;                  // number of vertices
int graph[10][10]; // adjacency matrix of the graph
int clique[10];       // solution maximum clique
int max_size = -1;        // size of current maximum clique

int is_clique(int nodes[], int size)        //checks graph in nodes complete or not
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0 ; j < size; j++)
        {
            if(i!=j && graph[nodes[i]][nodes[j]] != 1)
                return 0;
        }
    }
        return 1;  
}

void backtrack(int nodes[], int size, int pos)
{
    if (is_clique(nodes, size))
    {
        if (size > max_size)
        {
            max_size = size;
            for (int i = 0; i < size; i++)
                clique[i] = nodes[i];
        }
    }
    for (int i = pos; i < n; i++)
    {
        int is_adjacent = 1;
        for (int j = 0; j < size; j++)
        {
            if (!graph[nodes[j]][i])        //pos is adjacent to all the elements in nodes
            {
                is_adjacent = 0;
                break;
            }
        }
        if (is_adjacent)
        {
            nodes[size] = i;                        //if pos adja. added to nodes
            backtrack(nodes, size + 1, i + 1);      //size incremented, pos incremented
        }
    }
}

int main()
{
    int m, p, q;
    cout << "enter number of vertices- ";
    cin >> n;
    cout << "enter number of edges- ";
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << "enter source- ";
        cin >> p;
        cout << "enter destination- ";
        cin >> q;
        graph[p][q] = 1;
        graph[q][p] = 1;
    }

    int nodes[10];
    backtrack(nodes, 0, 0);

    cout << "Maximum clique: ";
    for (int i = 0; i < max_size; i++)
        cout << clique[i] << " ";
    cout << endl;
    cout<<"size- "<<max_size;

    return 0;
}
