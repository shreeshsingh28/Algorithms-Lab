#include <iostream>
using namespace std;

int weights[10]; // Weight of each item
int sol[10] = {0};    // Solution set
int n;           // Number of items
int capacity;    // Capacity of the knapsack
int best_size;  // Best value found so far
int selected[10] = {0};

void backtrack(int i, int current_size, int current_weight, int selected[])
{
    if (i == n)
    {
        if (current_size > best_size)
        {
            best_size = current_size;
            
            for (int j = 0; j < n; j++)
                sol[j] = selected[j];       // copy selected items to solution set
        }
        return;
    }
    if (current_weight + weights[i] <= capacity)
    {
        selected[i] = 1;             // mark current item as selected
        current_weight += weights[i];
        current_size++;

        backtrack(i + 1, current_size, current_weight, selected);         // 1 2 - call order

        selected[i] = 0;                // mark current item as not selected
        current_weight -= weights[i];
        current_size--;
    }
    backtrack(i + 1, current_size, current_weight, selected);             // 3 - call order
    return;
}

int main()
{
    cout<<"enter number of objects- ";
    cin>>n;

    cout<<"enter weight of objects- ";
    for (int i = 0; i < n; i++)
        cin>>weights[i];
    
    cout<<"enter capacity of container- ";
    cin>>capacity;
    
    best_size = 0;

    backtrack(0, 0, 0, selected);

    cout << "Solution set: ";
    for (int i = 0; i < n; i++)
        cout<<sol[i]<<" ";

    cout << "\nMaximum size: " << best_size;
    return 0;
}