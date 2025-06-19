class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        
        for(int i = 1;i < n;i++)
        {
            cout<<"Mini : "<<mini<<"  Diff : "<<nums[i]-k<<endl;
            if(nums[i] - mini > k)
            {
                mini = nums[i];
                ans += 1;
            }
        }
        return ans;
    }
};
