//Brute
//TC->O(2N)
//SC->O(3)
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 2;i < n;i+=3)
        {
            if(nums[i] - nums[i - 2] > k)
            {
                return {};
            }
        }
        vector<int> temp;
        for(int i = 0;i < n;i++)
        {
            temp.push_back(nums[i]);
            if(temp.size() == 3)
            {
                ans.push_back(temp);
                temp.clear();
            }
        }

        return ans;
    }
};
