class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int res = 0;
        int i = 0;
        int oneCount = 0;

        while(i < n){
            if(s[i] == '0'){
                res += oneCount;
                while(i < n && s[i] == '0')
                    i++;
            }
            else
            {
                oneCount++;
                i++;
            }
        }
        return res;
    }
};
