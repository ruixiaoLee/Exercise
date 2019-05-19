    bool isPalindrome(int x) {
      long int str=labs(x);
      //cout<<"str: "<<str<<endl;
      long ans=0;
      while(str != 0){
        ans = str%10 + ans*10;
        str/=10;
      }
      //cout<<"ans: "<<ans<<endl;
      if(ans>INT_MAX) return false;
      if(x>=0 && x==ans) return true;
      else return false;
    }
    
