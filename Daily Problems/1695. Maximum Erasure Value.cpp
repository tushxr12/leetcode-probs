class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        set<int> st;
        int sum = 0, maxSum = -1;

        while(right < n)
        {
            while(st.find(nums[right]) != st.end())
            {
                sum -= nums[left];
                st.erase(nums[left]);
                left++;
            }
            sum += nums[right];
            st.insert(nums[right]);
            right++;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
