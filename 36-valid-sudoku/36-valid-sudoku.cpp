class Solution {
public:
    bool isValidGroup(vector<char>v){
        map<char,bool>m;
        for(auto i:v){
            if(m.find(i)!=m.end())return false;
            m[i]=true;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;++i)
        {
            vector<char>r;
            vector<char>c;
            for(int j=0;j<9;++j)
            {
                if(board[i][j]!='.')r.push_back(board[i][j]);
                if(board[j][i]!='.')c.push_back(board[j][i]);
            }
            if(!isValidGroup(r))return false;
            if(!isValidGroup(c))return false;
        }
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                vector<char>b;
                for(int p=i;p<i+3;++p)
                {
                    for(int q=j;q<j+3;++q)
                    {
                        if(board[p][q]!='.')b.push_back(board[p][q]);
                    }
                }
                if(!isValidGroup(b))return false;
            }
        }
        return true;
    }
};