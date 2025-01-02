//Brute force
class Solution {
private:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        int k = 0;
        for(auto i : queries)
        {
            auto currQuery = i; // [0, 2]
            int startIndex = currQuery[0], endIndex = currQuery[1];
            int cnt = 0;
            for(int i = startIndex; i <= endIndex;i++)
            {
                string currWord = words[i];
                int currWordSize = currWord.size();
                if(isVowel(currWord[0]) && isVowel(currWord[currWordSize - 1]))
                {
                    cnt++;
                }
            }
            ans[k] = cnt;
            k++;
        }
        return ans;
    }
};

//Optimal
class Solution {
private:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n);
        int k = 0;

        //Calculating prefix sum
        vector<int> prefSum(words.size());
        if(isVowel(words[0][0]) && isVowel(words[0][words[0].size() - 1]))
        {
            prefSum[0] = 1;
        }
        for(int i = 1;i < words.size();i++)
        {
            string currString = words[i];
            if(isVowel(currString[0]) && isVowel(currString[currString.size() - 1]))
            {
                prefSum[i] = prefSum[i - 1] + 1;
            }
            else
            {
                prefSum[i] = prefSum[i - 1];
            }
        }
        // cout<<"Pref Sum : ";
        // for(auto i : prefSum)
        //     cout<<i<<" ";
        // cout<<"\n";
        
        for(auto i : queries)
        {
            auto currQuery = i; // [0, 2]
            int startIndex = currQuery[0], endIndex = currQuery[1];
            // int cnt = 0;
            if(startIndex == 0)
            {
                ans[k] = prefSum[endIndex];
            }
            else
            {
                ans[k] = prefSum[endIndex] - prefSum[startIndex - 1];
            }
            k++;
        }
        return ans;
    }
};
