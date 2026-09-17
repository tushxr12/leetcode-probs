class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0,j = 0;

        int currSum = 0;
        vector<int> minBestLenTillIndex(n, INT_MAX);

        int bestMinLen = INT_MAX, res = INT_MAX;

        while(j < n)
        {
            currSum += arr[j];

            while(i < j && currSum > target)
                currSum -= arr[i++];
            
            if(currSum == target)
            {
                int len = j - i + 1;

                if(i > 0 && minBestLenTillIndex[i-1] != INT_MAX)
                {
                    res = min(res, len + minBestLenTillIndex[i-1]);
                }
                bestMinLen = min(bestMinLen, len);
            }
            minBestLenTillIndex[j] = bestMinLen;
            j++;
        }   
        return res == INT_MAX ? -1 : res;
    }
};
