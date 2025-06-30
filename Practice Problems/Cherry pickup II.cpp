//Recursion
class Solution {
private:
    int func(int i,int j1, int j2,int n, int m, vector<vector<int>> &matrix)
    {
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
            return -1e8;
        
        if(i == n-1)
        {
            if(j1 == j2)
                return matrix[i][j1];
            else
            {
                return matrix[i][j1] + matrix[i][j2];
            }
        }
        int maxi = 0;
        for(int dj1 = -1; dj1 <= 1;dj1++)
        {
            for(int dj2 = -1; dj2 <= 1;dj2++)
            {
                int value = 0;
                if(j1 == j2)
                {
                    value = matrix[i][j1];
                }
                else
                {
                    value = matrix[i][j1] + matrix[i][j2];
                }

                value += func(i + 1,j1 + dj1, j2+dj2, n, m, matrix);
                maxi = max(maxi, value);
            }
        }
        return maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        return func(0,0,m-1,n,m,matrix);
    }
};
