#include <iostream>
using namespace std;

int d,x1,y1,x2,y2;

int main(int argc, char** argv) {
	
	cout<<"Ingrese la dimension de la matriz: ";cin>>d;
	
	int Matriz[d][d];
	
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<d;j++)
		{
			Matriz[i][j]=0;
		}	
	}
	
	cout<<"Ingrese la posición Inicial: \n";
	cout<<"X: \n";cin>>x1;
	cout<<"Y: \n";cin>>y1;
	
	Matriz[x1][y1]=1; //POSICIÓN INICIAL
	
	cout<<"Ingrese la posición Final: \n";
	cout<<"X: \n";cin>>x2;
	cout<<"Y: \n";cin>>y2;
	
	Matriz[x2][y2]=2; // POSICIÓN FINAL
	
	int n=1;
	int Contador=0; // CONTAR MOVIMIENTO PARA LLEGAR
	
	while(x1!=x2 || y1!=y2)
	{
		// POSIBILIDADES
		if(x1>=x2 && y1>y2)
		{		
			x1-=n;
			y1-=n;
			Matriz[x1][y1]=1;
			Contador+=1;		
		
		}else if(x1<x2 && y1<y2)
				{
					x1+=n;
					y1+=n;
					Matriz[x1][y1]=1;
					Contador+=1;
				
				}else if(x1>x2 && y1<y2)
						{
							x1-=n;
							y1+=n;
							Matriz[x1][y1]=1;
							Contador+=1;	
						
						}else if(x1<x2 && y1>y2)
								{
									x1+=n;
									y1-=n;
									Matriz[x1][y1]=1;
									Contador+=1;	
								
								}
								
								// DIFERENTE A DIAGONAL
								
								if(x1==x2 && y1!=y2)
								{
									if(y1>y2)
									{
										y1-=n;
										Matriz[x1][y1]=1;
										Contador+=1;
									}else if(y1<y2)
										{
											y1+=n;
											Matriz[x1][y1]=1;
											Contador+=1;
										}			
								}else if(x1!=x2 && y1==y2)
										{
											if(x1>x2)
											{
												x1-=n;
												Matriz[x1][y1]=1;
												Contador+=1;
												
											}else if(x1<x2)
												{
													x1+=n;
													Matriz[x1][y1]=1;
													Contador+=1;
												}
											
										}
	}
	
	cout<<"\n========================\n";
	
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<d;j++)
		{
			cout<<Matriz[i][j]<<"\t";
		}	
		cout<<"\n";
	}
	
	cout<<"\n========================\n";
	
	cout<<"Con "<<Contador<<" movimientos";
	
	return 0;
}
