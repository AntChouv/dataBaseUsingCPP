/*������� ��������� icsd17217
  ������� ��������� icsd15013
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>

using namespace std;

class Stud{//����� ������ ��� ����� ����������� �����
public:
    string name;
    string surname;
    string tel;
    int year;
    int am;
    Stud* prevSur;
    Stud* prevAm;
    Stud* nextSur;
    Stud* nextAm;
};
void displayList(Stud* stud){//�������� ������
    while (stud != NULL){
        cout<<stud->name<<" \n";
        stud = stud ->nextAm;
    }
}
void reverseDisplayList(Stud* stud){//�������� ������ ������� ��� �� ������������� �� ����� �������
    Stud* last;
    while (stud != NULL){//��������� ��� ��������� �����
        last = stud;
        stud = stud->nextAm;
    }
    while (last != NULL){
        cout<<last->name<<" \n";
        last = last ->prevAm;
    }
}
int check4Am(Stud* stud,Stud* newnode){//�������� �� � ������� ������� ��� ����������� ������ ����� ��� ������������
     while (stud != NULL){
            if (stud->am == newnode->am){
                    cout<<newnode->am<<" already exists"<<endl;
                    return 1;
            }stud = stud ->nextAm;
    }
    return 0;
}
void addStud(Stud** stud,string namep,string surnamep,string telp,int yearp,int amp){//�� �� ������������ ������ ������� ����� ��� �����
                                                                                     //���� ����� �� ������� ����� ������� �������.
    Stud* newnode = new Stud();//����������� ���� ������
    newnode->name=namep;//������� �� �������� ���� ��������� �����
    newnode->surname=surnamep;
    newnode->tel=telp;
    newnode->year=yearp;
    newnode->am=amp;
    newnode->nextAm=NULL;
    newnode->prevAm=NULL;
    newnode->nextSur=NULL;
    newnode->prevSur=NULL;
    if (check4Am(*stud,newnode)==1){
        return;
    }
    if (*stud == NULL){//�� ����� ����� ���� ���� ������� �� ��������� ����� head ��� ������
        newnode->prevAm=NULL;
        newnode->prevSur=NULL;
        (*stud) = newnode;
    }else if ((*stud)->am >= newnode->am){ //�� ������� �� ���� ���� ����
        newnode->nextAm = (*stud);//���������� ���� ������� �� ���� ������� nextAm
        newnode->nextSur = (*stud);
        newnode->nextAm->prevAm=newnode;//���������� ���� ������� �� ���� ������� prevAm.����� ���� �� ������� � ������� �� �� �����������
        newnode->nextSur->prevSur=newnode;
        *stud = newnode;
    }
}

//���������� ����������� ��� �� merge-sort ��� ������ ���� �� ����������� �� ��������
//�� ���� �� ������� ����. �������������� merge sort ����� ��� ������ ����� ��� ���������
//����� ���� ������ �� ���������� ������������ ���� ��� ��������� � ������������� ����� ��� ������

Stud* splitList(Stud *stud){//��������� ��� �� ��������� ��� ����� �� 2 �� ��� ����
    Stud* frst = stud;
    Stud* sec = stud;
    while (frst->nextSur && frst->nextSur->nextSur){
        frst = frst->nextSur->nextSur;
        sec = sec->nextSur;
    }Stud* temp = sec->nextSur;
    sec->nextSur=NULL;
    return temp;
}
Stud* meRge(Stud* frst,Stud* sec){
    if (!frst){
        return sec;
    }if (!sec){
        return frst;
    }
    const char *f = (frst->surname).c_str();
    const char *s = (sec->surname).c_str();
    if (strcmp(f,s)<0){
        frst->nextSur=meRge(frst->nextSur,sec);
        frst->nextSur->prevSur=frst;
        frst->prevSur=NULL;
        return frst;
    }else if (strcmp(f,s)>0) {
        sec->nextSur=meRge(frst,sec->nextSur);
        sec->nextSur->prevSur=sec;
        sec->prevSur=NULL;
        return sec;
    }else{
        if (frst->am < sec->am){
            frst->nextSur=meRge(frst->nextSur,sec);
            frst->nextSur->prevSur=frst;
            frst->prevSur=NULL;
            return frst;
        }else{
            sec->nextSur=meRge(frst,sec->nextSur);
            sec->nextSur->prevSur=sec;
            sec->prevSur=NULL;
            return sec;
        }
    }
}
Stud* mergeSort(Stud* stud){
    if (!stud || !stud->nextSur){
        return stud;
    }Stud* sec = splitList(stud);
    stud = mergeSort(stud);
    sec = mergeSort(sec);
    return meRge(stud,sec);
}
//Stud* stud = NULL
/*void printSur(Stud* stud){
    displayList(stud);
    Stud* stud2;
    stud2 = mergeSort(stud);
    cout<<"List sorted based on Surname\n";
    displayList(stud2);
}*/
int main(){;
Stud* stud;
addStud(&stud,"Antonis","Chouvardas","6999999999",2017,17217);
//addStud(&stud,"Giannis","Chouvardas","6999999997",2019,19117);
addStud(&stud,"Manolis","Manolou","6999999995",2019,19217);
addStud(&stud,"Manolis","Manolou","6999999995",2019,19217);
addStud(&stud,"Giorgos","Chouvardas","6999999998",2016,16217);
addStud(&stud,"Giannis","Chouvardas","6999999997",2018,18317);
addStud(&stud,"Poppi","Philippi","6999999996",2015,15317);
addStud(&stud,"Kwstas","Kwstou","6999999994",2019,19917);
displayList(stud);
reverseDisplayList(stud);
//printSur(stud);
return 0;
}
