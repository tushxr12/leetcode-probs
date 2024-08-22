class Solution
{
public:
    int findComplement(int num)
    {
        string s = "";
        while (num)
        {
            int rem = num % 2;
            s += to_string(rem);
            num /= 2;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                s[i] = '1';
            else
                s[i] = '0';
        }

        long long complement = 0;
        int power = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                complement += pow(2, power);
            power++;
        }
        return complement;
    }
};