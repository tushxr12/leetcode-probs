class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m, vector<int>(n,INT_MAX));

        deque<pair<int,int>> dq;
        ans[0][0] = grid[0][0];
        dq.push_front({0,0});

        while(!dq.empty())
        {
            auto [r,c] = dq.front();
            dq.pop_front();

            for(auto &dir : dirs)
            {
                int newR = r + dir[0];
                int newC = c + dir[1];

                if(newR < 0 || newR >= m || newC < 0 || newC >= n)
                    continue;
                
                if(ans[r][c] + grid[newR][newC] < ans[newR][newC]){
                    ans[newR][newC] = ans[r][c] + grid[newR][newC];

                    if(grid[newR][newC] == 0){
                        dq.push_front({newR, newC});
                    }
                    else
                    {
                        dq.push_back({newR, newC});
                    }
                }
            }
        }    
        int x = ans[m-1][n-1];
        return (health - x >= 1);
    }
};
