#include <iostream>
#include <climits>
#include <string>
#include <vector>
using namespace std;

string max_string(string &str1, string &str2){
  vector<vector<int> > map;
  vector<int> map_r;
  int max_length = 0;
  int new_max_length=0;
  vector<char> max_str_ch, new_str;
  int row=str1.size();
  int col=str2.size();
  for(int i=0 ; i<row ; i++){
    for(int j=0 ; j<col ; j++){
      if(str1[i]==str2[j]) map_r.push_back(1);
      else map_r.push_back(0);
    }
    map.push_back(map_r);
    map_r.clear();
  }
  //cout<<"map OK"<<endl;

  for(int i=0 ; i<row ; i++){
    for(int j=0 ; j<col ; j++){
      //cout<<map[i][j]<<" ";
    }
    //cout<<endl;
  }

  int a,b;
  for(int k=0 ; k<row ; k++){
    for(int s=0 ; s<col ; s++){
      a=k; b=s;
      //cout<<"row "<<k<<" col "<<s<<endl;
      new_max_length=0;
      max_str_ch.clear();
        while(a<=row-1 && b<=col-1){
          //cout<<"a: "<<a<<" b: "<<b<<endl;
          if(map[a][b]==1){
            new_max_length++;
            //cout<<"l: "<<new_max_length<<endl;
            //cout<<"a:"<<a<<" str[a]: "<<str1[a]<<endl;
            max_str_ch.push_back(str1[a]);
            //cout<<"max_str_ch size: "<<max_str_ch.size()<<endl;
            if(new_max_length>=max_length) {
                max_length=new_max_length;
                new_str.assign(max_str_ch.begin(),max_str_ch.end());
                for(int y=0; y<max_str_ch.size() ; y++){
                  //cout<<"new: ";
                  //cout<<max_str_ch[y]<<" ";
                }
                //cout<<"newl: "<<max_length<<endl;
                //max_str_ch.clear();
              }
            }else{
              new_max_length=0;
              max_str_ch.clear();
              //new_str.clear();
          }
          a++; b++;
        }//cout<<endl;
    }
  }
  string max_str(new_str.begin(), new_str.end());
  //cout<<endl;
  if(max_str.empty()) return "";
  else return max_str;
}

string longestCommonSubstring(vector<string>& strs) {
  if(strs.size()==0) return "";
  else{
    int len = strs.size();
    string str1 = strs[0];
    string str2;
    //cout<<"find max string"<<endl;
    for(int i=1 ; i<len ; i++){
      //cout<<"row num: "<<i<<endl;
      str2=strs[i];
      //cout<<"str1:"<<str1<<endl;
      str1 = max_string(str1, str2);
      //cout<<"new str1:"<<str1<<endl;
      //cout<<"str2:"<<str2<<endl;
    }
    return str1;
  }
}

int main(){
  vector<string> strs;
  string tmp;
  for(int i=0 ; i<3 ; i++){
    //cout<<"input: "<<endl;
    cin>>tmp;
    strs.push_back(tmp);
    //cout<<"your num: "<<strs[i]<<endl;
  }
  //cout<<"ok"<<endl;

  cout<<longestCommonSubstring(strs)<<endl;
  return 0;
}
