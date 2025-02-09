class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                if(j - i != nums[j] - nums[i])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};

//Better
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long goodPairs = 0, totalPairs = n*(n-1)/2;
        unordered_map<int,int> mpp;
        for(int i = 0;i < n;i++)
        {
            goodPairs += mpp[i - nums[i]];
            mpp[i - nums[i]]++;
        }
        return (totalPairs - goodPairs);
    }
};
