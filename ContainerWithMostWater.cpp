#include <vector>
#include <iostream>
using namespace std;
//from leetcode
int maxArea1(vector<int>& height) {
    int maxArea = 0, left = 0, right = height.size()-1;
    while (left < right) {
        int area = min(height[left],height[right])*(right-left);
        maxArea = max(maxArea, area);
        // Smaller of the two moves inward
        if (height[left] < height[right])
            left++; // left smaller
        else
            right--; // right smaller or equal
    }
    return maxArea;
}

int maxArea(vector<int>& height){
  int n=height.size();
  int dp[n];//到点0～n的最大区域大小
  dp[1]=min(height[0],height[1]);
  int higher,lower;
  //初始化maxArea的左右坐标点
  if(height[0]<height[1]){higher=1; lower=0;}
  else {higher=0; lower=1;}
  if(n==2) return min(height[0],height[1]);
  //
  for(int i=2 ; i<n ; i++){
    int maxA=0;
    for(int j=0 ; j<i ; j++){
      int smaller=min(height[i],height[j]);
      if(smaller*(i-j)>maxA) maxA=smaller*(i-j);
    }
    dp[i]=max(maxA,dp[i-1]);
    cout<<dp[i]<<endl;
  }
  int maxSpace=0;
  for(int j=1 ; j<n ; j++){
    maxSpace=max(maxSpace,dp[j]);
  }
  return maxSpace;
}

int main(void){
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(8);
  nums.push_back(6);
  nums.push_back(2);
  nums.push_back(5);
  nums.push_back(4);
  nums.push_back(8);
  nums.push_back(3);
  nums.push_back(7);
  cout<<maxArea(nums)<<endl;
  return 0;
}
