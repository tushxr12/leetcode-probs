class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> mins;
        for (auto i : timePoints)
        {
            string currTime = i;
            string hourSubstr = currTime.substr(0, 2);
            string minSubstr = currTime.substr(3, 2);
            int hoursInt = stoi(hourSubstr);
            int minsInt = stoi(minSubstr);
            int totalMins = hoursInt * 60 + minsInt;
            mins.push_back(totalMins);
        }
        sort(mins.begin(), mins.end());
        int ans = INT_MAX;
        for (int i = 1; i < mins.size(); i++)
            ans = min(ans, mins[i] - mins[i - 1]);

        return min(ans, 24 * 60 - mins[mins.size() - 1] + mins[0]);
    }
};