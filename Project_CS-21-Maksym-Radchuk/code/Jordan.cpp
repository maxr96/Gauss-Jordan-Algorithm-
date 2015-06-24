#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <Windows.h>
using namespace std;
class File{
      protected:
          int NEQ, N1;
          float **A;    
      public:
             virtual void fromFile() = 0;
             virtual void inFile() = 0;
             };
             
class Jordan : public File{
    public:
        virtual void setJordan();        
        virtual void doCalculate();
};

class Object1: public Jordan {
public:
	void fromFile();
    void inFile();
};
  void Jordan::setJordan()
   {
        cout<<"Ââåä³òü ê³ëüê³ñòü ð³âíÿíü : "; 
        cin>>NEQ;
        N1=NEQ+1;
        cout<<"ÂÂ²Ä "<<endl;
           A=new float *[NEQ];
           for (int i = 0; i<NEQ; i++)
              A[i] = new float [N1];
        for(int i=0;i<NEQ;i++)  
           for(int j=0;j<N1;j++)
           {
            cout<<"Ââåä³òü åëåìåíò ìàòðèö³["<<i+1<<"]"<<"["<<j+1<<"]=";
            cin>>A[i][j];
           }
   }
 void  Jordan::doCalculate()
 {
   float D,D1;
   for(int N=0;N<NEQ;N++)
      {
         if(A[N][N]==0)
                   {
                       cout<<endl<<"*** ÍÓËÜÎÂÈÉ ÅËÅÌÅÍÒ ÍÀ Ä²ÀÃÎÍÀË² ";
                         cout<<N<<" Ï²Ä ×ÀÑ ÂÈÊÎÍÀÍÍß***"<<endl;
                         system("pause");
                         exit(0);
                         
                   }
            D=(1/A[N][N]);
           for(int j=0;j<N1;j++)
             {
               A[N][j]=D*A[N][j];
             }
           for(int i=0;i<NEQ-1;i++)
                 {
                       if(i==N)
                            {
                              i++;
                            }
                     D1=A[i][N];
                    for(int j=0;j<N1;j++)
                            {
                               A[i][j]=A[i][j]-D1*A[N][j];
                             }
                  }
          A[N][N]=1;
       }
    cout<<endl<<"ÂÈÂ²Ä"<<endl<<endl;
      for(int i=0;i<NEQ;i++){
        for(int j=N1-1;j<N1;j++){
          cout<<setprecision(2)<<setw(5)<<"x"<<i+1<<"="<<A[i][j];}
             cout<<endl;}
}
void Object1::fromFile(){
        ifstream in("input.txt");
    if (in == 0)
    {
        cout << "Ïîìèëêà! Ôàéë íå çíàäåíî!" << endl;
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
void Object1::inFile(){
           ofstream fout;
           fout.open("result.txt");
            for(int i=0;i<NEQ;i++){
        for(int j=N1-1;j<N1;j++){
          fout<<setprecision(2)<<setw(5)<<"x"<<i+1<<"="<<A[i][j];}
             fout<<endl;}
             fout.close();}

class Object2: public Jordan  {
public:
	void fromFile();
    void inFile();
};
  
void Object2::fromFile(){
        ifstream in("input2.txt");
    if (in == 0)
    {
        cout << "Ïîìèëêà! Ôàéë íå çíàäåíî!" << endl;
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

class ObjectFactory {
public:
	virtual Jordan *createJordan(char *) = 0;
};

class Factory: public ObjectFactory {
public:
	Jordan *createJordan(char *type) {
		if(strcmp(type,"Object2") == 0) {
 			return new Object2;
		}
		else if(strcmp(type,"Object1") == 0) {
			return new Object1;
		}
	}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
	ObjectFactory* objectFactory;
	Jordan *btn, *btt, *btk;
    int a;
	objectFactory = new Factory;

	btn = objectFactory->createJordan("Object1");
    cout<<"1 - Äëÿ ââîäó ìàòðèö³ ç ôàéëó"<<endl<<"2 - Äëÿ ââîäó ìàòðèö³ ç êîíñîë³"<<endl;
    cin>>a;
    if(a==1){
            btn -> fromFile();}
    else if (a==2){
            btn -> setJordan();}   
    btn -> doCalculate();
    cout<<"1 - Äëÿ çàïèñó ó ôàéë"<<endl;
    cin>>a;
    if (a==1){
              btn->inFile();}
	btk = objectFactory->createJordan("Object2");
    cout<<"1 - Äëÿ ââîäó ìàòðèö³ ç ôàéëó"<<endl<<"2 - Äëÿ ââîäó ìàòðèö³ ç êîíñîë³"<<endl;
    cin>>a;
    if(a==1){
            btk -> fromFile();}
    else if(a==2){
            btk -> setJordan();}
	btk -> doCalculate();
	cout<<"1 - Äëÿ çàïèñó ó ôàéë"<<endl;
    cin>>a;
    if (a==1){
              btk->inFile();}
              
    delete 	objectFactory;
    
	return 0;
	
}
