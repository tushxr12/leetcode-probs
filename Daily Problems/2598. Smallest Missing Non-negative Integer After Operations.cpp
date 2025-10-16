class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(auto i : nums)
        {
            int r = ((i%value)+value)%value;
            mpp[r]++;
        }

        int MEX = 0;
        while(mpp[(MEX%value)] > 0){
            mpp[(MEX%value)]--;
            MEX++;
        }
        return MEX;
    }
};
