https://leetcode.com/problems/find-the-town-judge/

# Approach 1

1. Create 2 hash maps `trusting` and `trusted` for people who are trusting and for people who are to be trusted respectively.
2. Add the details in the `trust` grid in to the hash maps by counting as required.
3. Iterate on the `trusted` map.
4. Check for an entry for which 
	1. The value of `trusting` is $0$, i.e.) the person who trusts nobody.
	2. The value of `second` at that entry is $n-1$ i.e.) everybody else trusts this person.
5. If such an entry is found, return the person id.
6. Else return $-1$.
7. Base case: if the given value of $n$ is $1$, i.e.) we have to check for only one person, return $1$ if that person is trusted, else return $0$.

**Time Complexity**: $O(n*log(n))$
**Space Complexity**: $O(n)$

```cpp
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
```