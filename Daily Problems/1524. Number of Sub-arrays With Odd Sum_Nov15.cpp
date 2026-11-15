class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int mod = 1e9 + 7;
        int sum = 0;
        int cnt = 0, odd = 0, even = 1;
        
        for(int i = 0;i < n;i++)
        {
            sum += arr[i];
            if(sum%2 == 0)
            {
                ans = (ans + odd)%mod;
                even++;
            }
            else
            {
                ans = (ans + even)%mod;
                odd++;
            }
        }
        return ans;
    }
};
