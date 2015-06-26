#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <Windows.h>
using namespace std;
class Object2: public Jordan  {
public:
	void fromFile();
    void inFile();
    void printFile();
};
void Object2::printFile(){
	ifstream in("result2.txt");
	static char  buff[1024][1024];
    int i=0;
	if (in == 0)
    {
        cout << "Помилка! Файл не знадено!" << endl;
    }
    while (!in.eof( )) {
    	 in.getline(buff[i],sizeof(buff)); 
        std::cout << buff[i];
        ++i;
	}
	cout<<endl;
	in.close();
}
  
void Object2::fromFile(){
        ifstream in("input2.txt");
    if (in == 0)
    {
        cout << "Помилка! Файл не знадено!" << endl;
    }
    in >> NEQ;
    N1=NEQ+1;
    A = new float *[NEQ];
    for (int i = 0; i < NEQ; i++)
    {
        A[i] = new float [N1];
    }

    for (int i = 0; i < NEQ; i++)
    {
        for (int j = 0; j < N1; j++)
        {
            in >> A[i][j];
        }
    }
        in.close();}
void Object2::inFile(){
           ofstream fout;
           fout.open("result2.txt");
            for(int i=0;i<NEQ;i++){
        for(int j=N1-1;j<N1;j++){
          fout<<setprecision(2)<<setw(5)<<"x"<<i+1<<"="<<A[i][j];}
             fout<<endl;}
             fout.close();}

