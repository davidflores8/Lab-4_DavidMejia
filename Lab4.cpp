#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

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

	return 0;	
}
