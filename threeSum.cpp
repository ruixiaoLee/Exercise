#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int> > result;
  vector<int> newline;
  if(nums.size()<3) return result;
  for(int a=0 ; a<nums.size()-2 ; ++a){
    if(a>0 && nums[a]==nums[a-1]) continue;
    int b=a+1; int c=nums.size()-1;
    while(b<c){
      if(nums[a]+nums[b]+nums[c]>0) --c;
      else if(nums[a]+nums[b]+nums[c]<0) ++b;
      else{
        result.push_back({nums[a],nums[b],nums[c]});
        do ++b; while(nums[b]==nums[b-1] && b<c);
        do --c; while(nums[c]==nums[c+1] && b<c);
      }
    }
  }
  return result;
}

int main(void){
  vector<int> nums;
  nums.push_back(-1);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(-1);
  nums.push_back(-4);
  // nums.push_back(8);
  // nums.push_back(3);
  // nums.push_back(7);
  vector<vector<int> > sum=threeSum(nums);
  for(int i=0 ; i<sum.size() ; i++){
    for(int j=0 ; j<sum[i].size() ; j++){
      cout<<sum[i][j]<<" ";
    }cout<<endl;
  }

  return 0;
}
