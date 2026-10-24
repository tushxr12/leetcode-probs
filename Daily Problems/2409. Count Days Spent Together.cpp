class Solution {
public: 
    vector<int> cumMonthDays;
    int findDayOfYear(string date)
    {
        int month = stoi(date.substr(0,2));
        int days = stoi(date.substr(3));

        return cumMonthDays[month-1] + days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        cumMonthDays.resize(13,0);
        cumMonthDays[1] = 31;
        for(int i = 2;i <= 12;i++)
        {
            cumMonthDays[i] = cumMonthDays[i-1] + monthDays[i-1];
        }

        int arriveAlliceDay = findDayOfYear(arriveAlice);
        int leaveAlliceDay = findDayOfYear(leaveAlice);
        int arriveBobDay = findDayOfYear(arriveBob);
        int leaveBobDay = findDayOfYear(leaveBob);

        int ans = min(leaveBobDay,leaveAlliceDay) - max(arriveAlliceDay,arriveBobDay) + 1;
        
        return ans< 0 ? 0 : ans;
    }
};
