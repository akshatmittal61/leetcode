class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int>ans;
        int id=-1;
        int beg=0,end=n-1;
        int mid=(beg+end)/2;
        if(x<=arr[0])
        {
            for(int i=0;i<k;++i)
                ans.push_back(arr[i]);
        }
        else if(x>=arr[n-1])
        {
            for(int i=n-k;i<n;++i)
                ans.push_back(arr[i]);
        } 
        else
        {
            while(end-beg>=k)
            {
                if(abs(arr[beg]-x)<=abs(arr[end]-x))
                    --end;
                else ++beg;
            }
            for(int i=beg;i<=end;++i)
                ans.push_back(arr[i]);
        }
        return ans;
    }
};