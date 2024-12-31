class Solution {
private:
    unordered_set<int> st;
    int f(vector<int> &days, vector<int> &costs, int currDay)
    {
        if(currDay > days[days.size() - 1])
            return 0;
        
        if(st.find(currDay) == st.end())
            return 0 + f(days, costs, currDay + 1);
        
        int oneDay = costs[0] + f(days, costs, currDay + 1);
        int sevenDays = costs[1] + f(days, costs, currDay + 7);
        int thirtyDays = costs[2] + f(days, costs, currDay + 30);
        return min({oneDay, sevenDays, thirtyDays});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto i : days)
            st.insert(i);
        
        return f(days, costs, days[0]);
    }
};

//Memoization
class Solution {
private:
    unordered_set<int> st;
    int f(vector<int> &days, vector<int> &costs, int currDay, vector<int> &dp)
    {
        if(currDay > days[days.size() - 1])
            return 0;
        
        if(dp[currDay] != -1)
            return dp[currDay];
        
        if(st.find(currDay) == st.end())
            return dp[currDay] = 0 + f(days, costs, currDay + 1, dp);
        
        int oneDay = costs[0] + f(days, costs, currDay + 1, dp);
        int sevenDays = costs[1] + f(days, costs, currDay + 7, dp);
        int thirtyDays = costs[2] + f(days, costs, currDay + 30, dp);
        return dp[currDay] = min({oneDay, sevenDays, thirtyDays});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto i : days)
            st.insert(i);

        int maxi = days[days.size() - 1];
        vector<int> dp(maxi + 1, -1);
        return f(days, costs, days[0], dp);
    }
};

//Tabulation
class Solution {
private:
    unordered_set<int> st;
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(auto i : days)
            st.insert(i);

        int maxi = days[days.size() - 1] + 30;
        vector<int> dp(maxi + 1, 0);

        int n = days.size();


        for(int day = days[n - 1]; day >= 0;day--)
        {
            if(st.find(day) == st.end())
            {
                dp[day] = 0 + dp[day + 1];
                continue;
            }
                
            int oneDay = costs[0] + dp[day + 1];
            int sevenDays = costs[1] + dp[day + 7];
            int thirtyDays = costs[2] + dp[day + 30];
            dp[day] = min({oneDay, sevenDays, thirtyDays});
        }

        return dp[days[0]];
    }
};
