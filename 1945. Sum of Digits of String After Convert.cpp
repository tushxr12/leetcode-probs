class Solution
{
public:
    int getLucky(string s, int k)
    {
        string numberStrings = "";
        for (auto i : s)
            numberStrings += to_string(i - 'a' + 1);
        // cout<<numberStrings<<"\n";
        while (k--)
        {
            int sum = 0;
            for (auto i : numberStrings)
                sum += (i - '0');
            numberStrings = to_string(sum);
        }
        return stoi(numberStrings);
    }
};