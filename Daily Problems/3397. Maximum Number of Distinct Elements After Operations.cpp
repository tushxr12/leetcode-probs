class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        sort(begin(nums) , end(nums));

        int prev = INT_MIN;


        for(int i = 0;i < n;i++){
            int minVal = nums[i] - k;

            if(prev < minVal){
                prev = minVal;
                count++;
            }
            else if(prev < nums[i] + k)
            {
                prev += 1;
                count++;
            }
        }
        return count;
    }
};
