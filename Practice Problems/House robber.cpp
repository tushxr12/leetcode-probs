//Recursion
//TC->O(2^N) + O(2^N)
//SC->O(4N)
class Solution {
private:
    int func(int index, vector<int> &nums)
    {
        if(index == 0)
            return nums[0];
        
        if(index < 0)
            return 0;
        
        int pick = INT_MIN;
        
        if(index > 1)
            pick = max(pick,nums[index] + func(index - 2, nums));

        int notPick = 0 + func(index - 1, nums);

        return max(pick, notPick);
    }
public:
    int houseRobber(vector<int>& money) {
        int n = money.size();
        vector<int> v1,v2;

        for(int i = 0;i < n;i++)
        {
            if(i != 0)  
                v1.push_back(money[i]);
            if(i != n - 1)
                v2.push_back(money[i]);
        }

        int ans1 = func(n - 1, v1);
        int ans2 = func(n - 1, v2);

        return max(ans1, ans2);
    }
};
