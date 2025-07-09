class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps(1, startTime[0]);

        for(int i = 1;i < startTime.size();++i)
        {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }

        gaps.push_back(eventTime - endTime.back());

        long long maxFreeDuration = 0, currSum = 0;

        for(int i = 0;i < gaps.size();++i)
        {
            currSum += gaps[i] - ((i >= k + 1) ? gaps[i - (k + 1)] : 0);
            maxFreeDuration = max(maxFreeDuration , currSum);
        }
        return maxFreeDuration;
    }
};
