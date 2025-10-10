// Recursion
class Solution {
public:
    int n,K;

    int solve(vector<int> &energy, int i)
    {
        if(i >= n){
            return 0;
        }

        return energy[i] + solve(energy, i + K);
    }

    int maximumEnergy(vector<int>& energy, int k) {
        n = energy.size();
        K = k;

        int maxEnergy = INT_MIN;
        for(int i = 0;i < n;i++)
            maxEnergy = max(maxEnergy, solve(energy,i));
        return maxEnergy;
    }
};

// Memoization
class Solution {
public:
    int n,K;

    int solve(vector<int> &energy, int i,vector<int> &dp)
    {
        if(i >= n){
            return 0;
        }

        if(dp[i] != INT_MIN)
            return dp[i];

        return dp[i] = energy[i] + solve(energy, i + K,dp);
    }

    int maximumEnergy(vector<int>& energy, int k) {
        n = energy.size();
        K = k;

        vector<int> dp(n, INT_MIN);

        int maxEnergy = INT_MIN;
        for(int i = 0;i < n;i++)
            maxEnergy = max(maxEnergy, solve(energy,i,dp));
        return maxEnergy;
    }
};
