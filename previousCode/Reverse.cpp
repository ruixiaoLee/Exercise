#include <iostream>
#include <climits>
#include <string>
using namespace std;
int hell(int x){
  string ss = to_string(x);
  string ff;
  int size = ss.size();
  int fsize = ss.size();

  for(int i=size-1 ; i>0 ; i--){
    if(ss[i]!='0') break;
    else{
      fsize--;
    }
  }
  int d=fsize;
  ff.resize(fsize);

  for(int i=0 ; i<fsize ; i++){
    if(ss[i]=='-') {
      ff[i]='-';
    }else{
      ff[i]=ss[d-1];
      d--;
    }
    cout << ff[i];
  }
  //cout << "ff: " << ff << endl;
  cout << INT_MAX <<endl;
  cout << x << endl;
  long re=atol(ff.c_str());
  if(INT_MAX<re||re<INT_MIN) return 0;
  else return (int)re;
}
//from leetcode
int reverse(int x){
  long long int ans=0;
  while(x!=0)
  {
      ans=(ans*10) +(x%10);
      x/=10;
      if(ans> INT_MAX)
          return 0;
      if(ans<INT_MIN)
          return 0;
  }
  return ans;
}
int main(){
  int x=-2147483648;
  cout<<hell(x)<<endl;
  cout<<reverse(x)<<endl;
  return 0;
}
