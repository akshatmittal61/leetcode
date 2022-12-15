//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int m1=arr[0], m2=arr[0];
	    for(int i=0;i<n;++i)
	        m1=max(m1,arr[i]);
	    int k=0;
	    while(arr[k]==m1)++k;
	    if(k==n)return -1;
	    m2=arr[k];
	    for(int i=k;i<n;++i)
	        if(m2<arr[i] && arr[i]!=m1)m2=arr[i];
	    return m2;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends