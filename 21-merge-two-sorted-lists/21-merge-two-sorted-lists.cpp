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
    void insertion_tail(ListNode *&head, int n)
    {
        ListNode *newNode = new ListNode(n);
        if (head == NULL)
            head = newNode;
        else
        {
            ListNode *temp;
            for (temp = head; temp->next != NULL; temp = temp->next);
            temp->next = newNode;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3=NULL;
        ListNode *temp1=list1;
        ListNode *temp2=list2;
        while(temp1!=NULL&&temp2!=NULL)
        {
            if(temp1->val<=temp2->val)
            {
                insertion_tail(list3,temp1->val);
                temp1=temp1->next;
            }
            else
            {
                insertion_tail(list3,temp2->val);
                temp2=temp2->next;
            }
        }
        if(temp1==NULL)
        {
            while(temp2!=NULL)
            {
                insertion_tail(list3,temp2->val);
                temp2=temp2->next;
            }
        }
        else if(temp2==NULL)
        {
            while(temp1!=NULL)
            {
                insertion_tail(list3,temp1->val);
                temp1=temp1->next;
            }
        }
        return list3;
    }
};