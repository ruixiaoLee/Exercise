#include<vector>
#include<iostream>
#include<string>
using namespace std;
//#67
string addBinary(string a, string b){
  if(a.size()<b.size()){
    string c=a;
    a=b;
    b=c;
  }//a is longer than b
  string sum;
  int i=1,carry=0;
  int s;
  int len=a.length();
  while(len--){
    if(i>b.size())
      s=a[a.size()-i]-'0'+carry;
    else
      s=a[a.size()-i]+b[b.size()-i]-'0'-'0'+carry;
    if(s==2){
      carry=1;
      sum.insert(sum.begin(),'0');
    }else if(s==1){
      carry=0;
      sum.insert(sum.begin(),'1');
    }else if(s==3){
      carry=1;
      sum.insert(sum.begin(),'1');
    }else{
      carry=0;
      sum.insert(sum.begin(),'0');
    }
    ++i;
  }
  if(carry==1) sum.insert(sum.begin(),'1');
  return sum;
}

int main(void){
  string a="11";
  string b="1";
  string c=addBinary(a,b);
  cout<<c<<endl;
  return 0;
}
