class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int mat[n][n];
        int top=0,left=0,down=n-1,right=n-1;
        int dir=0;
        int k=0;
        while(top<=down && left<=right)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;++i)
                    mat[top][i]=++k;
                ++top;
            }
            else if(dir==1)
            {
                for(int i=top;i<=down;++i)
                    mat[i][right]=++k;
                --right;
            }
            else if(dir==2)
            {
                for(int i=right;i>=left;--i)
                    mat[down][i]=++k;
                --down;
            }
            else if(dir==3)
            {
                for(int i=down;i>=top;--i)
                    mat[i][left]=++k;
                ++left;
            }
            ++dir;
            dir%=4;
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;++i)
        {
            vector<int>r;
            for(int j=0;j<n;++j)
                r.push_back(mat[i][j]);
            ans.push_back(r);
        }
        return ans;
    }
};