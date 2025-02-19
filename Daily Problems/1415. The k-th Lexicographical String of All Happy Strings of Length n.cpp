class Solution {
private:
    string res;
    int count;

    bool backtrack(int n,int k, string &curr)
    {
        if(curr.size() >= n)
        {
            count++;
            if(count == k)
            {
                res = curr;
                return true;
            }
            return false;
        }

        for(char ch = 'a' ; ch <= 'c'; ch++)
        {
            if(curr.size() > 0 && curr[curr.size() - 1] == ch)
                continue;
            curr += ch;
            if(backtrack(n,k,curr)) 
                return true;
            curr.pop_back();
        }
        return false;
    }
public:
    string getHappyString(int n, int k) {
        count = 0;
        res = "";
        string curr = "";
        backtrack(n,k,curr);
        return res;
    }
};
