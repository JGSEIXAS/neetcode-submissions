class Solution {
public:
    void reorderList(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next; 
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* segunda_metade = slow->next;
        slow->next = nullptr;


        ListNode* anterior = nullptr;
        ListNode* atual = segunda_metade;
        
        while (atual != nullptr) {
            ListNode* proximo = atual->next;
            atual->next = anterior;         
            anterior = atual;                
            atual = proximo;                
        }
        
        ListNode* l1 = head;      
        ListNode* l2 = anterior; 

        while (l2 != nullptr) {

            ListNode* aux1 = l1->next;
            ListNode* aux2 = l2->next;

            l1->next = l2;
            
            l2->next = aux1;

            l1 = aux1;
            l2 = aux2;
        }
    }
};