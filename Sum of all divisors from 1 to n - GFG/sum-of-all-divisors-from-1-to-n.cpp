//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long F(int n)
    {
        if(n==1)return 1;
        int ans=n+1;
        for(int i=2;i<=sqrt(n);++i)
            ans+=(n%i==0)?i:0;
        return ans;
    }
    long long sumOfDivisors(int n)
    {
        long long s=0;
        for(int i=1;i<=n;++i)
            s+=(n/i)*i;
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends