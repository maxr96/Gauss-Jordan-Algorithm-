#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>
#include "Jordan.cpp"

using namespace std;



int main()
{ 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    Jordan jo;
    cout<<"1 - ��� ����� ������� � �����"<<endl<<"2 - ��� ����� ������� � ������"<<endl;
    cin>>a;
    if(a==1){
            jo.fromFile();}
    else if(a==2){
         jo.setJordan();}  
    jo.doCalculate();
    system("pause");
    return 0;
}
