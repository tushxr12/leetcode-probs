class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        for(auto i : shifts)
        {
            auto currShift = i; //[0,1,0]
            int startIndex = currShift[0], endIndex = currShift[1], direction = currShift[2];

            if(direction == 0)
            {
                for(int i = startIndex;i <= endIndex;i++)
                {
                    if(s[i] == 'a')
                        s[i] = 'z';
                    else
                        s[i]--;   
                }
            }
            else
            {
                for(int i = startIndex;i <= endIndex;i++)
                {
                    if(s[i] == 'z')
                        s[i] = 'a';
                    else
                        s[i]++;   
                }
            }
        }
        return s;
    }
};

//Better
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> arr(n);

        for(auto i : shifts)
        {
            if(i[2] == 1)
            {
                arr[i[0]]++;
                if(i[1] + 1 < n)
                    arr[i[1] + 1]--;
            }
            else
            {
                arr[i[0]]--;
                if(i[1] + 1 < n)
                    arr[i[1] + 1]++;
            }
        }   

        string ans = "";
        int sum = 0;
        for(int i  = 0;i < n;i++)
        {
            sum = (sum + arr[i])%26;
            if(sum < 0)
                sum += 26;
            char newChar = (char)('a' + (s[i] - 'a' + sum) % 26);
            ans += newChar;
        }
        return ans;
    }
};
