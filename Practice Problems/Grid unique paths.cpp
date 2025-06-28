//Recursion
class Solution {
private:
    int func(int i, int j, int n, int m)
    {
        if(i == 0 && j == 0)
            return 1;
        
        if(i < 0 || j < 0)
            return 0;
        
        //Top
        int top = func(i - 1,j,n,m);

        //Left
        int left = func(i, j - 1,n,m);

        return (top + left);
    }
public:
    int uniquePaths(int m, int n) {
        return func(m - 1,n - 1,m,n);
    }
};
