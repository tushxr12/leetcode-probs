class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastOne = -1;
        int currOne = -1;

        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 1){
                currOne = i;
                cout<<"Current one index : "<<currOne<<endl;

                if(lastOne != -1){
                    cout<<"Diff : "<<currOne - lastOne<<endl;
                    if(currOne - lastOne - 1 < k){
                        return false;
                    }
                }

                lastOne = i;
                cout<<"Last One index : "<<lastOne<<endl;
            }
        }
        return true;
    }
};
