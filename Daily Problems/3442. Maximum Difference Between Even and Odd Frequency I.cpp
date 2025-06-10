class Solution {
public:
    int maxDifference(string s) {
        map<char,int> mpp;
        for(auto i : s)
            mpp[i]++;
        vector<int> temp;
        for(auto i : mpp)
            temp.push_back(i.second);
        sort(temp.begin(), temp.end());
        int n = temp.size();
        int maxOdd = INT_MIN, minEven = INT_MAX;
        for(auto i : mpp)
        {
            if(i.second%2)
                maxOdd = max(maxOdd, i.second);
            if(i.second%2 == 0)
                minEven = min(minEven, i.second);
        }
        return maxOdd - minEven;
    }
};
