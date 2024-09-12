class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {
        int cnt = 0;
        for (auto i : words)
        {
            auto currWord = i;
            for (auto j : currWord)
            {
                if (allowed.find(j) == string::npos)
                {
                    cnt++;
                    break;
                }
            }
        }
        return (words.size() - cnt);
    }
};