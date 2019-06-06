    int removeElement(vector<int>& nums, int val) {
      if(nums.empty()) return 0;
      vector<int>::iterator iter=nums.begin();
      while(iter!=nums.end()){
        if(*iter==val){
          //cout<<*iter<<endl;
          nums.erase(iter);
        }
        else ++iter;
      }
      return nums.size();
    }
