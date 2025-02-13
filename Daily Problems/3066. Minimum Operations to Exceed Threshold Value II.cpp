class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue <long long, vector<long long>, greater<long long>> pq;
        for(auto i : nums)
            pq.push(i);
        
        int op = 0;
        while(pq.size() >= 2)
        {
            long long first = pq.top();
            if(first >= k)
                break;
            pq.pop();
            long long second = pq.top();
            pq.pop();
            long long operation = min(first,second)*2 + max(first,second);
            op++;
            pq.push(operation);
        }
        return op;
    }
};
