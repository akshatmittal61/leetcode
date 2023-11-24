#include <bits/stdc++.h>

using namespace std;

int search(vector<int> v, int x)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
        if (v[i] == x)
            return i;
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int x;
    cin >> x;
    cout << search(v, x) << endl;
    return 0;
}
