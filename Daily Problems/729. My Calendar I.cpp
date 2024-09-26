class MyCalendar
{
private:
    map<int, int> mpp;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        mpp[start]++;
        mpp[end]--;
        int sum = 0;
        for (auto i : mpp)
        {
            sum += i.second;
            if (sum > 1)
            {
                mpp[start]--;
                mpp[end]++;
                return false;
            }
        }
        return true;
    }
};