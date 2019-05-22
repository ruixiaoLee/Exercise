#include <iostream>
#include <climits>
#include <string>
#include <vector>
using namespace std;

string max_string(string &str1, string &str2){
  vector<vector<bool> > map;
  vector<bool> map_r;
  int max_length = 0;
  int new_max_length=0;
  vector<char> max_str_ch, new_str;
  int row=str1.size();
  int col=str2.size();
  for(int i=0 ; i<row ; i++){
    for(int j=0 ; j<col ; j++){
      if(str1[i]==str2[j]) map_r.push_back(true);
      else map_r.push_back(false);
    }
    map.push_back(map_r);
    map_r.clear();
  }

  int a,b;
  for(int k=0 ; k<row ; k++){
    for(int s=0 ; s<col ; s++){
      a=k; b=s;
      new_max_length=0;
      max_str_ch.clear();
        while(a<=row-1 && b<=col-1){
          if(map[a][b]==true){
            new_max_length++;
            max_str_ch.push_back(str1[a]);
            if(new_max_length>=max_length) {
                max_length=new_max_length;
                new_str.assign(max_str_ch.begin(),max_str_ch.end());
              }
            }else{
              new_max_length=0;
              max_str_ch.clear();
          }
          a++; b++;
        }
    }
  }
  string max_str(new_str.begin(), new_str.end());
  if(max_str.empty()) return "";
  else return max_str;
}

string longestCommonPrefix(vector<string>& strs) {
  if(strs.size()==0) return "";
  else{
    int len = strs.size();
    string str1 = strs[0];
    string str2;
    for(int i=1 ; i<len ; i++){
      str2=strs[i];
      str1 = max_string(str1, str2);
    }
    return str1;
  }
}

int main(){
  vector<string> strs;
  string tmp;
  for(int i=0 ; i<3 ; i++){
    cin>>tmp;
    strs.push_back(tmp);
  }
  cout<<longestCommonPrefix(strs)<<endl;
  return 0;
}
