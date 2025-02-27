class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        set<int> st;
        for(auto i : arr)
            st.insert(i);
        
        int maxLen = 0;
        for(int i = 0;i <n;i++)
        {
            for(int j = i + 1;j < n;j++)
            {
                int prev = arr[j];
                int curr = arr[i] + arr[j];
                int len = 2;
                while(st.find(curr) != st.end())
                {
                    int temp = curr;
                    curr += prev;
                    prev = temp;
                    maxLen = max(maxLen, ++len);
                }
            }
        }
        return maxLen;
    }
};
