class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, prefSum = 0, sortedPrefSum = 0;

        for(int i = 0;i < arr.size();i++)
        {
            prefSum += arr[i];
            sortedPrefSum += i;
            if(prefSum == sortedPrefSum)
                ans++;
        }
        return ans;
    }
};
