// Brute
// TC -> O(N*N)
// SC -> O(1)

class Solution {
private:
    int findMax(vector<int> &nums, int skip_idx){
        int currLength = 0, maxLength = 0;

        for(int i = 0;i < nums.size();i++){
            if(i == skip_idx)  
                continue;
            
            if(nums[i] == 1){
                currLength++;
                maxLength = max(maxLength, currLength);
            }
            else
            {
                currLength = 0;
            }
        }
        return maxLength;
    }
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int cntZero = 0;

        for(int i = 0;i < n;i++){
            if(nums[i] == 0){
                cntZero++;
                res = max(res, findMax(nums, i));
            }
        }
        return cntZero == 0 ? n - 1 : res;
    }
};
