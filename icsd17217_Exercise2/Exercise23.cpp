/*Αντώνης Χουβαρδάς icsd17217
  Αριστέα Βαλαζιώτη icsd15013
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Node{//Κλαση κομβων για μονα συνδεδεμενη λιστα
public:
    int data;
    Node* next;
};

void addNodeSingle(Node** head,int newdata){
    Node* newnode = new Node();//Δημιουργεια νεου κομβου
    newnode->data = newdata;//Βαζουμε τα δεδομενα στο καινουριο κομβο
    newnode->next = (*head);
    (*head) = newnode;
}
void displayList(Node *node){
    Node* temp = node;
    temp = temp -> next;
    while (temp != node){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<node->data<<endl;
}
void makeitCirc(Node** head){
     Node *start = *head;
     while ((*head)->next != NULL){//Βρισκουμε τον τελευταιο κομβο
        *head = (*head)->next;
     }
     (*head)->next = start;
}
void findPrince(Node* head){
    Node* headref = head;
    if (headref == NULL){
        cout<<"Empty list";
        return;
    }Node* cur = headref;
    Node* prev;
    while (true){
        if (cur->next == headref && cur == headref)
            break;
        displayList(headref);
        for (int i=0;i<3;i++){
            prev = cur;
            cur = cur->next;
        }
        if (cur == headref){
            prev = headref;
            while (prev->next!=headref)
                prev = prev->next;
            headref = cur->next;
            prev->next = headref;
            head = headref;
            free(cur);
        }
        else if (cur->next == headref){
            prev->next = headref;
            free(cur);
        }else {
            prev->next = cur->next;
            free(cur);
        }
    }
}
int main(){

    srand((int)time(0));
    int r = (rand()%15)+2;

    Node* head = NULL;
    for (int i=r;i>=1;i--){
        addNodeSingle(&head,i);
    }
    makeitCirc(&head);
    findPrince(head);
    return 0;
}
