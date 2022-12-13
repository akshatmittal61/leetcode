//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        for(int i=1;i<=n;++i)
        {
            int s=n;
            for(int j=1;j<i;++j)
                cout<<s--<<' ';
            for(int j=i;j<=n;++j)
                cout<<s<<' ';
            for(int j=i;j<n;++j)
                cout<<s<<' ';
            for(int j=1;j<i;++j)
                cout<<++s<<' ';
            cout<<endl;
        }
        for(int i=n-1;i>=1;--i)
        {
            int s=n;
            for(int j=1;j<i;++j)
                cout<<s--<<' ';
            for(int j=i;j<=n;++j)
                cout<<s<<' ';
            for(int j=i;j<n;++j)
                cout<<s<<' ';
            for(int j=1;j<i;++j)
                cout<<++s<<' ';
            cout<<endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends