#include <iostream>
#include <unordered_map>

using namespace std;

int mostFrequent(int arr[], int n) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    int max_count = 0, res = -1;
    for (auto i : mp) {
        if (max_count < i.second) {
            res = i.first;
            max_count = i.second;
        }
    }

    return res;
}

int main() {
    try {
        cout << "Enter the size of the array: ";
        int n;
        cin >> n;

        if (n <= 0) {
            cerr << "Array size should be a positive integer." << endl;
            return 1;
        }

        int arr[n];

        cout << "Enter the elements of the array (separated by spaces): ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (cin.fail()) {
                cerr << "Invalid input. Please enter integers only." << endl;
                return 1;
            }
        }

        cout << "Most frequent element: " << mostFrequent(arr, n) << endl;
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return 1;
    }

    return 0;
}
