#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class linked_list{
    public:
    int data;
    linked_list *next;
    
    linked_list(){
        this->next=NULL;
    }
    
    linked_list(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    
    linked_list * add(int data,linked_list *head)
    {
        if(head==NULL)
        {
            head=new linked_list(data);
            return head;
        }
        linked_list *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new linked_list(data);
        return head;
    }
    
    void print(linked_list*head)
    {
        linked_list*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"<-";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    
    linked_list *middle(linked_list*head)
    {
        linked_list *sp=head;
        linked_list *fp=head;
        while(fp!=NULL && fp->next!=NULL)
        {
            sp=sp->next;
            fp=fp->next->next;
        }
        return sp;
    }
    
    linked_list* delete_middle(linked_list *head)
    {
        linked_list*prev=head;
        linked_list*sp=head;
        linked_list*fp=head;
        while(fp!=NULL && fp->next!=NULL)
        {
            prev=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        prev->next=sp->next;
        delete sp;
        return head;
    }
    
    
    linked_list * delete_Linked_List(linked_list *head)
    {
        linked_list*prev=head;
        head=head->next;
        if(head==NULL)
        delete prev;
        while(head!=NULL)
        {
            delete prev;
            prev=head;
            head=head->next;
        }
        delete prev;
        return head;
    }
    
    void recursive_reverse_print(linked_list*head)
    {
        if(head==NULL)
        {cout<<"NULL";
        return;}
        recursive_reverse_print(head->next);
        cout<<"<-"<<head->data;
    }
    
    linked_list * reverse_linked_list(linked_list*head)
    {
        if(head->next==NULL)
        return head;
        linked_list*reversehead=reverse_linked_list(head->next);
        head->next->next=head;
        head->next=NULL;
        return reversehead;
    }
    
    void reverse_list(linked_list*start,linked_list*end)
    {
        linked_list*prev=NULL;
        linked_list*cur=start;
        linked_list*n=start->next;
        while(prev!=end)
        {
            cur->next=prev;
            prev=cur;
            cur=n;
            if(n!=NULL)n=n->next;
        }
    }
    
    linked_list * reverse_k_group(linked_list*head,int k)
    {
        if(head==NULL || head->next==NULL||k==1)
        return head;
        linked_list *dummy=new linked_list(-1);
        dummy->next=head;
        linked_list *beforestart=dummy,*end=head;
        int i=0;
        while(end!=NULL)
        {
            i++;
            if(i%k==0)
            {
                linked_list *start=beforestart->next,*temp=end->next;
                reverse_list(start,end);
                beforestart->next=end;
                start->next=temp;
                beforestart=start;
                end=temp;
            }
            else
            end=end->next;
        }
        return dummy->next;
    }
    
  /*  linked_list *merge_two_sorted_list(linked_list*h1,linked_list*h2)
    {
        if(h1==NULL)return h2;
        if(h2==NULL)return h1;
        if(h1->data<h2->data)
        {
            h1->next=merge(h1->next,h2);
            return h1;
        }
        else
        {
            h2->next=merge(h1,h2->next);
            return h2;
        }
    }*/
    
    linked_list *delete_duplicates(linked_list*head)
    {
        if(head==NULL ||head->next==NULL)
        return head;
        linked_list *newhead=delete_duplicates(head->next);
        if(head->data==newhead->data)
        return newhead;
        else{
        head->next=newhead;
        return head;}
    }
    
     bool hasCycle(linked_list *head) {
        linked_list *sp=head,*fp=head;
        while(fp!=NULL && fp->next!=NULL)
        {
            sp=sp->next;
            fp=fp->next->next;
            if(sp==fp)
                return true;
        }
        return false;
    }
};

int main()
{
  linked_list*head=NULL;
  head=head->add(1,head);
  head=head->add(2,head);
  head=head->add(2,head);
  head=head->add(3,head);
  head=head->add(4,head);
  head->print(head);
  head=head->delete_duplicates(head);
  head->print(head);
 // cout<<endl;
  cout<<head->hasCycle(head);

    return 0;
}
