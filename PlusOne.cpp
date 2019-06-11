#include<vector>
#include<iostream>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
  int carry=0;
  vector<int> newNum;
  for(int i=digits.size()-1 ; i>=0 ; --i){
    if(i==digits.size()-1){
      newNum.insert(newNum.begin(),(digits[i]+1)%10);
      if((digits[i]+1)>9) carry=1;
      if(i==0&&carry==1){
        newNum.insert(newNum.begin(),1);
      }
    }else{
      newNum.insert(newNum.begin(),(digits[i]+carry)%10);
      if(digits[i]+carry>9)
        carry=1;
      else
        carry=0;
      if(i==0&&carry==1){
        newNum.insert(newNum.begin(),1);
      }
    }
  }
  return newNum;
}
//from leetcode
//非常简单了可以说..
vector<int> plusOne2(vector<int>& digits) {
		int len = digits.size(), carry=1;
		while(carry && len--)//当carry=0且len=0跳出//注意本题+1刚好和carry=1一样了
			if(digits[len] < 9) {   //0~8//carry默认是1，如果是0～8则更新carry成0
				digits[len] += 1;
				carry = 0;
			}
			else  digits[len] = 0;//当本位是9的时候推入0因为此时carry=1
		if(carry)//while循环出已经算完全部的位如果此时依然有carry则要在前面插入1
			digits.insert(digits.begin(), 1);
		return digits;
}

int main(void){
  vector<int> s(3,8);

  vector<int> k=plusOne(s);
  for(int j=0 ; j<k.size() ; j++){
    cout<<k[j]<<" ";
  }
  return 0;
}
