class Solution {
public:
    typedef pair<long long,int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(begin(meetings), end(meetings));

        vector<int> roomUsedCount(n,0);

        priority_queue<P, vector<P>, greater<P>> usedRooms;
        priority_queue<int, vector<int> , greater<int>> availableRooms;

        for(int room = 0; room < n; room++){
            availableRooms.push(room);
        }

        for(vector<int> &meet : meetings)
        {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;

            // used rooms mein se available vaalo ko availableRooms mein dalo
            while(!usedRooms.empty() && usedRooms.top().first <= start){
                int room = usedRooms.top().second;
                usedRooms.pop();
                availableRooms.push(room);
            }

            // Check if any room is avaible
            if(!availableRooms.empty())
            {
                int room = availableRooms.top();
                availableRooms.pop();

                usedRooms.push({end, room});
                roomUsedCount[room]++;
            }
            else
            {
                // Koi available room nhi tha, check jo sbse pehle khtm hga
                int room = usedRooms.top().second;
                long long endTime = usedRooms.top().first;

                usedRooms.pop();
                usedRooms.push({endTime + duration,room});
                roomUsedCount[room]++;
            }
        }

        int ans = -1;
        int maxUsed = 0;

        for(int room = 0; room < n;room++){
            if(roomUsedCount[room] > maxUsed)
            {
                maxUsed = roomUsedCount[room];
                ans = room;
            }
        }

        return ans;
    }
};
