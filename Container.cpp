#include<bits/stdc++.h>
using namespace std;

class container
{
public :
    int weight;
    int id;
};

void sorting(container arr[],int n)
{
    int i,j,mini;
    for (i=0;i<n-1;i++)
    {
        mini=i;
        for (j=i+1;j<n;j++)
        {
            if (arr[j].weight < arr[mini].weight)
                mini=j;
        }
        if (mini!=i)
        {
            container temp=arr[i];
            arr[i]=arr[mini];
            arr[mini]=temp;
        }
    }
}

int main()
{
    cout<<"enter no. of objects- ";
    int ob;
    cin>>ob;
    container arr[ob];
    for (int i=0;i<ob;i++)
    {
        cout<<"enter weight- ";
        cin>>arr[i].weight;
        arr[i].id=i;
    }

    sorting(arr,ob);

    cout<<"id-weight (after sorting):\n";
    for (int i=0;i<ob;i++)
    {
        cout<<arr[i].id<<" - "<<arr[i].weight<<"\n";
    }
    cout<<"enter the capacity- ";
    int capacity;
    cin>>capacity;
    cout<<"selected ids are- ";

    cout<<endl;
    for (int i=0;i<ob;i++)
    {
        if (capacity >= arr[i].weight) {
            cout<<arr[i].id<<" ";
            capacity-=arr[i].weight;
        }
    }
    cout<<"\nCapacity Remaining : "<<capacity;

}
