/*Αντώνης Χουβαρδάς icsd17217
  Αριστέα Βαλαζιώτη icsd15013
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Node{//Κλαση κομβων για μονα συνδεδεμενη λιστα
public:
    int data;
    Node* next;
};

class Dnode{//Κλαση κομβων για διπλα συνδεδεμενη λιστα
public:
    int data;
    Dnode* prev;
    Dnode* next;
};

void addNodeSingle(Node** head,int newdata,int headsOtails){
    Node* newnode = new Node();//Δημιουργεια νεου κομβου
    newnode->data = newdata;//Βαζουμε τα δεδομενα στο καινουριο κομβο
    if (headsOtails == 0){//Για να προσθεσει νεο κομβο στην αρχη
        newnode->next = (*head);
        (*head) = newnode;
    }else if (headsOtails == 1){//Για να προσθεσει νεο κομβο στο τελος
        Node *last = *head;
        newnode->next = NULL;
        if (*head == NULL){//Αν η λιστα ειναι κενη τοτε απλα κανει τον νεο κομβο head
            *head = newnode;
            return;
        }
        while (last->next != NULL)//Παμε στο τελος της λιστας
            last = last -> next;
            last -> next = newnode;
            return;
    }
}

void countList(Node *node){
    int counter = 0;
    while (node != NULL){
        counter += 1;
        node = node -> next;
    }
    cout<<"\nThere are "<<counter<< " nodes in our single linked list"<<endl;
}

void displayList(Node *node){

    while (node != NULL){
        cout<<node->data<<" ";
        node = node -> next;
    }
}
void addDescending(Node** head,int newdata){
    Node* curr;
    Node* newnode = new Node();
    newnode->data = newdata;
    if((*head) == NULL || (*head)->data <= newdata){
        newnode->next = (*head);
        (*head) = newnode;
    }else{
        curr = (*head);
        while (curr->next!=NULL && (curr->next->data > newnode->data)){
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next=newnode;
    }

}
void deleteLast(Node* head){
    if (head == NULL)
        return;
    if (head->next == NULL){
        delete head;
    }
    Node* prev = head;
    while (prev->next->next != NULL)
        prev = prev->next;
    delete(prev->next);
    prev->next=NULL;
}
Node* deleteNode(Node* node,int num2del){
    if (node == NULL){
        cout<<"Empty list";
    }
    Node* temp = node;
    Node* prev = node;
    if (node->data==num2del){//Αν πρεπει να διαγραφτει το πρωτο στοιχειο
        delete node;
        node = temp->next;
        return node;
    }
    while (prev->next->data != num2del){
        prev = temp->next;
    }
    while (temp != NULL){
        temp = temp -> next;
        if (temp->data==num2del){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
    }
    return node;
}
void addNodeDouble(Dnode** node,int int2add,int pos){
    Dnode* newnode = new Dnode();//Δημιουργεια νεου κομβου
    newnode->data=int2add;//Βαζουμε τα δεδομενα στον καινουριο κομβο

    if (*node == NULL){//Αν λιστα ειναι κενη τοτε κανουμε το καινουριο κομβο head της λιστας
        newnode->prev=NULL;
        (*node) = newnode;
        return;
    }
    if (pos == 0){//Αν θελουμε να μπει στην αρχη
        newnode->next = (*node);//Κανουμε το επομενο του κανουριο κομβου head
        newnode->prev = NULL;//Και το προιγουμενο Νull
        if ((*node)!= NULL)
            (*node)->prev = newnode;//Αλλαζουμε τον προιγουμενο κομβο απο το head, σε νεο κομβο
        (*node) = newnode;
    }else if (pos == 1){//Αν θελουμε να μπει στο τελος
        Dnode* last = *node;
        while (last->next != NULL){//Παμε στο τελος της λιστας
            last = last->next;
        }last->next = newnode;//Αλλαζουμε το επομενο απο το τελευταιο node
        newnode->prev = last;
        return;
    }
}
void reverseDisplayList(Dnode* dnode){
    Dnode* last;
    while (dnode != NULL){//Βρισκουμε τον τελευταιο κομβο
        last = dnode;
        dnode = dnode->next;
    }
    while (last != NULL){
        cout<<last->data<<" ";
        last = last ->prev;
    }
}
int main(){
    //Για να υποδειξουμε τη λειτουργεια των συναρτησεων για μονα συνδεδεμενη λιστα
    Node* head = NULL;
    addNodeSingle(&head,4,0);
    addNodeSingle(&head,6,0);
    addNodeSingle(&head,9,0);
    addNodeSingle(&head,3,1);

    addDescending(&head,7);
    addDescending(&head,10);
    addDescending(&head,2);
    addDescending(&head,5);

    displayList(head);
    countList(head);

    deleteLast(head);
    displayList(head);
    countList(head);

    head = deleteNode(head,10);
    displayList(head);
    countList(head);

    head = deleteNode(head,9);
    displayList(head);
    countList(head);

    head = deleteNode(head,6);
    displayList(head);
    countList(head);

    head = deleteNode(head,4);
    displayList(head);
    countList(head);

    //Για να υποδειξουμε τη λειτουργεια των συναρτησεων για διπλα συνδεδεμενη λιστα
    Dnode* dnode = NULL;
    addNodeDouble(&dnode,4,0);
    addNodeDouble(&dnode,6,0);
    addNodeDouble(&dnode,9,0);
    addNodeDouble(&dnode,3,1);
    addNodeDouble(&dnode,5,1);

    reverseDisplayList(dnode);


    return 0;
}
