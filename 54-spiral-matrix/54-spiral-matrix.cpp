class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0,down=n-1,left=0,right=m-1;
        int dir=0;
        int no=m*n,k=0;
        vector<int>ans;
        while(top<=down && left<=right)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;++i)
                    ans.push_back(matrix[top][i]);
                ++top;
            }
            else if(dir==1)
            {
                for(int i=top;i<=down;++i)
                    ans.push_back(matrix[i][right]);
                --right;
            }
            else if(dir==2)
            {
                for(int i=right;i>=left;--i)
                    ans.push_back(matrix[down][i]);
                --down;
            }
            else if(dir==3)
            {
                for(int i=down;i>=top;--i)
                    ans.push_back(matrix[i][left]);
                ++left;
            }
            ++dir;
            dir%=4;
        }
        return ans;
    }
};