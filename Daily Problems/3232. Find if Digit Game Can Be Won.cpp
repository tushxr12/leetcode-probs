class Solution
{
public:
    bool canAliceWin(vector<int> &nums)
    {
        int sd = 0, dd = 0;
        for (auto i : nums)
        {
            if (i < 10)
                sd += i;
            else
                dd += i;
        }

        if (dd == sd)
            return false;
        return true;
    }
};