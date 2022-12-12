//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) {
        for(int i=1;i<=n;++i)
        {
            for(int j=i;j<n;++j)
                cout<<" ";
            for(int k=1;k<2*i;++k)
            {
                if(k&1)cout<<'*';
                else cout<<' ';
            }
            cout<<endl;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<i;++j)
                cout<<" ";
            for(int k=1;k<2*(n-i+1);++k)
            {
                if(k&1)cout<<'*';
                else cout<<' ';
            }
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends