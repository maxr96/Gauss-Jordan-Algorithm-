#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <Windows.h>
#include "ClearScreen.h"
#include "File.h"
#include "Jordan.h"
#include "Object1.h"
#include "Object2.h"
#include "ObjectFactory.h"
#include "Factory.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	ObjectFactory* objectFactory;
	Jordan *btn, *btt;
    int a=0;
	objectFactory = new Factory;
	cout<<"1-Ввід даних з файлу input.txt"<<endl;
	cout<<"2-Ввід даних з файлу input2.txt"<<endl;
	cout<<"3-Ввід даних з консолі зі збереженням у файлі result.txt"<<endl;
	cout<<"4-Ввід даних з консолі зі збереженням у файлі result2.txt"<<endl;
	cout<<"5-Вивід результату з файлу result.txt"<<endl;
	cout<<"6-Вивід результату з файлу result2.txt"<<endl;
	cout<<"0-Вихід з програми"<<endl;
	btn = objectFactory->createJordan("Object1");
	btt = objectFactory->createJordan("Object2");
cin>>a;
while(a!=0){
ClearScreen();
            switch(a){
            case 1: 
            btn -> fromFile();
            btn -> doCalculate();
            btn->inFile();
            break;
            case 2:
            btt -> fromFile();
            btt -> doCalculate();
            btn->inFile();
            break;
            case 3:
            btn -> setJordan();
            btn -> doCalculate();
            btn->inFile();
            break;
            case 4:
            btt -> setJordan();
            btt -> doCalculate();
            btt->inFile();
            break;
            case 5:
            btn->printFile();
            break;
            case 6:
            btt->printFile();
           	break;
            default:
            cout<<"Зробіть вибір ще раз"<<endl;
            break;
                    }
    cout<<"1-Ввід даних з файлу input.txt"<<endl;
	cout<<"2-Ввід даних з файлу input2.txt"<<endl;
	cout<<"3-Ввід даних з консолі зі збереженням у файлі result.txt"<<endl;
	cout<<"4-Ввід даних з консолі зі збереженням у файлі result2.txt"<<endl;
	cout<<"5-Вивід результату з файлу result.txt"<<endl;
	cout<<"6-Вивід результату з файлу result2.txt"<<endl;
	cout<<"0-Вихід з програми"<<endl;
	cin>>a;
				}
    delete 	objectFactory;
	return 0;
	
}