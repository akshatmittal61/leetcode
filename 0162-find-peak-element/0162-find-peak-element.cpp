class Solution {
public:
    int peak(vector<int>nums, int beg, int end){
        int n=nums.size();
        // int mid=end+(beg-end)/2;
        int mid=(beg+end)/2;
        while(beg<=end)
        {
            mid=(beg+end)/2;
            cout<<mid<<' ';
            if( (mid==0 || nums[mid-1]<nums[mid]) && (mid==n-1 || nums[mid+1]
            <nums[mid]) )
                return mid;
            else if(nums[mid+1]>nums[mid])return peak(nums, mid+1, end);
            else return peak(nums, beg, mid-1);
        }
        return -1;
    }
    int findPeakElement(vector<int>& arr) {
        // cout<<endl;
        // return peak(nums, 0, nums.size()-1);
        int n=arr.size();
    bool flag=false;
    for(int i=0;i<n-1;++i){
        if(arr[i]>arr[i+1]){
            return i;
        }
    }
    return n-1;
    }
};