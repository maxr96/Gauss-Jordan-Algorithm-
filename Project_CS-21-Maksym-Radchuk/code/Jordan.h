#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Jordan : public File{
    public:
        virtual void setJordan();        
        virtual void doCalculate();
};

void Jordan::setJordan()
   {
        cout<<"Введіть кількість рівнянь : "; 
        cin>>NEQ;
        N1=NEQ+1;
        cout<<"ВВІД "<<endl;
           A=new float *[NEQ];
           for (int i = 0; i<NEQ; i++)
              A[i] = new float [N1];
        for(int i=0;i<NEQ;i++)  
           for(int j=0;j<N1;j++)
           {
            cout<<"Введіть елемент матриці["<<i+1<<"]"<<"["<<j+1<<"]=";
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
                       cout<<endl<<"*** НУЛЬОВИЙ ЕЛЕМЕНТ НА ДІАГОНАЛІ ";
                         cout<<N<<" ПІД ЧАС ВИКОНАННЯ***"<<endl;
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
    cout<<endl<<"ВИВІД"<<endl<<endl;
      for(int i=0;i<NEQ;i++){
        for(int j=N1-1;j<N1;j++){
          cout<<setprecision(2)<<setw(5)<<"x"<<i+1<<"="<<A[i][j];}
             cout<<endl;}
}