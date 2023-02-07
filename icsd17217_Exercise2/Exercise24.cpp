/*Αντώνης Χουβαρδάς icsd17217
  Αριστέα Βαλαζιώτη icsd15013
*/
#include <iostream>
#include <string.h>

using namespace std;

class Queue{
public:
    int left,right,cap;
    int* q;
    Queue(int c){
        left = right = 0;
        cap = c;
        q = new int;
    }
     void display(){
        int i;
        if (left == right){
            cout<<("\nNo customers");
            return;
        }
        for (i=left;i<right;i++){
            cout<<"| "<<q[i];
        }
        return;
    }
    void customerOpt(int priority){
        if (cap == right){
            cout<<"No costumer\n";
            return;
        }else{
        q[right] = priority;
        right++;
        }
        cout<<right;
    return;
    }
    void nextCust(int cashiers[4]){
        if (left == right){
            cout<<"No customer\n";
            return;
        }
        int opt;
        cout<<"Press 1,2,3 or 4 to choose cashier for next customer : ";
        cin>>opt;
        cout<<"Costumer with number "<<q[left]<<" proceed to cashier number "<<opt<<"\n";
        cashiers[opt-1] += 1;
        for (int i=0;i<right-1;i++)
            q[i] = q[i+1];
        right--;
    }
    int showCustNum(){
        return q[right];
    }
};
void cashierMax(int cashiers[4]){
    int mx = cashiers[0];
    int mxCashier = 1;
    for (int i=1;i<=3;i++){
        if (cashiers[i]>mx){
            mx = cashiers[i];
            mxCashier = i+1;
        };
    }cout<<"The cashier with the most customers is number : "<<mxCashier<<"\n";;
}

int main(){
    int cashiers[4] = {0,0,0,0};
    Queue q(1000);
    char option ;
    int opt;
    int prior = 1;
    cout<<"Type:\nC for customers option\nB for bank cashier option\nM for bank managers option\nE for exit : ";
    cin>>option;
    opt = int(option);
    while (opt!=69 && opt!=101){
        if (opt == 67 || opt == 99){
           q.customerOpt(prior);
            prior+=1;
        }else if (opt==66 || opt==98){
            q.nextCust(cashiers);
            q.display();
        }else if (opt==77 || opt==109){
            int sum = 0;
            for (int i=0;i<=3;i++){
                sum += cashiers[i];
            }cashierMax(cashiers);
            cout<<"The summary of all customers serviced in a cashiers is : "<<sum;
            cout<<"\nThe number of customers entered the bank is : "<<q.showCustNum();
            cout<<"\nRemaining costumers : "<<q.showCustNum()-sum;
        }
        cout<<"\nGive next option : ";
        cin>>option;
        opt = int(option);
    }
};

