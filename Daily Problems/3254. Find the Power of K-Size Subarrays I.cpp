class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        dq.push_front(nums[0]);
        for(int i = 1;i < k - 1;i++)
        {
            if(dq.size() > 0 && nums[i] - dq.front() != 1)
            {
                dq.clear();
            }
            dq.push_front(nums[i]);
        }

        for(int i = k - 1;i < nums.size();i++)
        {
            if(dq.size() > 0 && nums[i] - dq.front() != 1)
            {
                dq.clear();
            }

            dq.push_front(nums[i]);
            if(dq.size() >= k)
                ans.push_back(dq.front());
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
