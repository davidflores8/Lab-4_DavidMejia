#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

char** crearMatriz(int, int);
void printMatriz(char**, int, int);
void liberarMatriz(char**, int);
char** llenarMatriz(char**, int, int, string);

int main()
{
	int largo=0;
	int ancho=0;
	string principal="";
	cout<<"Ingrese el largo de la matriz: "<<endl;
	cin>>largo;
	while (largo<=0)
	{
		cout<<"Ingrese un largo valido en la matriz: "<<endl;
		cin>>largo;
	}
	cout<<"Ingrese el ancho de la matriz: "<<endl;
  	cin>>ancho;
        while (ancho<=0)
        {
                cout<<"Ingrese un largo valido en la matriz: "<<endl;
                cin>>ancho;
        }
	char p=' ';
	stringstream ss;
	for(int i=0;i<ancho;i++)
	{
		cout<<"Ingrese el caracter numero "<<i+1<<endl;
		cin>>p;
		while(p!='^' &&  p!='.')
		{
			cout<<"Ingrese ^ para trampas o  . para casillas seguras: "<<endl;
			cin>>p;
		}
		ss<<p;
	}
	principal=ss.str();
	char** matriz=NULL;
	matriz=crearMatriz(largo, ancho);
	matriz=llenarMatriz(matriz, largo, ancho, principal);
	printMatriz(matriz, largo, ancho);
	liberarMatriz(matriz, largo);
	return 0;	
}

void Cuenta (char** matriz, int ancho, int largo)
{


}

char** llenarMatriz(char** matriz, int largo, int ancho, string principal)
{
	char primero=' ';
	char segundo=' ';
	char tercero=' '; 
	for(int i=0;i<largo;i++)
	{
		for(int j=0;j<ancho;j++)
		{
			if(i==0)
			{
				matriz[i][j]=principal[j];
			}
			else
			{
				
				if (j==0)
				{
				
					primero='.';
					segundo=matriz[i-1][j];	
					tercero=matriz[i-1][j+1];	
				}
				else if(j==ancho-1)
				{
					primero=matriz[i-1][j-1];
					segundo=matriz[i-1][j];
					tercero='.';
				}
				else
				{
					primero=matriz[i-1][j-1];
					segundo=matriz[i-1][j];
					tercero=matriz[i-1][j+1];
				}
					
				if (primero=='^' && segundo=='^' && tercero=='.')
                                        		matriz[i][j]='^';
                                else if (primero=='.' && segundo=='^' && tercero=='^')
                                        		matriz[i][j]='^';
				else if (primero=='^' && segundo=='.' && tercero=='.')
                                        		matriz[i][j]='^';
	                        else if (primero=='.' && segundo=='.' && tercero=='^')
                                        		matriz[i][j]='^';
        	                else
                                        		matriz [i][j]='.';
		
				
				//cout<<"primero:  "<<primero<<"  Segundo:  "<<segundo<<"  Tercero: "<<tercero<<endl;
			}		
		}			
	}
	return matriz;
}

void liberarMatriz(char** matriz, int largo)
{
        for(int g=0;g<largo;g++)
        {
                if(matriz[g]!=NULL)
                {
                        delete[] matriz[g];
                        matriz[g]=NULL;
                }
        }
        if(matriz!=NULL)
        {
                delete[]matriz;
        }
}

void printMatriz(char** matrix, int largo, int ancho)
{
        for(int i=0;i<largo;i++)
        {
                for(int j=0;j<ancho;j++)
                {
                        cout<<"[ "<<matrix[i][j]<<" ] ";

                }
                cout<<" "<<endl;
        }
}


char** crearMatriz(int largo, int ancho)
{
	char**matriz=NULL;
	matriz=new char*[ancho];
	for(int i=0; i<largo;i++)
	{
		matriz[i]=new char[ancho];
	}
	return matriz;
}
