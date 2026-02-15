class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1;
        int n = b.size() - 1;

        string res = "";
        int sum = 0, carry = 0;

        while(m >= 0 || n >= 0)
        {
            sum = carry;

            if(m >= 0){
                sum += a[m] - '0';
                m--;
            }

            if(n >= 0){
                sum += b[n] - '0';
                n--;
            }

            res.push_back((sum%2 == 0) ? '0' : '1');
            carry = (sum > 1) ? 1 : 0;
        }
        if(carry)
            res.push_back('1');
        reverse(begin(res), end(res));
        return res;
    }
};
