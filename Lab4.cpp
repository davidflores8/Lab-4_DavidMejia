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
	for(int i=0;i<largo;i++)
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
	printMatriz(matriz, largo, ancho);
	liberarMatriz(matriz, largo);

	return 0;	
}

void liberarMatriz(char** matriz, int largo)
{
        for(int g=0;g<largo;g++)
        {
                if(matriz[g]!=NULL)
                {
                        delete[]matriz[g];
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
                        cout<<matrix[i][j]<<" ";

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
