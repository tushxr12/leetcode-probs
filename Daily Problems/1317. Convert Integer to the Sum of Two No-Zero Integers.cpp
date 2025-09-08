class Solution {
private:
    bool checkIfContainsZero(int x)
    {
        string s = to_string(x);
        for(auto i : s)
            if(i == '0')
                return false;
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;

        for(int i = 1;i <= n;i++){
            int a = i;
            int b = n - i;

            if(checkIfContainsZero(a) && checkIfContainsZero(b)){
                return {a,b};
            }
        }
        return ans;
    }
};
