class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();

        int total = n*m;

        k %= total;
        if(!k)
            return grid;
        
        auto reverse = [&](int i,int j)
        {
            while(i < j)
            {
                swap(grid[i/m][i%m], grid[j/m][j%m]);
                i++;j--;
            }
        };

        reverse(0,total-1);
        reverse(0,k-1);
        reverse(k,total-1);
        return grid;
    }
};
