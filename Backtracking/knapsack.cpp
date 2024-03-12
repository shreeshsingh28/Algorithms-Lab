#include <iostream>
using namespace std;

int profit[10];  // Value of each item
int weights[10]; // Weight of each item
int sol[10] = {0};    // Solution set
int n;           // Number of items
int capacity;    // Capacity of the knapsack
int best_value;  // Best value found so far
int selected[10] = {0};

void backtrack(int i, int current_profit, int current_weight, int selected[])
{
    if (i == n)
    {
        if (current_profit > best_value)
        {
            best_value = current_profit;
            
            for (int j = 0; j < n; j++)
                sol[j] = selected[j];       // copy selected items to solution set
        }
        return;
    }
    if (current_weight + weights[i] <= capacity)
    {
        selected[i] = 1;             // mark current item as selected
        current_weight += weights[i];
        current_profit += profit[i];

        backtrack(i + 1, current_profit, current_weight, selected);         // 1 2 - call order

        selected[i] = 0;                // mark current item as not selected
        current_weight -= weights[i];
        current_profit -= profit[i];
    }
    backtrack(i + 1, current_profit, current_weight, selected);             // 3 - call order
    return;
}

int main()
{
    n = 3;
    profit[0] = 9;
    profit[1] = 7;
    profit[2] = 10;
    weights[0] = 3;
    weights[1] = 5;
    weights[2] = 2;
    capacity = 8;
    best_value = 0;

    backtrack(0, 0, 0, selected);

    cout << "Solution set: ";
    for (int i = 0; i < n; i++)
        cout<<sol[i]<<" ";

    cout << "\nMaximum value: " << best_value;
    return 0;
}