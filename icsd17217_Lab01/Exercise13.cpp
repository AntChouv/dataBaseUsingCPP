/*������� ��������� icsd17217
  ������� ��������� icsd15013
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int bForceSearch(string text,string word){
    int txtlength = text.length();
    int wrdlength = word.length();
    for (int i=0;i<=txtlength-wrdlength;i++){//�� ������ i<=txtlength ���� �� ��������� ��� ��� ������� � ����
                                             //�� ���� � ��������� ��� ����� ����� ���� �� ����� �� i ����������
                                             //���� ��� �� ������� ��� ������������� ��� �������� ��� ������
        int j;
        for (j=0;j<wrdlength;j++){
            if (text.at(i+j)!=word.at(j)){
                break;
            }
        }
        if(j==wrdlength)return i;
    }
    return -1;
}

int main () {
string str;
string strText;

ifstream in;
in.open("text.txt");

while(!in.eof()) {
	getline(in, str);
	strText += str + "\n";

}
in.close();
cout << strText;
cout<<bForceSearch(strText,"most");
return 0;
}
