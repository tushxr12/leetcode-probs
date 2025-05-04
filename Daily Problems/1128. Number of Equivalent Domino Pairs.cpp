//Using extra space
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int> mpp;
        int cnt = 0;

        for(auto &i : dominoes)
        {
            auto curr = i;
            if(curr[0] > curr[1])
            {
                swap(curr[0],curr[1]);
            }
            mpp[{curr[0], curr[1]}]++;
        }

        
        
        for(auto it : mpp)
            cnt += (it.second * (it.second - 1)/2);

        return cnt;
    }
};
