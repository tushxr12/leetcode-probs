class Solution {
private:
    bool backtrack(int index, vector<bool> &used, vector<int> &seq, int n)
    {
        while(index < seq.size() && seq[index] != 0)
            index++;
        
        if(index == seq.size())
            return true;
        
        for(int i = n; i >= 1;i--)
        {
            if(used[i]) 
                continue;
            
            if(i == 1)
            {
                seq[index] = i;
                used[i] = true;
                if(backtrack(index + 1, used, seq, n))
                    return true;
                seq[index] = 0;
                used[i] = false;
            }
            else if(index + i < seq.size() && seq[index + i] == 0)
            {
                seq[index] = i;
                seq[index + i] = i;
                used[i] = true;
                if(backtrack(index + 1, used, seq, n))
                    return true;
                seq[index] = 0;
                seq[index+i] = 0;
                used[i] = false;
            }
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<bool> used(n + 1, 0);
        vector<int> seq(2*n - 1);
        backtrack(0, used, seq, n);
        return seq;
    }
};
