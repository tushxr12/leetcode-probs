class Solution {
private:
    int dp[101][101][601]; 
    int solve(vector<pair<int,int>> & count, int m,int n, int index)
    {
        if(index >= count.size() || (m == 0 && n == 0))
            return 0;

        if(dp[m][n][index] != -1)
            return dp[m][n][index];
        
        int take = 0;
        if(count[index].first <= m && count[index].second <= n){
            take = 1 + solve(count, m - count[index].first, n - count[index].second, index + 1);
        }

        int skip = solve(count, m, n, index + 1);

        return dp[m][n][index] = max(take, skip);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int N= strs.size();
        vector<pair<int,int>> count(N);

        for(int i = 0;i < N;i++){
            int countZeroes = 0, countOnes = 0;

            for(const char&ch : strs[i]){
                if(ch == '0')
                    countZeroes++;
                else
                    countOnes++;
            }
            count[i] = {countZeroes, countOnes};
        }

        memset(dp, -1, sizeof(dp));
        return solve(count, m, n, 0);
    }
};
