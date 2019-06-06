#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
using namespace std;

int removeDuplicates(vector<int>& nums) {
  if(nums.empty()) return 0;
  //if(nums.size()==1) return 1;
  vector<int>::iterator iter=nums.begin();
  while(iter+1!=nums.end()){
    if(*iter==*(iter+1)){
      cout<<*iter<<endl;
      nums.erase(iter);
    }
    else ++iter;
  }
  return nums.size();
}
int removeDuplicates2(vector<int>& nums) {
  if(nums.empty()) return 0;
  if(nums.size()==1) return 1;
  int newl=1;
  for(int i=0 ; i<nums.size()-1 ; i++){
    if(nums[i]==nums[i+1]){
      newl--;
    }
    newl++;
  }
  return newl;
}

int main(void){
  vector<int> nums;
  int temp,l;
  cout<<"input l"<<endl;
  cin>>l;
  for(int i=0 ; i<l; i++){
    cin>>temp;
    nums.push_back(temp);
  }
  int s1=removeDuplicates(nums);
  int s2=removeDuplicates2(nums);
  cout<<"size1 is "<<s1<<endl;
  cout<<"size2 is "<<s2<<endl;
  // for(int i=0 ; i<ss ; i++){
  //   cout<<nums[i]<<" ";
  // }

  return 0;
}
