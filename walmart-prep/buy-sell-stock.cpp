#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int Min = INT_MAX;
    int Max = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        Min = min(Min, prices[i]);
        Max = max(Max, prices[i] - Min);
    }
    return Max;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}