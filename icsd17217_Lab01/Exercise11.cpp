/*Αντώνης Χουβαρδάς icsd17217
  Αριστέα Βαλαζιώτη icsd15013
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void serialsearch1(int *arr,int sz,int r){ // Συναρτηση που μολις βρει τον ζητουμενο αριθμο τερματιζεται η λειτουργεια της
    int i=0,pos;
    bool found=false;
    while ((i<sz) && (found==false)){ //Τερματισμος αν βρει το νουμερο η αν ψαξει ολο το πινακα και δεν τον βρει
        if (arr[i]==r){
            found = true;
            pos = i;
        }
        i = i + 1;
    }
    if (found == true){
        cout<<"Item found at position "<<pos<<endl;
    }else
        cout<<"Item not found"<<endl;
}
void serialsearch2(int *arr,int sz,int r){
    int i=0;
    int rpss[sz];//Εδω ειναι ενας προσωρινος πινακας στον οποιο αποθηκευουμε τις θεσεις που βρισουμε το νουμερο
                 //και στις υπολοιπες θεσεις του βαζουμε -1
    bool found=false;
    while (i<sz){
        if (arr[i]==r){
            rpss[i] = i;
            found = true;
        }else{
            rpss[i] = -1;
        }
        i = i + 1;
    }
    if (found==true){// Αν εχει βρει εστω και μια φορα το νουμερο εμφανιζει τις θεσεις του
        cout<<"In positions : ";
        int j;
        for (j=0;j<sz;++j){
            if (rpss[j]>=0){
                cout<<rpss[j]<<endl;
            }
        }
    }else
        cout<<"Not found";
    delete[] rpss;
};

int main(){
    int n,r;
    cout<<"Give an integer number : ";
    cin>>n;
    srand((int)time(0));
    int *arr = new int[n];//Δεν χρειαζεται η malloc για dynamic memory allocation
    for (int i=0;i<n;++i){
        arr[i]=(rand()%n)+1;
    }
    for (int i=0;i<n;++i){
        cout<<arr[i]<<"\n";
    }
    r = (rand()%n)+1;
    cout<<"Searching for : "<<r<<endl;
    cout<<"First serial"<<endl;
    serialsearch1(arr,n,r);
    cout<<"Second serial"<<endl;
    serialsearch2(arr,n,r);
    return 0;
}

