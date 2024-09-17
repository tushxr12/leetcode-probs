class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> ans;
        int n1 = s1.size(), n2 = s2.size();
        string curr = "";
        map<string, int> mpp;
        for (int i = 0; i < n1; i++)
        {
            if (s1[i] == ' ')
            {
                mpp[curr]++;
                curr = "";
            }
            else if (i == n1 - 1)
            {
                curr += s1[i];
                mpp[curr]++;
            }
            else
            {
                curr += s1[i];
            }
        }
        curr = "";
        for (int i = 0; i < n2; i++)
        {
            if (s2[i] == ' ')
            {
                mpp[curr]++;
                curr = "";
            }
            else if (i == n2 - 1)
            {
                curr += s2[i];
                mpp[curr]++;
            }
            else
            {
                curr += s2[i];
            }
        }
        // For Debugging
        cout << "Printing map: \n";
        for (auto i : mpp)
            cout << "First : " << i.first << " Second : " << i.second << "\n";
        for (auto i : mpp)
            if (i.second == 1)
                ans.push_back(i.first);
        return ans;
    }
};