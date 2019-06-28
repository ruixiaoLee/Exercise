#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int> > result;
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

int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(),nums.end());
  int min=100000;
  for(int a=0 ; a<nums.size()-2 ; ++a){
    int b=a+1,c=nums.size()-1;
    while(b<c){
      int sum=nums[a]+nums[b]+nums[c];
      //cout<<"a:"<<nums[a]<<" b:"<<nums[b]<<" c:"<<nums[c]<<endl;
      if(abs(sum-target)<=abs(min-target)){
        min=sum;
        //cout<<"min:"<<min<<endl;
      }
      if(sum>target) --c;
      else ++b;
    }
  }
  return min;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  sort(nums.begin(),nums.end());
  vector<vector<int> > result;
  if(nums.size()<3) return result;
  for(int a=0 ; a<nums.size()-3 ; ++a){
    if(a>0 && nums[a]==nums[a-1]) continue;
    for(int d=nums.size()-1 ; d>a+2 ;--d){
      if(d<nums.size()-1 && nums[d]==nums[d+1]) continue;
      int b=a+1,c=d-1;
      int need=target-nums[a]-nums[d];
      //cout<<"num[a]:"<<nums[a]<<" num[d]:"<<nums[d]<<endl;
      //cout<<"need:"<<need<<endl;
      while(b<c){
        //cout<<"num[b]:"<<nums[b]<<" b:"<<b<<" num[c]:"<<nums[c]<<" c:"<<c<<endl;
        int sumbc=nums[b]+nums[c];
        if(sumbc<need) ++b;
        else if(sumbc>need) --c;
        else{
          result.push_back({nums[a],nums[b],nums[c],nums[d]});
          //cout<<"push: num[a]:"<<nums[a]<<" num[b]:"<<nums[b]<<" c:"<<nums[c]<<" d:"<<nums[d]<<endl;
          do ++b; while(nums[b]==nums[b-1] && b<c);
          do --c; while(nums[c]==nums[c+1] && b<c);
        }
      }
    }
  }
  return result;
}

int main(void){
  vector<int> nums={1,0,-1,0,-2,2};
  //nums.push_back({-1,2,1,-4});
  vector<vector<int> > sum=fourSum(nums,0);
  //cout<<threeSumClosest(nums,100)<<endl;
  for(int i=0 ; i<sum.size() ; i++){
    for(int j=0 ; j<sum[i].size() ; j++){
      cout<<sum[i][j]<<" ";
    }cout<<endl;
  }
  return 0;
}
