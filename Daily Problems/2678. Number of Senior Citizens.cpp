class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int ans = 0;
        for (int i = 0; i < details.size(); i++)
        {
            string curr = details[i];
            string age = "";
            age += curr[11];
            age += curr[12];
            if (stoi(age) > 60)
                ans++;
        }
        return ans;
    }
};