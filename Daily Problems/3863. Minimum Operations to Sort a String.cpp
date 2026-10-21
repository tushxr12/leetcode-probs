class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if(is_sorted(begin(s), end(s)))
            return 0;
        
        if(n == 2)
            return -1;
        
        char minChar = *min_element(begin(s), end(s));
        char maxChar = *max_element(begin(s), end(s));

        if(s[0] == minChar || s[n-1] == maxChar)
            return 1;
        
        char maxMid = *max_element(begin(s)+1, end(s)- 1);
        char minMid = *min_element(begin(s)+1, end(s)- 1);

        if(s[0] > maxMid && s[n-1] < minMid)
            return 3;
        return 2;
    }
};
