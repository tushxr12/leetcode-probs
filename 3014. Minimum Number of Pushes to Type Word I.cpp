class Solution
{
public:
    int minimumPushes(string word)
    {
        map<char, int> mpp;
        for (auto i : word)
            mpp[i]++;

        vector<pair<int, char>> v;
        for (auto i : mpp)
        {
            v.push_back({i.second, i.first});
        }

        sort(v.begin(), v.end(), greater<pair<int, char>>());

        for (auto i : v)
        {
            cout << i.first << "\n";
        }

        int ans = 0, cnt = 0;
        for (auto i : v)
        {
            cnt++;
            if (cnt <= 8)
                ans += i.first;
            else if (cnt <= 16)
                ans += (2 * i.first);
            else if (cnt <= 24)
                ans += (3 * i.first);
            else
                ans += (4 * i.first);
        }
        return ans;
    }
};