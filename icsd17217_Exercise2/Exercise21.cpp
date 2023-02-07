/*������� ��������� icsd17217
  ������� ��������� icsd15013
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Node{//����� ������ ��� ���� ����������� �����
public:
    int data;
    Node* next;
};

class Dnode{//����� ������ ��� ����� ����������� �����
public:
    int data;
    Dnode* prev;
    Dnode* next;
};

void addNodeSingle(Node** head,int newdata,int headsOtails){
    Node* newnode = new Node();//����������� ���� ������
    newnode->data = newdata;//������� �� �������� ��� ��������� �����
    if (headsOtails == 0){//��� �� ��������� ��� ����� ���� ����
        newnode->next = (*head);
        (*head) = newnode;
    }else if (headsOtails == 1){//��� �� ��������� ��� ����� ��� �����
        Node *last = *head;
        newnode->next = NULL;
        if (*head == NULL){//�� � ����� ����� ���� ���� ���� ����� ��� ��� ����� head
            *head = newnode;
            return;
        }
        while (last->next != NULL)//���� ��� ����� ��� ������
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
    if (node->data==num2del){//�� ������ �� ���������� �� ����� ��������
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
    Dnode* newnode = new Dnode();//����������� ���� ������
    newnode->data=int2add;//������� �� �������� ���� ��������� �����

    if (*node == NULL){//�� ����� ����� ���� ���� ������� �� ��������� ����� head ��� ������
        newnode->prev=NULL;
        (*node) = newnode;
        return;
    }
    if (pos == 0){//�� ������� �� ���� ���� ����
        newnode->next = (*node);//������� �� ������� ��� �������� ������ head
        newnode->prev = NULL;//��� �� ����������� �ull
        if ((*node)!= NULL)
            (*node)->prev = newnode;//��������� ��� ����������� ����� ��� �� head, �� ��� �����
        (*node) = newnode;
    }else if (pos == 1){//�� ������� �� ���� ��� �����
        Dnode* last = *node;
        while (last->next != NULL){//���� ��� ����� ��� ������
            last = last->next;
        }last->next = newnode;//��������� �� ������� ��� �� ��������� node
        newnode->prev = last;
        return;
    }
}
void reverseDisplayList(Dnode* dnode){
    Dnode* last;
    while (dnode != NULL){//��������� ��� ��������� �����
        last = dnode;
        dnode = dnode->next;
    }
    while (last != NULL){
        cout<<last->data<<" ";
        last = last ->prev;
    }
}
int main(){
    //��� �� ����������� �� ����������� ��� ����������� ��� ���� ����������� �����
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

    //��� �� ����������� �� ����������� ��� ����������� ��� ����� ����������� �����
    Dnode* dnode = NULL;
    addNodeDouble(&dnode,4,0);
    addNodeDouble(&dnode,6,0);
    addNodeDouble(&dnode,9,0);
    addNodeDouble(&dnode,3,1);
    addNodeDouble(&dnode,5,1);

    reverseDisplayList(dnode);


    return 0;
}
