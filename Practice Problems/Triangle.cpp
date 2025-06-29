//Recursion
class Solution {
private:
    int func(int i,int j,int n, vector<vector<int>> &triangle)
    {
        if(i == n - 1)
            return triangle[i][j];
        
        int down = triangle[i][j] + func(i + 1,j, n,triangle);
        int dg = triangle[i][j] + func(i + 1,j + 1,n,triangle);

        return min(down, dg);
    }
public:
    int minTriangleSum(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return func(0,0,n,triangle);
    }
};
