class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        for(int i = 0;i < n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                int res = nums[i]*nums[j];
                mpp[res]++;
            }
        }
        int ans = 0;
        for(auto i : mpp)
        {
            int product = i.first;
            int cnt = i.second;
            if(cnt >= 2)
            {
                int comb = (cnt*(cnt - 1))/2;
                ans += (comb*8);
            }
        }
        return ans;
    }
};
