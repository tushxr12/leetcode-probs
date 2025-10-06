class Solution {
private:
    bool dfs(int i,int j,int t,vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        int n = grid.size();
        visited[i][j] = true;

        if(i == n-1 && j == n-1)
            return true;
        
        for(auto &dir: dirs){
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && !visited[i_][j_] && grid[i_][j_] <= t){
                if(dfs(i_,j_,t,grid,visited))
                    return true;
            }
        }
        return false;
    }
public:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0, high = n*n - 1, ans = INT_MAX;

        while(low <= high){
            int mid = (low + high)/2;
            vector<vector<bool>> visited(n, vector<bool>(n,false));

            if(grid[0][0] <= mid && dfs(0,0,mid,grid,visited)){
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
