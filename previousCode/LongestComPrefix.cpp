#include <iostream>
#include <climits>
#include <string>
#include <vector>
using namespace std;

string max_string(string &str1, string &str2){
  int a=0;
  int max_length = 0;
  int new_max_length=0;
  vector<char> max_str_ch, new_str;
  int row=str1.size();
  int col=str2.size();

  while(a<min(row,col)){
    if(str1[a]==str2[a]){
      new_max_length++;
      max_str_ch.push_back(str1[a]);
      if(new_max_length>max_length) {
          max_length=new_max_length;
          new_str.assign(max_str_ch.begin(),max_str_ch.end());
        }
    }else{break;
    }
    a++;
  }

  string max_str(new_str.begin(), new_str.end());
  if(max_str.empty()) return "";
  else return max_str;
}

string longestCommonPrefix(vector<string>& strs) {
  if(strs.empty()) return "";
  else{
    for(int j=0 ; j<strs.size() ; j++){
      if(strs[j].empty()) return "";
    }
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

int main(void){
  vector<string> strs;
  string tmp;

  while (cin>>tmp){
  strs.push_back(tmp);
  }
  cout<<longestCommonPrefix(strs)<<endl;
  return 0;
}


//from leetcode
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) return "";
    int i = -1;
    while(strs[0][++i])
        for(int j = 0;j < strs.size();j++)
            if(strs[j][i] != strs[0][i]) return strs[0].substr(0,i);
    return strs[0].substr(0,i);
}
