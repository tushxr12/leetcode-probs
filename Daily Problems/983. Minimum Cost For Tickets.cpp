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
