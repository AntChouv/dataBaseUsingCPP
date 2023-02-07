/*Αντώνης Χουβαρδάς icsd17217
  Αριστέα Βαλαζιώτη icsd15013
*/

#include <bits/stdc++.h>
using namespace std;
int cnt=0;//Μετραει ποσα στοιχεια εχει μεσα το heap
void buildMaxHeap(int arr[], int n){//Συναρτηση για  τη δημιουργια heap οπου το child παντα μικροτερο απο το parent
    int *arr1 = new int[cnt-1];//Προσορινος πινακας που βαζουμε μεσα τα στοιχεια που θα σποτελουν το heap
    int x = 0;
    int j = 0;
    int i;
    for (i=0;i<n;i++){
        if(arr[i]!=-1){
            arr1[j]=arr[i];
            j++;
        }

    }
    for (i=0;i<cnt;i++){
        if ((arr1[i] > arr1[(i-1)/2])){//Αν child μεγαλυτερο απο parent
            int j=i;
            while (arr1[j] > arr1[(j-1)/2]){//Κανε swap το child με το parent μεχρι το child να ειμαι μικροτερο
                if (arr1[j]!=-1){
                    swap(arr1[j], arr1[(j-1)/2]);
                }
                j =(j-1)/2;
            }
        }
    }for (i=0;i<n;i++){//ξανα
        if(i<cnt){
            arr[i]=arr1[i];
        }else
            arr[i]=-1;

    }
}

void arrSort(int arr[], int n){//Συναρτηση για κανει sort το heap

    for (int i=n-1;i>0;i--){
        swap(arr[0], arr[i]);
        int j=0, index;
        index=(2*j+1);
        if (arr[index]<arr[index+1] && index<(i-1))//
            index++;
        if (arr[j] < arr[index] && index < i)
            swap(arr[j], arr[index]);
        j = index;
        while (index < i){
           index=(2*j+1);
        if (arr[index]<arr[index+1] && index<(i-1))//
            index++;
        if (arr[j] < arr[index] && index < i)
            swap(arr[j], arr[index]);
        j = index;
        }
    }
}
void printArr(int arr[],int n){
    int i=0;
    while (i<n){
        if (arr[i]!=-1)
            cout<<arr[i]<<" ";
        i++;
    }
}
void insertArr(int arr[],int n,int num){
    for (int i=0;i<n;i++){
        if (arr[i]==-1){
            arr[i]=num;
            return;
        }
    }
    cout<<"No space left";
}

int main()
{
    int n = 30;
    srand((int)time(0));
    int *arr = new int[n];//Δεν χρειαζεται η malloc για dynamic memory allocation
    int x = 0;
    for (int i=0;i<n;++i)
        arr[i]=-1;
    while (x!=6){
        cout<<"Press 1 to create random array\n";
        cout<<"Press 2 to make heap from random array\n";
        cout<<"Press 3 to add to the heap\n";
        cout<<"Press 4 to print the heap\n";
        cout<<"Press 5 to sort and print the heap\n";
        cout<<"Press 6 to exit\n";
        cin>>x;
        if (x==1){
            cnt=0;
            for (int i=0;i<20;++i){
                arr[i]=(rand()%n)+1;
                cnt++;
            }for (int i=0;i<20;++i){
                cout<<" "<<arr[i];
            }
        }else if (x==2){
            buildMaxHeap(arr, n);
        }else if (x==3){
            int num;
            cout<<"Give a number to add : ";
            cin>>num;
            cnt++;
            insertArr(arr,n,num);
            buildMaxHeap(arr, n);
        }else if (x==4){
            printArr(arr,n);
        }else if (x==5){
            arrSort(arr,n);
            printArr(arr,n);

        }
    }
    cout<<cnt;
    return 0;
}
