// Recursion approach:
class Solution {
public:
    bool solve(int index, string &s, int cnt, vector<vector<int>> &dp)
    {
        if(cnt < 0)
            return false;

        if(index >= s.size()){
            return (cnt == 0);
        }

        if(dp[index][cnt] != -1)
            return dp[index][cnt];

        if(s[index] == '('){
            return dp[index][cnt] = solve(index+1,s,cnt+1,dp);
        }
        else if(s[index] == ')'){
            return dp[index][cnt] = solve(index+1,s,cnt-1, dp);
        }
        else
        {
            bool open = solve(index+1,s,cnt+1,dp);
            bool close = solve(index+1,s,cnt-1,dp);
            bool neutral = solve(index+1,s,cnt,dp);
            return dp[index][cnt] = (open || close || neutral);
        }
        return dp[index][cnt] = false;
    }

    bool checkValidString(string s) {
        int n = s.size();
        int cnt = 0;

        vector<vector<int>> dp(n, vector<int>(n,-1));

        return solve(0,s,cnt,dp);
    }
};

// Range based approach:
class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;

        for(auto i : s){
            if(i == '('){
                mini += 1;
                maxi += 1;
            }
            else if(i == ')'){
                mini -= 1;
                maxi -= 1;
            }
            else
            {
                mini -= 1;
                maxi += 1;
            }

            if(mini < 0)
                mini = 0;
            
            if(maxi < 0)
                return false;
        }
        return (mini == 0);
    }
};
