// Approach - 1
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int i = 0;

        while(i < n){
            long long l = 0;
            if(nums[i] == 0){
                while(i < n && nums[i] == 0)
                {
                    l++;
                    i++;
                }
            }
            else
            {
                i++;
            }

            ans += (l)*(l+1)/2;
        }
        return ans;
    }
};
