class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if(n == 1){
            return 0;
        }

        if(n == 2){
            if(s[0] == '0' && s[1] == '1')
                return 0;
            if(s[0] == '1' && s[1] == '0')
                return 0;
            return 1;
        }

        int ones = 0, zeroes = 0;
        int mini = INT_MAX;
        int first = s[0];

        int needChanges1 = 0, needChanges2 = 0;
        // assume starting with 1
        for(int i = 0;i < n;i+=2){
            if(s[i] != '1')
                needChanges1++;
        }

        for(int i = 1;i < n;i+=2){
            if(s[i] != '0')
                needChanges1++;
        }

        // Assume starting with 0
        for(int i = 0;i < n;i+=2){
            if(s[i] != '0')
                needChanges2++;
        }

        for(int i = 1;i < n;i+=2){
            if(s[i] != '1')
                needChanges2++;
        }
        return min(needChanges1,needChanges2);
    }
};
