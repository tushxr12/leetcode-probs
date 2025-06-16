//Brute
//TC->O(N^2)
//SC->O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++)
            {
                if(nums[j] > nums[i])
                    maxi = max(maxi , nums[j] - nums[i]);
            }
        }
        return (maxi == INT_MIN) ? -1 : maxi;
    }
};

//Optimal
//TC->O(N)
//SC->O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minElement = nums[0];
        int maxDiff = -1;
        for(int j = 1;j < n;j++)
        {
            if(nums[j] > minElement)
            {
                maxDiff = max(maxDiff, nums[j] - minElement);
            }
            else
            {
                minElement = nums[j];
            }
        }
        return maxDiff;
    }
};
