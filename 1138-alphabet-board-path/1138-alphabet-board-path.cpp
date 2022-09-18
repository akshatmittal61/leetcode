class Solution {
public:
    string alphabetBoardPath(string target) {
        char board[6][5]={
            {'a','b','c','d','e'},
            {'f','g','h','i','j'},
            {'k','l','m','n','o'},
            {'p','q','r','s','t'},
            {'u','v','w','x','y'},
            {'z',' ',' ',' ',' '},
        };
        string ans;
        int r=0,c=0;
        for(auto C:target)
        {
            if(board[r][c]==C){
                ans+='!';
                continue;
            }
            int k=C-'a';
            int i=k/5,j=k%5;
            char p='D',q='R';
            if(r<i)p='D';
            else p='U';
            if(c<j)q='R';
            else q='L';
            if(C=='z'&&c!=0)
            {
                for(int I=r;I<4;++I)ans+=p;
                for(int I=c;I>0;--I)ans+=q;
                ans+='D';
            }
            else
            {
                for(int I=0;I<abs(r-i);++I)ans+=p;
                for(int I=0;I<abs(c-j);++I)ans+=q;
            }
            r=i,c=j;
            ans+='!';
        }
        return ans;
    }
};