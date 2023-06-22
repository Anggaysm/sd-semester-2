#include <stdio.h>
#include <iostream>

using namespace std;

 struct tipeS
{
	struct tipeS *Left;
	int info;
	struct tipeS *Right;
};
typedef struct tipeS simpul;
simpul *P,*FIRST,*LAST,*PVertex,*PEdge,*Q,*R,*S;
simpul *PointS[5];

int main()
{
	int A [5][5]= {{0,8,0,2,0}, {6,0,3,0,0}, {0,0,0,0,9}, {0,0,12,0,7}, {0,14,0,0,0}};
	int NmS [5] = {1,2,3,4,5};
	int i,j;
	
	//simpul pertama
	i=0;j=0;
	P= new simpul;
	P->info=NmS[0];
	FIRST=P;
	LAST=P;
	P->Left=NULL;
	P->Right==NULL;
	PointS[0]=P;
	cout<<P->info;
	cout<<" alamat :"<<PointS[0]<<endl;
	
	//simpul vertex yang berikutnya
	for (i=1;i<=4;i++)
	{
		P= new simpul;
		P->info = NmS[i];
		LAST->Left =P;
		LAST= LAST->Left;
		P->Left=NULL;
		P->Right=NULL;
		PointS[i]=P;
		cout<<P->info;
		cout<<" alamat :"<<PointS[i]<<endl;
	}
	
	//simpul Edge untuk semua vertex
	cout<<endl;
	Q = FIRST;
	for (i=0;i<=4;i++)
	{
		R=Q;
		cout<<"Vertex "<<Q->info ;
		for (j=0;j<=4;j++)
		{
			if (A[i][j] !=0)
			{
				P = new simpul;
				P->info = A[i][j];
				R->Right = P;
				P->Left = PointS[j];
				cout<<" berhubungan dengan :"<<P->Left->info;
				cout<<" bobot "<<P->info;
				P->Right=NULL;
				R=P;
			}
		}
		cout<<endl;
		Q = Q->Left;
	}
	return 0;
}