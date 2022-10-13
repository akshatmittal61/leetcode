//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        char dir='e';
        int top=0,bottom=r-1,left=0,right=c-1;
        vector<int>ans;
        while(top<=bottom && left<=right)
        {
            if(dir=='e')
            {
                for(int i=left;i<=right;++i)
                    ans.push_back(matrix[top][i]);
                dir='s';
                ++top;
            }
            else if(dir=='s')
            {
                for(int i=top;i<=bottom;++i)
                    ans.push_back(matrix[i][right]);
                dir='w';
                --right;
            }
            else if(dir=='w')
            {
                for(int i=right;i>=left;--i)
                    ans.push_back(matrix[bottom][i]);
                dir='n';
                --bottom;
            }
            else if(dir=='n')
            {
                for(int i=bottom;i>=top;--i)
                    ans.push_back(matrix[i][left]);
                dir='e';
                ++left;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends