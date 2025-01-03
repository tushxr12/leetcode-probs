class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0, currSum = 0;
        for(int i = 0;i < n - 1;i++)
        {
            currSum += nums[i];
            long long int remSum = 0;
            for(int j = i + 1;j < n;j++)
            {
                remSum += nums[j];
            }
            if(currSum >= remSum)
                ans++;
        }
        return ans;
    }
};

//Optimal
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long int ans = 0, currSum = 0, totSum = 0, remSum = 0;
        for(auto i : nums)
            totSum += i;
        
        for(int i = 0;i < n - 1;i++)
        {
            currSum += nums[i];
            remSum = (totSum - currSum);
            if(currSum >= remSum)
            {
                ans++;
            }
        }
        return ans;
    }
};
