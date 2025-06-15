class Solution {
private:
    bool isPalindrome(int i,int j, string s)
    {
        while(i < j)
        {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while(i < j)
        {
            if(s[i] != s[j])
                return (isPalindrome(i + 1,j,s) || isPalindrome(i, j - 1,s));
            i+=1;
            j-=1;
        }
        return true;
    }
};
