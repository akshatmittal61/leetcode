class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if ( n == 1 ) {
            if ( trust.size() == 0 )
                return 1;
            else 
                return 0;
        }
        map<int, int> trusting, trusted;
        for(auto v: trust) {
            trusting[v[0]]++;
            trusted[v[1]]++;
        }
        for(auto x: trusted) {
            if( trusting[x.first] == 0 && x.second == n - 1 )
                return x.first;
        }
        return -1;
    }
};