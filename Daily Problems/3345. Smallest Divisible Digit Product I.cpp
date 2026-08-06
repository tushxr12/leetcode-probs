class Solution {
public:
    int getProduct(string s)
    {
        int ans = 1;
        for(int i = 0;i < s.size();i++)
        {
            ans *= (s[i] - '0');
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        for(int i = n;;i++)
        {
            string currNum = to_string(i);
            int prod = getProduct(currNum);
            if(prod%t == 0)
                return i;
        }
        return -1;
    }
};
