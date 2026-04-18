class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(begin(s), end(s));
        int revInt = stoi(s);

        return abs(n - revInt);
    }
};
