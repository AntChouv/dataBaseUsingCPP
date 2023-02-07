/*Αντώνης Χουβαρδάς icsd17217
  Αριστέα Βαλαζιώτη icsd15013
*/
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int sumOdig(int x,int sum){//Επιστρεφουμε καθε φορα το νουμερο μας χωρις το τελευταιο στοιχειο το οποιο
                           //προσθετουμε στο sum και το επιστρεφουμε επισης ως δευτερη παραμετρο
    if (x>=10){
        return sumOdig(x/10,sum+(x%10));
    }else return sum+x;
}

int increaDig(int x,int y){//Επιστρεφουμε καθε φορα τον αριθμο μας χωρις το τελευταιο στοιχειο
                           //το οποιο συγκρινουμε σε καθε αναδρομη με το τρεχων τελεταιο στοιχειο
    cout<<x%10<<endl;
    if ((x%10)<=y && x>=10){
        y=x%10;
        return increaDig(x/10,y);
    }else if ((x%10)>=y)//Αν το τρεχων ειναι μεγαλυτερο του προιγουμενου τελευταιου στοιχειου
                        //τοτε τα ψηδεια δεν ακολουθουν αυξουσα διαταξη
        return -1;
}
int binarysearch(int *arr,int l,int r,int x,int combs){//Ως παραμετρους εχουμε τον πινακα,το αριστερο ακρο,το δεξι ακρο
                                                       //τον αριθμο που ψαχνουμε και τις επαναληψεις της αναδρομης
    int i=0;

    if (l<=r){
            int m = l+(r-l)/2;
           if (x==arr[m]){
                combs = combs + 1;
                cout<<"Item found at position "<<m<<" and it took "<<combs<< " comparisons";
                r=0;
           }
           if (x<arr[m]){
                 return binarysearch(arr,l,m-1,x,combs + 1);
           }else {
                return binarysearch(arr,m+1,r,x,combs + 1);
           }
    }
    if (r!=0){
        return -1;
    }
}

int main(){
    int x,y=0;
    cout<<"Give an integer Number : ";
    cin>>x;
    cout<<"Sum of digits in : "<<sumOdig(x,y)<<endl;

    cout<<"Give an integer Number : ";
    cin>>x;
    y = x%10;
    if (increaDig(x/10,y)<0)
        cout<<"Not increasing digits"<<endl;
    else
        cout<<"Increasing digits"<<endl;


    int n,chck;
    cout<<"Give an integer number";
    cin>>n;
    srand((int)time(0));
    int *arr = new int[n];
    arr[0]=1+rand()%4;
    for (int i=1;i<n;++i){
        arr[i]=arr[i-1]+1+(rand()%4);
    }
    for (int i=0;i<n;++i){
        cout<<arr[i]<<"\n";
    }
    x = (rand()%n)+1;
    cout<<"we are looking for number : "<<x<<endl;
    int l = 0;
    int r = n-1;
    int combs = 0;


    chck = binarysearch(arr,l,r,x,combs);
    if (chck == -1){
        cout<<"Item not found"<<endl;
    }
    return 0;
}
