class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        long long ans = 0;
        int n = s.size() - 1;

        while (n >= 0 && s[n] == ' ')
            n--;

        while (n >= 0 && s[n] != ' ')
        {
            ans++;
            n--;
        }

        cout << ans << "\n";
        return ans;
    }
};