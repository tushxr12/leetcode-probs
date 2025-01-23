class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<int> rowCount(n), colCount(m);

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 1)
                {
                    rowCount[i]++;
                    colCount[j]++;
                    ans++;
                }
            }
        }

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 1)
                {
                    if(rowCount[i] == 1 && colCount[j] == 1)
                        ans--;
                }
            }
        }
        return ans;
    }
};
