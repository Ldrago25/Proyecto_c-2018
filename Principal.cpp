#include "Principal.h"

Principal::Principal()
{
}

Principal::~Principal()
{
}

void Principal::mainApp()
{
	escribirArchivo();	
	Cifrar();
	DesCifrar();
	Mostrar();
}

void Principal::Cifrar()
{
	string linea;
	int n_lineas = 0;
	
	ifstream archivo (Nombre_Archivo.c_str(), std::ifstream::in);
	
	//unsigned int vect[tamaño de las letras/4];
	
	
	while(getline(archivo, linea)){
		n_lineas++;
	}
	cout << "lineas del archivo: " << n_lineas << endl;
	
	archivo.clear();
	archivo.seekg(0);
	
	while(getline(archivo,linea)){			
	
		//cout << "linea: " << linea << endl;
		
		unsigned int palabra;
		
		string auxiliar;
		
		int j=0;
		
		for(int i=0; i<linea.length(); i++)
		{
			if(j == 4){
				//cout << "GUARDO LEGAL la verga" << endl;
				j = 0;
				//cout << "el auxiliar es: (" << auxiliar << ")" << endl;
				for(int y = auxiliar.length()-1; y>=0;y--){
					palabra |= auxiliar.at(y);
					//cout << "result = " << palabra << endl;
					if(y>0){
						palabra<<=8;
					}
				}
				letras.push_back(palabra);
				palabra = 0;
				auxiliar.clear();
			}
			if(j < 4){
				//cout << "a:" << palabra << " b: " << linea.at(i) << endl;
				auxiliar += linea.at(i);
				//cout << "result = " << palabra << endl;
				//palabra<<=8;
				j++;
			}			
		}
		if(j <= 4){
			for(int i=0;i<4-j;i++)
			{
				//cout << "agregue un espacio" << endl;
				auxiliar += " ";
			}
			//cout << "el auxiliar es: (" << auxiliar << ")" << endl;
			for(int y = auxiliar.length()-1; y>=0;y--){
				palabra |= auxiliar.at(y);
				//cout << "result = " << palabra << endl;
				if(y>0){
					palabra<<=8;
				}
			}
			letras.push_back(palabra);
		}
	}
	
}

void Principal::escribirArchivo()
{
	char respuesta;
	
	cout<<endl<<"Nombre del archivo a crear: "<<endl;
	cin.sync();
	getline(cin,Nombre_Archivo);
	
	Nombre_Archivo+=".txt";
	
	Archivo.open(Nombre_Archivo.c_str(),ios::out);
	
	if(Archivo.fail())
	{
		cout<<endl<<"El archivo no se creo"<<endl;
		exit(0);	
	}else
	{
		do{
			cout<<endl<<"Que quiere escribirle al archivo: "<<endl;
			
			cin.sync();
			getline(cin,Frase);
			Archivo<<Frase;
			Archivo << "\n";
			
			cout<< "¿quiere otra linea? S/N" << endl;
			cin>>respuesta;
			respuesta = toupper(respuesta);
			system("cls");
		}while(respuesta == 'S');
		
		Archivo.close();
	}
}

void Principal::DesCifrar()
{
	int n_lineas=0;
	string linea;
	
	ofstream enteros;
	
	enteros.open("ENTEROS.txt",ios::out);
		
	for(int i=0 ; i<letras.size() ; i++)
	{
		enteros<<letras[i]<<endl;
	}
		
	ifstream numeros ("ENTEROS.txt", std::ifstream::in);
	
	while(getline(numeros, linea)){
		n_lineas++;
	}
	
	cout << "lineas: " << n_lineas << endl;
	
	numeros.clear();
	numeros.seekg(0);
	
	unsigned int numeros_linea;
	unsigned int movimiento;
	int mascara = 255;
	unsigned int auxiliar;
	
	char letra[4];	
	
	while(getline(numeros,linea)){			
	
		//cout << "linea: " << linea << endl;
				
		numeros_linea = atoi(linea.c_str());
		
		//cout<< "numeros :" << numeros_linea<< endl;
		//system("pause");
		
		movimiento = numeros_linea;
		
		
			for(int i = 0 ; i < 4 ; i++)
			{
				auxiliar = movimiento;
							
				if(i != 0)
				{
					auxiliar >>= i*8;
					//cout << "lei: " << auxiliar<<endl;
				}
				
				auxiliar &= mascara;
				
				letra[i] = auxiliar;
				
				//cout << "lei: " << auxiliar<<endl;
				
				cout<< letra[i];	
			}
			cout<<endl;
	}
}

void Principal::Mostrar()
{
	for(int i=0; i< letras.size(); i++){
		cout << letras[i] << endl;
	}
	system("pause");
}
