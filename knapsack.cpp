#include<bits/stdc++.h>
using namespace std;

class product
{
public :
    int weight;
    int profit;
    int id;
    long pdensity;
};

void sorting(product arr[],int n,int choice)
{
    int i,j,mini;
    for (i=0;i<n-1;i++)
    {
        mini=i;
        for (j=i+1;j<n;j++)
        {
            if (choice==1) {
                if (arr[j].weight < arr[mini].weight)
                mini=j;
            }
            else if (choice==2)
            {
                if (arr[j].profit > arr[mini].profit)
                mini=j;
            }
            else
            {
                if (arr[j].pdensity > arr[mini].pdensity)
                mini=j;
            }
        }
        if (mini!=i)
        {
            product temp=arr[i];
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
    product arr[ob];
    for (int i=0;i<ob;i++)
    {
        cout<<"enter weight- ";
        cin>>arr[i].weight;
        cout<<"enter profit- ";
        cin>>arr[i].profit;
        arr[i].id=i;
        arr[i].pdensity=arr[i].profit/arr[i].weight;
    }
    sorting(arr,ob,1);

    cout<<"id - profit - weight - profit density (after sorting):\n";

    for (int i=0;i<ob;i++)
    {
        cout<<arr[i].id<<" - "<<arr[i].weight<<" - "<<arr[i].profit<<" - "<<arr[i].pdensity<<"\n";
    }
    cout<<"enter capacity";
    int capacity;
    cin>>capacity;

    vector<int> v1(ob),v2(ob),v3(ob);
    int p1=0,p2=0,p3=0;

    for (int i=0;i<ob;i++)
    {
        if (capacity >= arr[i].weight) {
            cout<<arr[i].id<<" ";
            capacity-=arr[i].weight;
            v1[arr[i].id]=1;
            p1+=arr[i].profit;
        }
        else
        {
            v1[arr[i].id]=0;
        }
    }
    cout<<endl<<"For weight minimum : ";
    for (int i=0;i<ob;i++)
        cout<<v1[i]<<" ";
    cout<<"     PROFIT : "<<p1<<endl;

    cout<<"enter capacity";
    cin>>capacity;

    sorting(arr,ob,2);
    for (int i=0;i<ob;i++)
    {
        cout<<arr[i].id<<" - "<<arr[i].weight<<" - "<<arr[i].profit<<" - "<<arr[i].pdensity<<"\n";
    }

    for (int i=0;i<ob;i++)
    {
        if (capacity >= arr[i].weight) {
            cout<<arr[i].id<<" ";
            capacity-=arr[i].weight;
            v2[arr[i].id]=1;
            p2+=arr[i].profit;
        }
        else
        {
            v2[arr[i].id]=0;
        }
    }
    cout<<endl<<"For profit maximum : ";
    for (int i=0;i<ob;i++)
        cout<<v2[i]<<" ";
    cout<<"     PROFIT : "<<p2<<endl;

    cout<<"enter capacity";
    cin>>capacity;

    sorting(arr,ob,3);
    for (int i=0;i<ob;i++)
    {
        cout<<arr[i].id<<" - "<<arr[i].weight<<" - "<<arr[i].profit<<" - "<<arr[i].pdensity<<"\n";
    }

    for (int i=0;i<ob;i++)
    {
        if (capacity >= arr[i].weight) {
            cout<<arr[i].id<<" ";
            capacity-=arr[i].weight;
            v3[arr[i].id]=1;
            p3+=arr[i].profit;
        }
        else
        {
            v3[arr[i].id]=0;
        }
    }
    cout<<endl<<"For profit density maximum : ";
    for (int i=0;i<ob;i++)
        cout<<v3[i]<<" ";
    cout<<"     PROFIT : "<<p3<<endl;

}
