#include<iostream>
#include<vector>
//#include<climits>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int dp=nums[0];//子串最大和
    int sum=dp;//全局最大和
    for(int i=1 ; i<nums.size() ; i++){
        dp=max(dp+nums[i], nums[i]);//更新dp为（dp加上下一个数字，下个数字本身大）中较大的
        sum=max(dp,sum);//如果子串最大和比全局大则更新全局
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
