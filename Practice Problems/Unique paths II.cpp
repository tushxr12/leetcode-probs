//Recursion
class Solution {
private:
    int func(int i,int j, int n,int m, vector<vector<int>> &matrix)
    {
        if(i == 0 && j == 0)
            return 1;
        
        if(i < 0 || j < 0 || matrix[i][j] == 1)
            return 0;
        
        int top = func(i - 1,j,n,m,matrix);

        int left = func(i, j -1,n,m,matrix);

        return (top + left);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        if(matrix[0][0] == 1 || matrix[n-1][m-1] == 1)
            return 0;
        return func(n -1,m -1, n,m, matrix);
    }
};
