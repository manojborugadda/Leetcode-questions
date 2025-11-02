class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0)); // 0 = empty
        for (auto &g : guards) grid[g[0]][g[1]] = 1;    // 1 = guard
        for (auto &w : walls)  grid[w[0]][w[1]] = 2;    // 2 = wall

        //directional scanning method is simpler and faster instead of BFS/DFS as the "guard" vision is "straight" lines.

        // top-to-bottom scan 
        for(int j = 0;j<n;j++) {
            bool guard_active  = false;
            for(int i = 0;i<m;i++) {
                if(guard_active and grid[i][j] == 0) {
                    grid[i][j] = 3;// mark guarded
                }
                if(grid[i][j] == 1) {
                    guard_active = true;
                }
                if(grid[i][j] == 2) {
                    guard_active = false;
                }
            }
        }
        // bottom-to-top scan 
        for (int j = 0; j < n; j++) {
            bool guard_active = false;
            for (int i = m - 1; i >= 0; i--) {
                if (guard_active && grid[i][j] == 0) {
                    grid[i][j] = 3; // mark guarded
                }
                if (grid[i][j] == 1) guard_active = true;  // guard found
                if (grid[i][j] == 2) guard_active = false; // wall found
            }
        }

         // left-to-right scan 
        for (int i = 0; i < m; i++) {
            bool guard_active = false;
            for (int j = 0; j < n; j++) {
                if (guard_active && grid[i][j] == 0) {
                    grid[i][j] = 3; // mark guarded
                }
                if (grid[i][j] == 1) guard_active = true;  // guard found
                if (grid[i][j] == 2) guard_active = false; // wall found
            }
        }

        // right-to-left scan 
        for (int i = 0; i < m; i++) {
            bool guard_active = false;
            for (int j = n-1; j >= 0; j--) {
                if (guard_active && grid[i][j] == 0) {
                    grid[i][j] = 3; // mark guarded
                }
                if (grid[i][j] == 1) guard_active = true;  // guard found
                if (grid[i][j] == 2) guard_active = false; // wall found
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) count++; // empty & unguarded
            }
        }
        return count;
    }
};

/*
O(4⋅m⋅n) because we scan the grid 4 times (once in each direction).
That simplifies to O(m⋅n).
Space complexity is O(m⋅n) since We store the whole grid in memory.
*/
