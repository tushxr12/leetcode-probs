class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m =isWater[0].size();
        vector<vector<int>> ans(n, vector<int>(m, - 1));
        queue<pair<int,int>> q;
        vector<vector<int>> dirs = {{0,1}, {1,0}, {0, -1}, {-1, 0}};

        for(int r = 0; r < n;r++)
        {
            for(int c = 0;c < m;c++)
            {
                if(isWater[r][c] == 1)
                {
                    ans[r][c] = 0;
                    q.push({r,c});
                }
            }
        }

        while(!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            for(auto dir : dirs)
            {
                int nr = r + dir[0], nc = c + dir[1];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc] == -1)
                {
                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return ans;
    }
};
