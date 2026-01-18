// TC : O(M*N*Side*Side)
// SC : O(M*N)
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Row Cumulative Sum
        vector<vector<int>> rcs(rows, vector<int> (cols));
        for(int i = 0;i < rows;i++){
            rcs[i][0] = grid[i][0];
            for(int j = 1;j < cols;j++){
                rcs[i][j] = rcs[i][j-1] + grid[i][j];
            }
        }

        // Column Cumulative Sum
        vector<vector<int>> ccs(rows, vector<int> (cols));
        for(int j = 0;j < cols;j++){
            ccs[0][j] = grid[0][j];
            for(int i = 1;i < rows;i++){
                ccs[i][j] = ccs[i-1][j] + grid[i][j];
            }
        }

        // Try to iterate on all possible side squares
        for(int side = min(rows, cols); side >= 2;side--)
        {
            for(int i = 0; i + side - 1 < rows;i++){
                for(int j = 0;j + side - 1 < cols;j++){

                    int targetSum = rcs[i][j+side-1] - (j > 0 ? rcs[i][j-1] : 0);

                    // Now check that all rows, cols, diag, antiDiag sum should be equal for a magic square

                    bool allSame = true;

                    // Check rows
                    for(int r = i + 1; r < i + side;r++)
                    {
                        int currSum = rcs[r][j+side-1] - (j > 0 ? rcs[r][j-1] : 0);
                        if(currSum != targetSum)
                        {
                            allSame = false;
                            break;
                        }
                    }

                    if(!allSame)
                        continue;
                    
                    // Check cols
                    for(int c = j; c < j + side;c++)
                    {
                        int currSum = ccs[i+side-1][c] - (i > 0 ? ccs[i-1][c] : 0);
                        if(currSum != targetSum)
                        {
                            allSame = false;
                            break;
                        }
                    }

                    if(!allSame)
                        continue;
                    
                    // Check diag and anti diag
                    int diagSum = 0, antiDiagSum = 0;
                    for(int k = 0;k < side;k++)
                    {
                        diagSum += grid[i+k][j+k];
                        antiDiagSum += grid[i+k][j+side-1-k];
                    }

                    if(diagSum == targetSum && antiDiagSum == targetSum)
                    {
                        return side;
                    }
                }
            }
        }
        
        // If no square found abve, return 1 here
        return 1;
    }
};
