#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void bfs(int a[][10],int n,int src,int vis[10])
{
    queue<int> Q;
    for (int i = 1; i <= n; i++)
        vis[i]=0;

    Q.push(src);
    vis[src]=1;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v]==1 && vis[v]==0)
            {
                Q.push(v);
                vis[v]=1;
            }
        }
        cout<<u<<" ";
    }
}

void dfs(int a[][10],int n,int src,int vis[10],int des)
{
    stack<int> s;
    for (int i = 1; i <= n; i++)
        vis[i]=0;

    s.push(src);
    vis[src]=1;

    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v]==1 && vis[v]==0)
            {
                s.push(v);
                vis[v]=1;
            }
        }
        cout<<u<<" ";
    }
}

int main()
{
    int n,m;
    cout<<"enter no. of vertices ";
    cin>>n;
    cout<<"enter no. of edges ";
    cin>>m;

    int a[10][10]={0};
    
    int s,d;
    for (int i = 1; i <= m; i++)
    {
        cout<<"enter source ";
        cin>>s;
        cout<<"enter destination ";
        cin>>d;
        a[s][d]=1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<a[i][j]<<"  ";
        }
        cout<<"\n";
    }
    
    int vis[10] = {0};




    
    
}