class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        bool zeroesPresent = false, onesPresent = false;
        for(auto i : s)
        {
            if(i == '0')
            {
                zeroesPresent = true;
                // break;
            }
            else
            {
                onesPresent = true;
                // break;
            }
        }

        if(!zeroesPresent || !onesPresent)
        {
            return (s.size() - 1);
        }
        int n = s.size();
        vector<int> zeroesPrefixSum(n), onesPrefixSum(n);
        zeroesPrefixSum[0] = s[0] == '0' ? 1 : 0;
        for(int i = 1;i < n;i++)
        {
            char curr = s[i];
            if(curr == '0')
            {
                zeroesPrefixSum[i] = (zeroesPrefixSum[i - 1] + 1);
            }
            else
            {
                zeroesPrefixSum[i] = zeroesPrefixSum[i - 1];
            }
        }

        onesPrefixSum[n - 1] = s[n - 1] == '1' ? 1 : 0;

        for(int i = n - 2;i >= 0;i--)
        {
            char curr = s[i];
            if(curr == '1')
            {
                onesPrefixSum[i] = onesPrefixSum[i + 1] + 1;
            }
            else
            {
                onesPrefixSum[i] = onesPrefixSum[i + 1];
            }
        }
        cout<<"Zeroes prefix sum : ";
        for(auto i : zeroesPrefixSum)
            cout<<i<<" ";
        cout<<"\nOnes prefix sum : ";
        for(auto i : onesPrefixSum)
            cout<<i<<" ";
        cout<<"\n";
        for(int i = 0;i < n - 1;i++)
        {
            ans = max(ans, zeroesPrefixSum[i] + onesPrefixSum[i + 1]);
        }
        return ans;
    }
};
