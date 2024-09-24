class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> mpp;
        for(auto i:arr1)
        {
            string curr = "";
            string numInString = to_string(i);
            for(auto j : numInString)
            {
                curr += j;
                mpp[curr]++;
            }
        }
        int ans = 0;
        for(auto i : arr2)
        {
            string curr = "";
            string numInString = to_string(i);
            for(auto j : numInString)
            {
                curr += j;
                if(mpp.find(curr) != mpp.end())
                {
                    ans = max(ans, (int)curr.size());
                }
            }
        }
        return ans;
    }
};