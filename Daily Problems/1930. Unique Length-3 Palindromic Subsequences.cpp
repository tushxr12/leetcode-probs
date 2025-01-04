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

//Better
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<char> st;
        for(auto i : s)
            st.insert(i);
        cout<<st.size(); // Count of unique chars
        int ans = 0;
        for(auto ch : st)
        {
            int first = -1, last = -1;
            //aabca
            for(int i = 0;i < s.size();i++)
            {
                if(ch == s[i])
                {
                    if(first == -1)
                    {
                        first = i;
                    }
                    last = i;
                }
            }  
            if(first == last)
                continue;
            set<char> st1;
            for(int i = first + 1;i < last;i++)
            {
                st1.insert(s[i]);
            }
            ans += (st1.size());
        }
        return ans;
    }
};
