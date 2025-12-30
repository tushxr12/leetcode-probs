class Solution {
private:
    int isMagicSquare(int row,int col, vector<vector<int>> &grid)
    {
        // uniquesness
        unordered_set<int> st;

        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++)
            {
                int num = grid[i+row][j+col];
                if(num < 1 || num > 9 || st.find(num) != st.end())
                    return false;
                else
                    st.insert(num);
            }
        }

        // check sums
        int sum = grid[row][col] + grid[row][col+1] + grid[row][col+2];

        for(int i = 0;i < 3;i++){
            // row sums
            if(grid[row+i][col] + grid[row+i][col+1] + grid[row+i][col+2] != sum)
                return false;
            
            // Cols sum
            if(grid[row][col+i] + grid[row+1][col+i] + grid[row+2][col+i] != sum)
                return false;
        }

        // Diagnoal sum
        if(grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2] != sum)
            return false;
        
        // AntiDiagonal sum
        if(grid[row][col+2] + grid[row+1][col+1] + grid[row+2][col] != sum)
            return false;
        
        return true;
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(rows < 3 || cols < 3)
            return 0;
        
        int cnt = 0;
        for(int i = 0;i <= rows-3;i++){
            for(int j = 0;j <= cols-3;j++){
                if(isMagicSquare(i,j,grid)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
