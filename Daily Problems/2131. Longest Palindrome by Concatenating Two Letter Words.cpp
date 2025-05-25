class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mpp;
        int n = words.size();
        int ans = 0;
        for(auto i : words){
            string reverseWord = i;
            swap(reverseWord[0] , reverseWord[1]);

            if(mpp[reverseWord] > 0){
                ans += 4;
                mpp[reverseWord]--;
            }else{
                mpp[i]++;
            }
        }

        for(auto i : mpp)
        {
            string word = i.first;
            int cnt = i.second;

            if(word[0] == word[1] && cnt > 0)
            {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};
