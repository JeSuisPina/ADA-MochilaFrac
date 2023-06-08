// C++ program to solve fractional Knapsack Problem

#include <iostream>
#include <algorithm>
using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
struct Item {
    int profit, weight;

    // Constructor
    Item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

// Comparison function to sort Item
// according to profit/weight ratio
static bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N, int& finalWeight)
{
    // Sorting Item on basis of ratio
    sort(arr, arr + N, cmp);

    double finalValue = 0.0;
    finalWeight = 0;

    // Looping through all items
    for (int i = 0; i < N; i++) {

        // If adding Item won't overflow,
        // add it completely
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].profit;
            finalWeight += arr[i].weight;
        }

        // If we can't add current Item,
        // add fractional part of it
        else {
            finalValue += arr[i].profit * ((double)W / (double)arr[i].weight);
            finalWeight += W;
            break;
        }
    }

    // Returning final value
    return finalValue;
}

// Driver code
int main()
{
    int W = 50, W1 = 70, W2 = 100, W3 = 10;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	Item arr1[] = { { 60, 10 }, { 100, 20 }, { 120, 30 }, { 80, 15 }, { 200, 35 } };
	Item arr2[] = { { 70, 25 }, { 50, 15 }, { 200, 30 }, { 90, 20 }, { 120, 40 }, { 150, 35 } };
	Item arr3[] = { { 30, 7 }, { 20, 5 }, { 25, 4 } };

    int N = sizeof(arr) / sizeof(arr[0]);
	int N1 = sizeof(arr1) / sizeof(arr1[0]);
	int N2 = sizeof(arr2) / sizeof(arr2[0]);
	int N3 = sizeof(arr3) / sizeof(arr3[0]);

    int finalWeight = 0;
	int finalWeight1 = 0;
	int finalWeight2 = 0;
	int finalWeight3 = 0;

    // Function call
    double finalValue = fractionalKnapsack(W, arr, N, finalWeight);
	double finalValue1 = fractionalKnapsack(W1, arr1, N1, finalWeight1);
	double finalValue2 = fractionalKnapsack(W2, arr2, N2, finalWeight2);
	double finalValue3 = fractionalKnapsack(W3, arr3, N3, finalWeight3);


	cout << "Caso de prueba 0:\n";
    cout << "Final value: " << finalValue << endl;
    cout << "Final weight: " << finalWeight << endl;

	cout << "\nCaso de prueba 1:\n";
    cout << "Final value: " << finalValue1 << endl;
    cout << "Final weight: " << finalWeight1 << endl;

	cout << "\nCaso de prueba 2:\n";
    cout << "Final value: " << finalValue2 << endl;
    cout << "Final weight: " << finalWeight2 << endl;

	cout << "\nCaso de prueba 3:\n";
    cout << "Final value: " << finalValue3 << endl;
    cout << "Final weight: " << finalWeight3 << endl;
    return 0;
}
