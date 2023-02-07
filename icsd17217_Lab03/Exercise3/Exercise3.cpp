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
int compars=0; //Μεταβλητη για να μετραμε τις συγκρησεις καθε επαναληψης
void fillArr(int *arr,int n){//Συναρτηση που γεμιζει τον πινακα με τυχαιους αριθμους απο το 0 εως το 50000
    int i;
    arr[0]=1+rand()%4;
    for (i=1;i<n;i++){
        arr[i] = (rand()%50000)+0;
    }
}
void printArr(int *arr,int n){
    int i;
    for (i=0;i<n;i++){
        cout<<arr[i]<<"| ";
    }
    cout<<"\n";
}
void swapNums(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
void insertionSort(int *arr,int n){
    int i,j,cur;
    for (i=1;i<n;i++){
        cur = arr[i];
        j = i - 1;

        while (j>=0 && arr[j]<cur){//Μεταφερει τα στοιχεια του πινακα απο το arr[0] εως arr[j]
                                   // καθως και αυτα που ειναι μικροτερα απο το arr[i],
                                   // μια θεση προς τα δεξια
            compars+=1;
            arr[j+1]=arr[j];
            j--;
        }arr[j+1]=cur;
    }
    cout<<"Insertion sort  took "<<compars<<" comparisons"<<endl;
}
void selectionSort(int *arr,int n){
    int i,j,maxim;
    for(i=0;i<n-1;i++){
        maxim=i;
        for(j=i+1;j<n;j++){//Βρησκουμε το μεγαλυτερο στοιχειο του πινακα
            if (arr[j]>arr[maxim]){
                maxim=j;
                compars+=1;
            }
        }swapNums(&arr[maxim],&arr[i]);//Κανουμε swap το μεγαλυτερο στοιχειο που βρηκαμε με το πρωτο στοιχειο του πινακα
    }
    cout<<"Selection sort  took "<<compars<<" comparisons"<<endl;
}
void bubbleSort(int* arr,int n){
    int i,j;
    for (i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if (arr[j]<arr[j+1]){
                swapNums(&arr[j],&arr[j+1]);
                compars+=1;
            }
        }
    }
    cout<<"Bubble sort  took "<<compars<<" comparisons"<<endl;
}
void merge(int *arr,int left,int mid,int right){//Συναρτηση που συγχωνευει 2 πινακες
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 =  right - mid;
    int L[n1], R[n2];
    for (i=0;i<n1;i++){//Βαζουμε στοιχεια στο πρωτο πινακα
        L[i]= arr[left + i];
    }
    for (j=0;j<n2;j++){//Και εδω στο δευτερο
        R[j]= arr[mid + 1+ j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i<n1&&j<n2){//Ξαναβαζουμε τα στοιχεια των προσωρινων πινακων πισω στον αρχικο μας
        compars+=1;
        if (L[i]>=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int *arr, int left,int right){//Καθε φορα περναμε το αριστερο και δεξι μερος του σημειου του πινακα που ειναι για sort
    if (left<right){
        int mid = left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int partition(int *arr,int low,int high){//Καθε φορα που εχουμε το στοιχειο pivot βαζει ολα τα μεγαλυτερα στα αριστερα
    int pivot=arr[high];
    int i=(low-1);
    for (int j=low;j<=high-1;j++){
        if (arr[j]>=pivot){//Ο ελεγχος
            compars+=1;
            i++;
            swapNums(&arr[i],&arr[j]);
        }
    }
    swapNums(&arr[i+1],&arr[high]);
    return(i+1);
}
void quickSort(int *arr,int low,int high){
    if (low<high){
        int p= partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
}

int main(){
    int n,i,a;
    time_t t;
    srand((int)time(0));
    cout<<"Give an integer number : ";
    cin>>n;
    cout<<"Press 1 for insertion sort\nPress 2 for selection sort\nPress 3 for bubble sort\nPress 4 for merge sort\nPress 5 for quick sort\nPress 6 for exit+ : ";
    cin>>a;
    int *arr = new int[n];
    long long int sum=0;
    double sumTime=0;
    for (int j=0;j<50;j++){
        fillArr(arr,n);
        cout<<"\n";
        t = clock();
        compars=0;
        if (a==1){
            insertionSort(arr,n);
        }else if (a==2){
            selectionSort(arr,n);
        }else if (a==3){
            bubbleSort(arr,n);
        }else if (a==4){
            mergeSort(arr,0,n-1);
            cout<<"Merge sort  took "<<compars<<" comparisons"<<endl;
        }else if (a==5){
            quickSort(arr,0,n-1);
            cout<<"Quick sort  took "<<compars<<" comparisons"<<endl;
        }
        sum=sum + compars;
        t = clock() - t;
        double time_taken = ((double)t)/CLOCKS_PER_SEC;
        cout<<"Time taken for sorting : "<<time_taken<<endl;
        sumTime=sumTime + time_taken;
    }
    cout<<"Sum of comparisons : "<<sum<<endl;
    cout<<"Sum of time taken : "<<sumTime<<endl;
    cout<<"Average comparisons : "<<sum/50<<endl;
    cout<<"Average time taken : "<<sumTime/50<<endl;
    return 0;
}
