#include<iostream>
#include<vector>
//#include<climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int dp=nums[0];
    int sum=dp;
    for(int i=1 ; i<nums.size() ; i++){
        dp=max(dp+nums[i], nums[i]);
        sum=max(dp,sum);
    }
    return sum;
}
int main(void){
  vector<int> nums;
  int length,a;
  cout<<"input the length:"<<endl;
  cin>>length;
  for(int i=0 ; i<length ; i++){
    cin>>a;
    nums.push_back(a);
  }
  cout<<"Max sum:"<<maxSubArray(nums)<<endl;
  return 0;
}
