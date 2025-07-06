class FindSumPairs {
public:
    vector<int> vec1, vec2;
    unordered_map<int,int> mpp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        vec1 = nums1;
        vec2 = nums2;

        for(auto i : vec2) 
            mpp[i]++;
    }
    
    void add(int index, int val) {
        mpp[vec2[index]]--;
        vec2[index] += val;
        mpp[vec2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(auto i : vec1)
            cnt += mpp[tot - i];
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
