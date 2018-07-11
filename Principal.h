#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Principal
{
	string Frase;
	string Nombre_Archivo;
	string Frase2;
	
	vector <unsigned int> letras;
	ofstream Archivo;
	
	public:
		Principal();
		~Principal();
		
		void mainApp();
		
		void Cifrar();
		
		void DesCifrar();
		
		void Mostrar();
		
		void escribirArchivo();
		
		void leerArchivo();		
		
	protected:
};

#endif
