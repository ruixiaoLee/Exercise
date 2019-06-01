//#include<stack>
//stack函数中的常用函数有：pop(),push(), swap(), empty(), size(), top()
//pop()从上推出
//push()从上推出
//empty()是否是空stack
//size()大小
//top()取得最上面的

bool isValid(string s) {
  std::stack<char> sta;
  for(int i=0 ; i<s.size() ; i++){
    //cout<<"s[i] "<<s[i]<<endl;
    if(sta.empty() && (s[i]=='}' || s[i]==']' || s[i]==')')) return false; 
    if(s[i]=='}' && sta.top()=='{') sta.pop();
    else if(s[i]==']' && sta.top()=='[') sta.pop();
    else if(s[i]==')' && sta.top()=='(') sta.pop();
    else {
      sta.push(s[i]);}
  }
  //cout<<"size is "<<sta.size()<<endl;
  if(sta.empty()) return true;
  else return false;
}
