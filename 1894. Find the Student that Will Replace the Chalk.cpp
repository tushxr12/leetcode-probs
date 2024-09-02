class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        int n = chalk.size(), ans = -1;
        long long sum = 0;
        for (auto i : chalk)
            sum += i;

        k %= sum;

        for (int i = 0; i < n; i++)
        {
            if (chalk[i] > k)
            {
                ans = i;
                break;
            }
            else
            {
                k -= chalk[i];
            }
        }
        return ans;
    }
};