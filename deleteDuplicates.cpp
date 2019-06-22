    ListNode* deleteDuplicates(ListNode* head){
      ListNode *newList=head; 
      if(head==NULL || head->next==NULL) return head;  
      while(newList->next!=NULL){
        if(newList->val != newList->next->val){
         newList=newList->next;
        }
         else newList->next=newList->next->next;
      }
        return head;
    }
