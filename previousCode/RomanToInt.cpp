#include <iostream>
#include <climits>
using namespace std;

int RomanToNum(char c){
  int num;
  //cout<<"char: "<<c<<endl;
  switch(c){
    case 'I': num=1; break;
    case 'V': num=5; break;
    case 'X': num=10; break;
    case 'L': num=50; break;
    case 'C': num=100; break;
    case 'D': num=500; break;
    case 'M': num=1000; break;
  }
  // if(c=='I') num=1;
  // else if(c=='V') num=5;
  // else if(c=='X') num=10;
  // else if(c=='L') num=50;
  // else if(c=='C') num=100;
  // else if(c=='D') num=500;
  // else num=1000;
  //cout<<"num: "<<num<<endl;
  return num;
}
int romanToInt(string s) {
  int len=s.size();
  int sum = RomanToNum(s[len-1]);
  for(int i=len-1 ; i>0 ; i--){
    int ans1 = RomanToNum(s[i]);
    int ans2 = RomanToNum(s[i-1]);
    //cout<<"i "<<i<<" ans1 "<<ans1<<" ans2 "<<ans2<<endl;
    if(ans1>ans2)
      sum=sum-ans2;
    else
      sum=sum+ans2;
    cout<<sum<<endl;
  }
  return sum;
}

