//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long gcd(long long a,long long b)
    {
        if(a==0 || b==0)return a+b;
        if(a==b)return a;
        if(a>b)return gcd(a-b,b);
        else return gcd(a,b-a);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        long long g=1,l=1;
        g=gcd(A,B);
        l=(A*B)/g;
        vector<long long>ans;
        ans.push_back(l);
        ans.push_back(g);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends