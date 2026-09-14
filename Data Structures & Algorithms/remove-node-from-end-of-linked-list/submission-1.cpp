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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tamanho = head;
        int cont = 0;
        while(tamanho != nullptr){
            cont +=1;
            tamanho = tamanho->next;
        }

        cont -= n;
        tamanho = head;
        ListNode* anterior = nullptr;
        while(cont --){
            anterior = tamanho;
            tamanho = tamanho ->next;
        }
        if(anterior == nullptr){
            return head->next;
        }
        anterior -> next = tamanho->next;
        return head;
    }
};
