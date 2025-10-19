#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller,Node *&larger,int pivot){
  if(head==NULL){
    //must initzliae the lists
    smaller=NULL;
    larger=NULL;
    return;
  }
  //temp holder of head
  Node* tempy=head;
  //sperates rest of body with this one
  Node* cont=head->next;

//now we have the old head isolated till the
//following recursive call returns
  head=cont;
  llpivot(head,smaller,larger,pivot);
  
  if(pivot>=tempy->val){
    Node* temp=tempy;
    Node* older=smaller;
    //temp->next=NULL;
    //smaller=tempy;
    //starting at the temp right now then connect to the preivous one so 
    //order is preserved
    smaller=temp;
    temp->next=older;
  }
  else{
    Node* temp=tempy;
    Node* older=larger;
    //larger=tempy;
    //larger->next=temp;
    //larger now starting at temp then connectin to the past connectION
    larger=temp;
    temp->next=older;

  }
}
