class Solution {
private:
    string convertDecimalToBinary(int n)
    {
        string res = "";
        while(n != 0)
        {
            if(n%2 == 1)
                res += "1";
            else
                res += "0";
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isAllSet(string s)
    {
        for(auto i : s)
            if(i == '0')
                return false;
        
        return true;
    }
public:
    int smallestNumber(int n) {

        for(int i = n;;i++)
        {
            string num = convertDecimalToBinary(i);
            if(isAllSet(num))
            {
                return i;
            }
        }
        return -1;
    }
};
