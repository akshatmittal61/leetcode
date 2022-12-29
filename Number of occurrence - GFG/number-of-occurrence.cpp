//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) {
	    int beg=0, end=n-1;
        int mid=(beg+end)/2;
        int low=-1,high=-1;
        int ans=0;
        if(n==0)return ans;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            if(nums[mid]==target)break;
            else if(nums[mid]>target)end=mid-1;
            else beg=mid+1;
        }
        if(nums[mid]==target)
        {
            low=mid,high=mid;
            while(low>0 && nums[low-1]==target)--low;
            while(high<n-1 && nums[high+1]==target)++high;
            return high-low+1;
        }
        return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends