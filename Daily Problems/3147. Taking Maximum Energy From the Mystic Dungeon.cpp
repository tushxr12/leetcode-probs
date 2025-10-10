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
