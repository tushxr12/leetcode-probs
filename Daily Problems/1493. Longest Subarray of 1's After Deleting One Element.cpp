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

// Better
// TC -> O(N)
// SC -> O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxLength = 0;
        int zeroCount = 0;

        while(j < n){
            if(nums[j] == 0){
                zeroCount++;
            }

            while(zeroCount > 1){
                if(nums[i] == 0)
                    zeroCount--;
                i++;
            }

            int currLength = j - i;
            maxLength = max(maxLength, currLength);
            j++;
        }
        return maxLength;
    }
};

Optimal (More clean and Simple)
TC -> O(N)
SC -> O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int maxLength = 0;
        int zeroCount = 0;
        int last_zero_idx = -1;

        while(j < n){
            if(nums[j] == 0){
                i = last_zero_idx + 1;
                last_zero_idx = j;
            }

            int currLength = j - i;
            maxLength = max(maxLength, currLength);
            j++;
        }
        return maxLength;
    }
};
