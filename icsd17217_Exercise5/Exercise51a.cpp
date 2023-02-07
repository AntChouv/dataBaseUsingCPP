/*Αντώνης Χουβαρδάς icsd17217
  Αριστέα Βαλαζιώτη icsd15013
*/
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int hashsize = 1;
int colls1 = 0;
int colls2 = 0;
class obj{ //Αντικειμενο για περιπτωση double hashing
    int key;
    string word;
    int reps;
public:
    void setkey(int key1){
        key = key1;
    }
    int getkey(){
        return key;
    }
    void setword(string word1){
        word = word1;
    }
    string getword(){
        return word;
    }
    void setReps(int reps1){
        reps = reps1;
    }
    int getReps(){
        return reps;
    }
    void addRep(){
        reps=reps+1;
    }
};

class Node{ //Αντικειμενο για hashing με linked list
public:
    int key;
    string word;
    int reps;
    Node* next;
};


int hash1(int key){
    return (key%hashsize);
}
int hash2(int key){
    int hs = ((key/hashsize)%hashsize);
    if (hs==0){
        hs = 1;
    }
    return hs;
}
void insertHash(string word,int key,obj* ob){
    int index = hash1(key);
    string s1 = ob[index].getword();

    if (ob[index].getkey() != -1){//Σε περιπτωση συγκρουσης
        colls1++;//Προσθεσε στο μετρητη συγκρουσεων
        if (!word.compare(s1)){//Αν ειναι ιδια λεξη προσθεσε στο μετρητη
            ob[index].addRep();
            return;
        }
        int index2 = hash2(key);
        int i = 1;
        while (1){//Αν δεν ειναι ιδια λεξη κανουμε hash2 και βρησκουμε ποιο θα ειναι το βημα για την επομενη θεση
            int newIndex = (index + i*index2)%hashsize;
             if (!word.compare(ob[newIndex].getword())){//Αν βρει ιδια λεξη προσθετει στο μετρητη λεξης 1
                colls1++;//και στο μετρητη συγκρουσεων
                ob[newIndex].addRep();
                return;
            }
            if (ob[newIndex].getkey() == -1){
                ob[newIndex].setkey(key);
                ob[newIndex].setword(word);
                ob[newIndex].addRep();
                break;
            }i++;
        }
    }else{//Αν η θεση ειναι κενη προσθεσε στοιχειο στο hash
        ob[index].setkey(key);
        ob[index].setword(word);
        ob[index].addRep();
    }
}

void displayHash(obj* ob){
    for (int i = 0; i < hashsize; i++){
        if (ob[i].getkey() != -1)
            cout << i <<" - Key:"<< ob[i].getkey() <<" --> "<<ob[i].getword()<<"("<<ob[i].getReps()<<")"<<endl;
    }
}

int GetKey(string word){//Συναρτηση για να προσθετει τους ascii των γραμματων ωστε να βρουμε κλειδι με το hash1 και το hash2
    int sum = 0;
    for (int i = 0; i < word.length(); i++){
        char x = word.at(i);
        sum=sum+int(x);
    }return sum;
}
void addDescending(Node** obj,int key,string word){//Κωδικας ετοιμος απο την ερωτημα 1 της δευτερης εργασιας μου
    Node* curr;
    Node* curr1;
    Node* newnode = new Node();
    newnode->key = key;
    newnode->word = word;
    newnode->reps = 1;
    if((*obj) == NULL || word.compare((*obj)->word)<0){
        newnode->next = (*obj);
        (*obj) = newnode;
    }else{
        curr1 = (*obj);
        while (curr1!=NULL){
            if (!(curr1->word.compare(word))){
                curr1->reps++;
                return;
            }
            curr1 = curr1 -> next;
        }
        curr=(*obj);
        while (curr->next!=NULL && (curr->next->word).compare(newnode->word)<0)
                curr = curr->next;

        newnode->next = curr->next;
        curr->next=newnode;
    }
}
void insertHash(string word,int key,Node** ob){//Συναρτηση για να βαζει στοιχειο στο hash δευτερης επιλογης
    int index = hash1(key);
    string s1 = ob[index]->word;
    if (ob[index]->key != -1){
        colls2++;
        if (!word.compare(s1)){//Αν ειναι ιδια ανεβασε μετρητη λεξης
            ob[index]->reps++;
            return;
        }else addDescending(&ob[index],key,word);//Αν ειναι ιδιο key διαφορετικη λεξη βαλτη στο linked list
    }else{
        ob[index]->key = key;
        ob[index]->word = word;
        ob[index]->reps = 1;
    }
}
void displayList(Node *obj){

    while (obj != NULL){
        cout<<obj->word<<"("<<obj->reps<<"),";
        obj = obj -> next;
    }
}
int main(){
    time_t t;
    cout<<"Press a number(best prime) to set the hash table size : ";
    cin>>hashsize;
    string line;
    string const delims(" ',.:);!?(/-\n");
    int ascii;
    int x=1;
    clock_t start, end;
    double elapsed;
    while (x!=0){
        fstream file;
        file.open("lord.txt",ios::in);
        cout<<"Press 1 to test hashing using double-hash method";
        cout<<"\nPress 2 to test hashing using double-hash method";
        cout<<"\nPress 0 to exit : ";
        cin>>x;
        if (x==1){                                                 //Για αρχειο μεγεθους 6kb και 11kb εκανε 0.001sec και στις 2 περιπτωσεις(με τις συγκρουσεις να ειναι παντα πιο πολλες στο double hashing
            start = clock();                                       //Για αρχειο μεγεθους 53 kb εκανε 0.006s(11747 συγκρουσεις) για double hash και 0.004(8925 συγκρουσεις) για hashing με linked list
            obj dict[hashsize];
            for (int i=0; i<hashsize; i++){
                dict[i].setkey(-1);
                dict[i].setReps(0);
            }
            while (getline(file,line)){
            size_t beg,pos=0;
                while ((beg = line.find_first_not_of(delims, pos)) != string::npos){
                    pos = line.find_first_of(delims, beg + 1);
                    ascii = GetKey(line.substr(beg, pos - beg));
                    insertHash(line.substr(beg, pos - beg),ascii,dict);
                }
            }
            end = clock();
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            displayHash(dict);
            cout<<"Time taken for hashing : "<<elapsed<<endl;
            cout<<colls1<<" collisions occured"<<endl;;
        }if (x==2){
            Node* hashTable[hashsize];
            start = clock();
            for (int i=0; i < hashsize; i++){
                hashTable[i] = new Node();
                hashTable[i]->key=-1;
                hashTable[i]->reps=0;
            }
            while (getline(file,line)){
                size_t beg,pos=0;
                while ((beg = line.find_first_not_of(delims, pos)) != string::npos){
                    pos = line.find_first_of(delims, beg + 1);
                    ascii = GetKey(line.substr(beg, pos - beg));
                    insertHash(line.substr(beg, pos - beg),ascii,hashTable);
                }
            } end = clock();
            elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
            for (int i=0; i < hashsize; i++){
                if (hashTable[i]->key!=-1){
                    cout<<i<<" - Key:"<<hashTable[i]->key<<"-->";
                    displayList(hashTable[i]);
                    cout<<endl;
                }
            }cout<<"Time taken for hashing : "<<elapsed<<endl;
            cout<<colls2<<" collisions occured"<<endl;
        }file.close();
    }
    return 0;
}

