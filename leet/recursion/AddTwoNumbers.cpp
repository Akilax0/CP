#include<bits/stdc++.h>
using namespace std;

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
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode *ans = new ListNode(); 
        ListNode *cur = ans;
        
        int res = 0,a,b,val;
        
      
        while(l1!= NULL || l2!= NULL || res){
            a = l1!=NULL ? l1->val : 0; 
            b = l2!=NULL ? l2->val : 0; 
            
            
            val = a + b + res;
            res = (int) val / 10;
            val = val % 10;
            cur->next = new ListNode(val);
            
            cur = cur->next;
            l1 = l1!=NULL ? l1->next : NULL;
            l2 = l2!=NULL ? l2->next : NULL;
            
        }
        return ans->next;
    }
};