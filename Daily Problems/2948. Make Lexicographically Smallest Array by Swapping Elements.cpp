class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> temp(nums);
        int n = nums.size();
        sort(temp.begin(), temp.end());
        //[1,1,2,6,7,18]

        int currGroup = 0;
        unordered_map<int,int> mpp;
        mpp.insert(pair<int,int>(temp[0], currGroup));

        unordered_map<int, list<int>> mppList;
        mppList.insert(pair<int, list<int>>(currGroup, list<int>(1, temp[0])));

        for(int i = 1;i < n;i++)
        {
            if(abs(temp[i] - temp[i - 1]) > limit)
            {
                currGroup++;
            }

            mpp.insert(pair<int,int>(temp[i], currGroup));

            if(mppList.find(currGroup) == mppList.end())
            {
                mppList[currGroup] = list<int>();
            }
            mppList[currGroup].push_back(temp[i]);
        }

        for(int i = 0;i < n;i++)
        {
            int currNum = nums[i];
            int groupOfCurrNum = mpp[currNum];
            nums[i] = *mppList[groupOfCurrNum].begin();
            mppList[groupOfCurrNum].pop_front();
        }
        return nums;
    }
};
