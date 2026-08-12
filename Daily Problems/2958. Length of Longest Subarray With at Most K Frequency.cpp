class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int,int> mpp;
        int ans = 0;

        while(j < n)
        {
            mpp[nums[j]]++;

            while(i < j && mpp[nums[j]] > k)
            {
                mpp[nums[i]]--;
                i++;
            }

            int currLength = j - i + 1;
            ans = max(ans, currLength);
            j++;
        }   
        return ans;
    }
};

// Approach - 2
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        unordered_map<int,int> mpp;
        int ans = 0;
        int culprit = 0;

        while(j < n)
        {
            mpp[nums[j]]++;

            if(mpp[nums[j]] == k + 1)
            {
                culprit++;
            }

            if(culprit)
            {
                mpp[nums[i]]--;
                if(mpp[nums[i]] == k)
                    culprit--;
                i++;
            }

            if(!culprit)
            {
                int currLength = j - i + 1;
                ans = max(ans, currLength);
            }        
            j++;
        }   
        return ans;
    }
};
