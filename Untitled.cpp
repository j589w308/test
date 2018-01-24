#include <iostream>
#include <vector>

using namespace std;

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

RandomListNode *copyRandomList(RandomListNode *head);

    RandomListNode *copyRandomList(RandomListNode *head) {
    //Without hashMap: use 3 iterations on orginal list
    //1st iteration: create newNode for each node, connect newNode after the node. like: A->A'->B->B'...
    //2nd iteration: assign (the next of the random of A) to (the random of A')
    //3rd iteration: disconnect original list and new list.
    //Time Complexity: O(3*n) Space Complexity: O(1)
        if(head == NULL)
            return head;
        
        RandomListNode *nextNode = head->next;
        
        RandomListNode *newNode = new RandomListNode(head->label);
        
        newNode->next = nextNode;
        head->next = newNode;
        
        //RandomListNode *newHead = newNode;
        while(nextNode != NULL)
        {
            RandomListNode *newNode = new RandomListNode(nextNode->label);
            RandomListNode *tmp = nextNode->next;
            newNode->next = tmp;
            nextNode->next = newNode;
            nextNode = tmp;   
        }
        
        nextNode = head;
        //2nd iteration: Assign----- nextNode.next.random = nextNode.random.next;
        while(nextNode != NULL)
        {
            if(nextNode->random == NULL) //Do not forget to check the 'nextNode->random = NULL
                nextNode->next->random = NULL;
            else
                nextNode->next->random = nextNode->random->next;
            nextNode = nextNode->next->next;
        }
        
        RandomListNode *node = head;
        nextNode = node->next;
        
        //3rd iteration: disconnect A and A'
        RandomListNode *newHead = head->next;
        
          
        while(nextNode != NULL)
        {
            node->next = nextNode->next;
            if(nextNode->next == NULL)  //check nextNode == NULL once it have nextNode->next->next(may access NULL value)
                nextNode->next = NULL;
            else
                nextNode->next = nextNode->next->next;
            node = node->next;
            nextNode = nextNode->next;
            
        }
        
        return newHead;
    }

int main()
{

  return 0;
}
