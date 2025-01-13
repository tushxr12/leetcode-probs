class Solution {
public:
    int minimumLength(string s) {
        map<char,int> mpp;
        int n = s.size();
        for(auto i : s)
            mpp[i]++;
        int ans = 0;
        for(auto i : mpp)   
            if(i.second%2)
                ans += 1;
            else
                ans += 2;
        return ans;
    }
};
