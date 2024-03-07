https://leetcode.com/problems/word-pattern/

# Approach 1

1. Create a array of strings, `words` by splitting `s` by `space`.
2. Create 2 hash-maps, one for `pattern` -> `s` and another for vice versa.
3. Check if the size of string `s` is not equal to size of `words`, return `false` already.
4. Start iterating on the both, add both in their respective hash-maps.
5. If the mapping does not matches for any entry, return `false`.
6. If all the mappings match, return `true`.

**Time Complexity**: $O(n*log(n))$
**Space Complexity**: $O(n)$

```cpp
class Solution {
public:
    vector<string> split(string s, char c) {
        int n=s.length();
        vector<string> ans;
        for(int i=0;i<n;++i) {
            string h="";
            for(int j=i;j<n;++j) {
                if(s[j]==c || j==n-1){
                    i=j;
                    if(j==n-1)
                        h+=s[n-1];
                    break;
                }
                else h+=s[j];
            }
            ans.push_back(h);
        }
        return ans;
    }
    bool wordPattern(string pattern, string s) {
        vector<string> words = split(s, ' ');
        map<char,string>m;
        map<string,char>q;
        int n = pattern.length();
        if(n!=words.size())return false;
        for(int i=0;i<n;++i)
        {
            if( m.find(pattern[i]) != m.end() ) {
                if(m[pattern[i]]!=words[i])return false;
            }
            else m[pattern[i]]=words[i];
            if( q.find(words[i]) != q.end() ) {
                if(q[words[i]]!=pattern[i])return false;
            }
            else q[words[i]]=pattern[i];
        }
        return true;
    }
};
```