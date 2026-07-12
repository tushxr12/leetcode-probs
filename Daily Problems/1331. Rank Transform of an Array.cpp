class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty())
            return {};

        vector<int> temp = arr;
        sort(begin(temp), end(temp));
        int rank = 1;
        unordered_map<int,int> mpp;
        mpp[temp[0]] = 1;
        int n = arr.size();

        for(int i = 1;i < n;i++)
        {
            if(temp[i] != temp[i-1])
                rank++;
            mpp[temp[i]] = rank;
        }

        vector<int> ans;
        for(int i = 0;i < n;i++){
            ans.push_back(mpp[arr[i]]);
        }
        return ans;
    }
};
