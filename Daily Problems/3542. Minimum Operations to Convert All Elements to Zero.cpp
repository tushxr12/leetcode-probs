// Brute force
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(begin(nums) , end(nums));
        int ans = 0;
        for(int target: st){
            if(target == 0){
                continue;
            }

            bool flow = false;
            for(int i = 0;i<n;i++){
                if(nums[i] == target){
                    if(!flow){
                        flow = true;
                        ans++;
                    }
                }
                else if(nums[i] < target)
                {
                    flow = false;
                }
            }
        }
        return ans;
    }
};
