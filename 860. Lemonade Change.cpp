class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0;
        for (auto i : bills)
        {
            if (i == 5)
                five += 1;
            else if (i == 10)
            {
                if (five)
                {
                    five -= 1;
                    ten += 1;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (ten && five)
                {
                    ten -= 1;
                    five -= 1;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};