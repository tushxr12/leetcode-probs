class Solution {
public:
    static bool check(int a,int b)
    {
        int s1 = __builtin_popcount(a);
        int s2 = __builtin_popcount(b);

        if(s1 == s2)
            return (a < b);
        return (s1 < s2);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), check);
        return arr;
    }
};
