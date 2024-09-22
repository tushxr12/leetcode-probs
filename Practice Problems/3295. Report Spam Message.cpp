class Solution
{
public:
    bool reportSpam(vector<string> &message, vector<string> &bannedWords)
    {
        map<string, int> mpp;
        for (auto i : bannedWords)
            mpp[i]++;
        int cnt = 0;
        for (auto i : message)
        {
            if (mpp.find(i) != mpp.end())
                cnt++;

            if (cnt >= 2)
                return true;
        }
        return false;
    }
};