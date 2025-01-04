class Solution {
private:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            if(s[left] != s[right]) 
                return false;
            left++;
            right--;
        }
        return true;
    }

    void generateSubsequences(const std::string& str, int index, std::string current, std::set<std::string>& subsequences) {
    if (index == str.length()) {
        subsequences.insert(current);
        return;
    }
    
    generateSubsequences(str, index + 1, current + str[index], subsequences);
    
    generateSubsequences(str, index + 1, current, subsequences);
}
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int ans = 0;
        set<string> uniqueSubs;
        generateSubsequences(s, 0, "", uniqueSubs);
        for(auto i : uniqueSubs)
        {
            cout<<i<<"\n Strings size : "<<i.size()<<endl;
            if(isPalindrome(i) && i.size() == 3)
            {
                cout<<"INside\n";
                ans++;
            }
        }
        cout<<"Finshed";
        return ans;
    }
};
