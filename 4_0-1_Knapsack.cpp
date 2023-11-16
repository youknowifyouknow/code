#include<iostream>
#include<vector>
#include<stdexcept>

using namespace std;

int knapsack(int capacity, int items, const vector<int>& price, const vector<int>& wt) {
    vector<vector<int>> dp(items + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= items; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (wt[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[items][capacity];
}

int main() {
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Calculate Maximum Profit for 0/1 Knapsack\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    int capacity, items;
                    cout << "Enter the capacity of the knapsack: ";
                    cin >> capacity;
                    if (capacity <= 0) {
                        throw invalid_argument("Capacity should be a positive integer.");
                    }

                    cout << "Enter the number of items: ";
                    cin >> items;
                    if (items <= 0) {
                        throw invalid_argument("Number of items should be a positive integer.");
                    }

                    vector<int> price(items + 1);
                    vector<int> wt(items + 1);

                    cout << "Enter the prices of items:\n";
                    for (int i = 1; i <= items; i++) {
                        cout << "Item " << i << ": ";
                        cin >> price[i];
                        if (price[i] < 0) {
                            throw invalid_argument("Price of an item should be a non-negative integer.");
                        }
                    }

                    cout << "Enter the weights of items:\n";
                    for (int i = 1; i <= items; i++) {
                        cout << "Item " << i << ": ";
                        cin >> wt[i];
                        if (wt[i] < 0) {
                            throw invalid_argument("Weight of an item should be a non-negative integer.");
                        }
                    }

                    int maxProfit = knapsack(capacity, items, price, wt);
                    cout << "Maximum Profit Earned: " << maxProfit << "\n";
                    break;
                }
                case 2:
                    cout << "Exiting the program.\n";
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option.\n";
            }
        } catch (const exception& e) {
            cerr << "Exception: " << e.what() << endl;
        } catch (...) {
            cerr << "An unknown exception occurred." << endl;
        }

    } while (choice != 2);

    return 0;
}
