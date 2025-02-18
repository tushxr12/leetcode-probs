class Solution {
private:
    bool check(string &perm, string &pattern)
    {
        for(int i = 0;i < pattern.size();i++)
        {
            if(pattern[i] == 'I')
            {
                if(perm[i] > perm[i + 1])
                    return false;
            }
            else
            {
                if(perm[i] < perm[i + 1])
                    return false;
            }
        }
        return true;
    }
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string seq = "";
        for(int i = 1;i <= n + 1;i++)
        {
            seq.push_back(i + '0');
        }
        string perm = seq;

        while(!check(perm, pattern))
        {
            next_permutation(perm.begin(), perm.end());
        }
        return perm;
    }
};
