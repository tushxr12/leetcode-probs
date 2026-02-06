class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        int minEl = nums[0], maxEl = nums[0];

        int i = 0, j = 0;
        int L = 1;

        while(j < n)
        {
            minEl = nums[i];
            maxEl = nums[j];

            while(i < j && maxEl > (1LL*minEl*k))
            {
                i++;
                minEl = nums[i];
            }
            L = max(L, j - i + 1);
            j++;
        }

        return (n-L);
    }
};
