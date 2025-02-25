class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int currSum = 0;
            for(int j = i;j < n;j++)
            {
                currSum += arr[j];
                if(currSum%2)
                    ans++;
            }
        }
        return (ans%mod);
    }
};

//Linear Time
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int n = arr.size();
        int ec = 1, oc = 0, prefSum = 0;
        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            prefSum += arr[i];
            if(prefSum%2)
            {
                ans += ec;
                oc++;
            }
            else
            {
                ans += oc;
                ec++;
            }
            ans %= mod;
        }
        return (ans%mod);
    }
};
