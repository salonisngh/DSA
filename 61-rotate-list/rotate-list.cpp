/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp= head;
        int cnt=1; 
        if(temp==NULL || temp->next==NULL || k==0) return head;
        while(temp->next!=NULL){
            temp=temp->next;
            cnt++;
        }
        k=k%cnt;
        if(k==0) return head;
        temp->next=head;
        int d=cnt-k-1; temp=head;
        while(d>0){
            temp=temp->next;
            d--;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};