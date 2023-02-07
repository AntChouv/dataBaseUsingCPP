/*Αντώνης Χουβαρδάς icsd17217
  Αριστέα Βαλαζιώτη icsd15013
*/
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;


void binarysearch(int *arr,int sz,int x){
    int i=0,comps=0;
    int l,r;
    l = 0;//Αριστερη μερια του πινακα
    r = sz-1;//δεξια μερια του πινακα

    while (l<=r){
           int m = l+(r-l)/2;//To κεντρο του πινακα
           if (x==arr[m]){
                comps = comps + 1;
                cout<<"Item found at position "<<m<<" and it took "<<comps<<" comparisons";
                r=0;//Αν βρουμε το νουμερο τοτε σταματαει η while και χρησιμοποιουμε το r σαν ενδειξη οτι το βρηκαμε
                break;
           }
           if (x<arr[m]){
                comps = comps + 1;
                r = m-1;//Οριζουμε ως δεξια μερια του πινακα μια θεση πριν το κεντρο μας
           }else {
                comps = comps + 1;
                l = m+1;//Οριζουμε ως αριστερη μερια του πινακα μια θεση πριν το κεντρο μας
           }
    }
    if (r!=0){
        cout<<"item not found";
    }
}
int main(){
    int n,r;
    cout<<"Give an integer number";
    cin>>n;
    srand((int)time(0));
    int *arr = new int[n];
    arr[0]=1+rand()%4;
    for (int i=1;i<n;++i){
        arr[i]=arr[i-1]+1+(rand()%4);//Για αριθμους σε αυξουσα σειρα
    }
    for (int i=0;i<n;++i){
        cout<<arr[i]<<"\n";
    }
    r = (rand()%n)+1;
    cout<<"We look for the number : "<<r<<endl;
    cout<<"First\n"<<endl;
    cout<<"Second\n"<<endl;
    binarysearch(arr,n,r);
    return 0;
}
