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

//Approach-2
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int cnt = 0;

        for(int i = 0;i < n;i++){
            if(nums[i] == 0)
                cnt++;
            else
                cnt = 0;
            
            ans += (cnt);
        }
        return ans;
    }
};
