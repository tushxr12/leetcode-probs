class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        int m = INT_MAX;
        unordered_map<int,int> mpp;

        for(auto i : b1){
            mpp[i]++;
            m = min(m, i);
        }

        for(auto i : b2){
            mpp[i]--;
            m = min(m, i);
        }

        vector<int> rem;

        for(auto [k, c] : mpp)
        {
            if(c%2) 
                return -1;
            
            for(int i = 0;i < abs(c)/2;i++)
            {
                rem.push_back(k);
            }
        }

        nth_element(rem.begin(), rem.begin() + rem.size()/2, rem.end());
        long long ans = 0;
        for(int i = 0;i < rem.size()/2;i++)
            ans += min(rem[i], m*2);
        return ans;
    }
};
