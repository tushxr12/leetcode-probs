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

//Using constant space 
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> vec(100);
        int res = 0;
        for(auto &i : dominoes)
        {
            if(i[0] > i[1])
                swap(i[0], i[1]);
            
            int num = i[0]*10 + i[1];
            res += vec[num];
            vec[num]++;
        }
        return res;
    }
};
