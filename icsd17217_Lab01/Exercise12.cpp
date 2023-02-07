/*������� ��������� icsd17217
  ������� ��������� icsd15013
*/
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;


void binarysearch(int *arr,int sz,int x){
    int i=0,comps=0;
    int l,r;
    l = 0;//�������� ����� ��� ������
    r = sz-1;//����� ����� ��� ������

    while (l<=r){
           int m = l+(r-l)/2;//To ������ ��� ������
           if (x==arr[m]){
                comps = comps + 1;
                cout<<"Item found at position "<<m<<" and it took "<<comps<<" comparisons";
                r=0;//�� ������ �� ������� ���� ��������� � while ��� �������������� �� r ��� ������� ��� �� �������
                break;
           }
           if (x<arr[m]){
                comps = comps + 1;
                r = m-1;//�������� �� ����� ����� ��� ������ ��� ���� ���� �� ������ ���
           }else {
                comps = comps + 1;
                l = m+1;//�������� �� �������� ����� ��� ������ ��� ���� ���� �� ������ ���
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
        arr[i]=arr[i-1]+1+(rand()%4);//��� �������� �� ������� �����
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
