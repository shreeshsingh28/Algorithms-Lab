#include<iostream>
#include<queue>
using namespace std;

void BFS(int v,int visited[],int n,int a[][10])
{
    queue<int> Q;
    visited[v]=1;
    Q.push(v);
    cout<<v<<" ";

    while(!Q.empty())
    {
        int w;
        w=Q.front();
        Q.pop();
        for(int u=1;u<=n;u++)
        {
            if(a[w][u]==1 && visited[u]==0)
            {
                Q.push(u);
                visited[u]=1;
                cout<<u<<" ";
            }
        }
    }
}

int main()
{
    int a[10][10],n,m,x,p,q;
    cout<<"enter number of vertices- ";
    cin>>n;
    cout<<"enter number of edges- ";
    cin>>m;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<"enter source- ";
        cin>>p;
        cout<<"enter destination- ";
        cin>>q;
        a[p][q]=1;
        //a[q][p]=1;
    }
    cout<<"the matrix is- \n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<"enter starting vertex- ";
    int c;
    cin>>c;

    int visited[n+1];
    for(int i=1;i<=n;i++)
        visited[i]=0;

    cout<<"BFS- ";
    BFS(c,visited,n,a);

}
