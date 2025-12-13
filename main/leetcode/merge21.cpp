#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* curr1, *curr2;

        if (list1->val < list2->val){
            curr1 = list1;
            curr2 = list2;
        } else {
            curr1 = list2;
            curr2 = list1;
        }

        ListNode* temp1, *temp2;
        while (curr1->next!=nullptr){
            while (curr2!=nullptr){
                if (curr1->next->val < curr2->val){
                    curr1 = curr1->next;
                } else {
                    temp1 = curr1->next;
                    curr1->next = curr2;
                    temp2 = curr2->next;
                    curr2->next = temp1;
                    curr2 = temp2;
                }
            }
        }


        


        
    }
};
