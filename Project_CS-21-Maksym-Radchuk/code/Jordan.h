#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

class Jordan{
	private:
	    int NEQ, N1;
		float A[50][50];
	public:
		Jordan(){
			NEQ=1;
			N1=1;
			for (int i=0;i<=NEQ;i++){
				for(int j=0;j<=N1;j++){
					A[i][j]=0;
				}
			}
		}
     	void setJordan(){
		cout<<"������ ������� ������ : ";
	    cin>>NEQ;
	    N1=NEQ+1;
	    	if(N1>50){
		cout<<"*** ���̲� �ղ��ί �����ֲ "<<NEQ<<" �������Ӫ ";
		cout<<"���������� ���̲� �����ֲ ***"<<endl;
		exit(0);
	}
	   	cout<<"������ ������ ������� : "<<endl;
	     for(int i=1;i<=NEQ;i++){
		   for(int j=1;j<=N1;j++){
			cin>>A[i][j];
	         	}
        	}
		}
		void doCalculate(){
			int N, j, i;
			float D,D1;
			for(N=1;N<=NEQ;N++){
				if(A[N][N]==0){
					cout<<endl<<"*** �������� ������� �'���ߪ���� �� Ĳ�����˲ ";
					cout<<N<<" ϲ� ��� ��������� ***"<<endl;
					exit(0);
				}
				D=(1/A[N][N]);
				for(j=1;j<=N1;j++){
					A[N][j]=D*A[N][j];
				}
				for(i=1;i<=NEQ;i++){
					if(i==N){
						i=i+1;
					}
					D1=A[i][N];
					for(j=1;j<=N1;j++){
						A[i][j]=A[i][j]-D1*A[N][j];
					}
				}
					A[N][N]=1;
				}
				cout<<endl<<"��²�"<<endl<<endl;
     	for(i=1;i<=NEQ;i++){
		    for(j=1;j<=N1;j++){
			    cout<<setprecision(2)<<setw(5)<<A[i][j];
	    	}
	    	cout<<endl;
       	}
	}
};
