/*Αντώνης Χουβαρδάς icsd17217
  Αριστέα Βαλαζιώτη icsd15013
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<bits/stdc++.h>

using namespace std;


class Stud{
    public:
    int am;
    int year;
    float av;
    string fullname;
    Stud* left;
    Stud* right;
};
Stud* newnode(int amp,int yearp,float avp,string fullnamep){
    Stud* stud=new Stud;
    stud->am=amp;
    stud->year=yearp;
    stud->av=avp;
    stud->fullname=fullnamep;
    stud->left=stud->right=NULL;
    return stud;
}
Stud* insertNode(Stud* stud,int amp,int yearp,float avp,string fullnamep){
    if (stud == NULL){//Αν ειναι αδιο
        return newnode(amp,yearp,avp,fullnamep);
    }if (amp<stud->am){//Αν ειναι μικροτερο παμε προς αριστερα
        stud->left = insertNode(stud->left,amp,yearp,avp,fullnamep);
    }else if (amp>stud->am){//Αν μεγαλυτερο προς τα δεξια
        stud->right = insertNode(stud->right,amp,yearp,avp,fullnamep);
    }else
        cout<<"\nAlready registered"<<endl;
    return stud;
}
void display(Stud* stud){
    if (stud != NULL){
        display(stud->left);
        cout<<"\nAM : "<<stud->am<<"\nName : "<<stud->fullname<<"\nYear : "<<stud->year<<"\nAverage Grade : "<<stud->av<<endl;
        display(stud->right);
    }
}
void findMaxAm(Stud* stud){//Μπορει μονο να βρισκεται στο τελος απο ολες τις δεξιες μεριες
    if (stud->right!=NULL){
        findMaxAm(stud->right);
    }else
        cout<<"\nAM : "<<stud->am<<"\nName : "<<stud->fullname<<"\nYear : "<<stud->year<<"\nAverage Grade : "<<stud->av<<endl;
}
void findStud(Stud* stud,int a){
    stack<Stud* >temp;
    Stud* curr=stud;
    while (curr != NULL || temp.empty() == false){
        while (curr != NULL){
             temp.push(curr);//Βαζουμε στη στοιβα δεικτες κομβων
             curr=curr->left;
        }curr = temp.top();
        temp.pop();

        if (curr->am == a){
            cout<<"\nAM : "<<curr->am<<"\nName : "<<curr->fullname<<"\nYear : "<<curr->year<<"\nAverage Grade : "<<curr->av<<endl;
            return;
        }
        curr=curr->right;
    }
    cout<<"No student with that id number is registered\n";
}
void findMaxAv(Stud* stud){
    stack<Stud* >temp;
    Stud* curr=stud;
    int mx=0;
    int mxAm=0;
    while (curr != NULL || temp.empty() == false){
        while (curr != NULL){
             temp.push(curr);//Βαζουμε στη στοιβα δεικτες κομβων
             curr=curr->left;
        }curr = temp.top();
        temp.pop();

        if (mx<curr->av){
            mx=curr->av;
            mxAm=curr->am;
        }
        curr=curr->right;
    }
    cout<<"Student with highest grade was : ";
    findStud(stud,mxAm);
}
Stud* createTree(Stud* stud){
    fstream file;
    file.open("students_bst.txt",ios::in);
    string line;
    string delim = ",";
    size_t pos = 0;
    string token;
    while (getline(file,line)){
        int am;
        int year;
        int av;
        string fullname;
        while ((pos = line.find(delim)) != string::npos){
            token = line.substr(0,pos);
            if (pos==5){
                stringstream num(token);//κανουμε cast ως integer
                num>>am;
            }else if (pos==4){
                stringstream num(token);
                num>>year;
            }else{
                fullname = token;
            }
            line.erase(0,pos + delim.length());
        }
        av=strtof((line).c_str(),0);//cast ως float
        stud=insertNode(stud,am,year,av,fullname);
    }
    file.close();
    return stud;
}
Stud* deletion(Stud* stud,int a){
    if (stud == NULL) return stud;
    if (a<stud->am){
        stud->left = deletion(stud->left,a);
    }else if (a>stud->am){
        stud->right = deletion(stud->right,a);
    }else{
        Stud* temp;
        if (stud->right == NULL && stud->left == NULL){//Χωρις παιδια
            delete stud;
            stud == NULL;
        }
        if (stud->left == NULL){//Χωιρις αριστερο παιδι
            temp = stud->right;
            free(stud);
            return temp;
        }else if (stud->right == NULL){//Χωρις δεξι παιδι
            temp = stud->left;
            free(stud);
            return temp;
        }else{
            Stud* parent = stud->right;
            Stud* successor = stud->right;
            while (successor->left != NULL){
                parent = successor;//Φυλαμε παντα το πατερα του κομβου που παμε
                successor = successor->left;
            }parent->left = successor->right;//Βαζουμε ως αριστερο παιδι του πατερα το δεξι παιδι του απογονου

            stud->am = successor->am;//Αντιγραφουμε τα δεδομενα
            stud->av = successor->av;
            stud->fullname = successor->fullname;
            stud->year = successor->year;
            delete successor;
            return stud;
        }
    }
}
int counT(Stud* stud,int &i){
    if (stud != NULL){
        counT(stud->left,i);
        i++;
        counT(stud->right,i);
    }
}
void savetoFile(Stud* stud){
    fstream file;
    file.open("students_bst.txt",ios::out);
    stack<Stud* >temp;
    Stud* curr=stud;
    while (curr != NULL || temp.empty() == false){
        while (curr != NULL){
             temp.push(curr);//Βαζουμε στη στοιβα δεικτες κομβων
             curr=curr->left;
        }curr = temp.top();
        temp.pop();
        if (file.is_open())
            file<<curr->am<<","<<curr->fullname<<","<<curr->year<<","<<curr->av<<"\n";
        curr=curr->right;
    }
    file.close();
}


int main(){
    Stud* stud = NULL;
    stud=createTree(stud);
    int choice=-1;
    int a;
    while (choice != 0){
        cout<<"Please enter 1 to add student\n2 to display all students\n3 to display student with highest id number\n";
        cout<<"4 to display student with highest average grade\n5 to search students info\n6 to delete student\n7 to display number of students\n0 to save and exit : ";
        cin>>choice;
        if (choice == 1){
            int am,year;
            float av;
            string fullname;
            cout<<"\nEnter students id number : ";
            cin>>am;
            cout<<"Enter students full name : ";
            cin.ignore();
            getline(cin,fullname);
            cout<<"Enter students year of entry : ";
            cin>>year;
            cout<<"Enter  students average grade : ";
            cin>>av;
            stud =  insertNode(stud,am,year,av,fullname);
        }else if (choice == 2){
            display(stud);
        }else if (choice == 3){
            findMaxAm(stud);
        }else if(choice == 4){
            findMaxAv(stud);

        }else if (choice == 5){
            cout<<"Give an id number  : ";
            cin>>a;
            findStud(stud,a);
        }else if (choice == 6){
            cout<<"Give am number for deletion ";
            cin>>a;
            stud=deletion(stud,a);
        }else if (choice == 7){
            int i=0;
            counT(stud,i);
            cout<<"Number of students registered "<<i<<endl;
        }else if (choice == 0){
            savetoFile(stud);
        }
    }
    return 0;
}
