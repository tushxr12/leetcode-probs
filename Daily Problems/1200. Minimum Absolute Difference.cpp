class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr) ,end(arr));
        int minDiff = INT_MAX;
        int n = arr.size();
        for(int i = 1;i < n;i++)
        {
            int currDiff = arr[i] - arr[i-1];
            minDiff = min(minDiff, currDiff);
        }

        vector<vector<int>> ans;
        for(int i = 1;i < n;i++)
        {
            if(arr[i] - arr[i-1] == minDiff)
            {
                vector<int> curr = {arr[i-1], arr[i]};
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
