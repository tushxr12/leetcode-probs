//Recursion
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

class Solution {
  private:
  int func(int index, int target, vector<int> &arr)
  {
      if(target == 0)
        return 1;
      
      if(index == 0)
        return (arr[index] == target) ? 1 : 0;
      

      //Not take 
      int notTake = func(index - 1, target, arr);

      //Take 
      int take = 0;

      if(arr[index] <= target)
        take = func(index - 1, target - arr[index], arr);
      
      return (take + notTake) % mod;
  }
  public:
   int countPartitions(int n, int diff, vector<int>& arr) {
        int totSum = 0;
        for(auto i: arr)
          totSum += i;
        
        int target = (totSum - diff)/2;

        return func(n - 1, target, arr);
    }
};

//Memoization
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

class Solution {
  private:
  int func(int index, int target, vector<int> &arr, vector<vector<int>>&dp)
  {
      if(target == 0)
        return 1;
      
      if(index == 0)
        return (arr[index] == target) ? 1 : 0;
      
      if(dp[index][target] != -1)
        return dp[index][target];

      //Not take 
      int notTake = func(index - 1, target, arr, dp);

      //Take 
      int take = 0;

      if(arr[index] <= target)
        take = func(index - 1, target - arr[index], arr, dp);
      
      return dp[index][target] = (take + notTake) % mod;
  }
  public:
   int countPartitions(int n, int diff, vector<int>& arr) {
        int totSum = 0;
        for(auto i: arr)
          totSum += i;

        if(totSum - diff < 0)
          return 0;
        
        if((totSum - diff)%2)
          return 0;
        
        int target = (totSum - diff)/2;

        vector<vector<int>> dp(n, vector<int> (target + 1, -1));

        return func(n - 1, target, arr, dp);
    }
};
