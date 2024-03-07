https://leetcode.com/problems/valid-sudoku/

# Approach 1

1. Check every row if any number is repeated there.
	1. Create a frequency array for every row.
	2. Count the occurrences of every number.
	3. If any number get repeated, return `false`.
2. Repeat the same for column.
3. Repeat the same for every square.
4. For every square, iteration will be required from every third index to the next 3 rows / columns.
5. If all checks are passed, return `true`.

**Time Complexity**: $O(1)$
**Space Complexity**: $O(1)$

**Note**: The parameters are constants because a Sudoku is always a `9x9` grid. The loops will not be dependent on any question parameters.

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for ( int i = 0; i < 9; ++i ) {
            vector<int> v(9, 0);
            for ( int j = 0; j < 9; ++j ) {
                if ( board[i][j] == '.' ) {
                    continue;
                }
                if ( v[board[i][j] - '0' - 1] >= 1 ) {
                    return false;
                }
                v[board[i][j] - '0' - 1]++;
            }
        }
        for ( int i = 0; i < 9; ++i ) {
            vector<int> v(9, 0);
            for ( int j = 0; j < 9; ++j ) {
                if ( board[j][i] == '.' ) {
                    continue;
                }
                if ( v[board[j][i] - '0' - 1] >= 1 ) {
                    return false;
                }
                v[board[j][i] - '0' - 1]++;
            }
        }
        for ( int i = 0; i < 9; i += 3 ) {
            for ( int j = 0; j < 9; j += 3 ) {
                vector<int> v(9, 0);
                for ( int I = i; I < i + 3; ++I ) {
                    for ( int J = j; J < j + 3; ++J ) {
                        if ( board[I][J] == '.' ) {
                            continue;
                        }
                        if ( v[board[I][J] - '0' - 1] >= 1 ) {
                            return false;
                        }
                        v[board[I][J] - '0' - 1]++;
                    } 
                }
            }
        }
        return true;
    }
};
```