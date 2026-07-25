class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(begin(s),end(s));
        int size = s.size();
        int ans = (s[size-1] - '0') * (s[size-2] - '0');
        return ans;
    }
};
