#ifndef __MINIDB_H__
#define __MINIDB_H__
#include "BinaryTree.h"
class MiniDB
{
    ifstream archivo;
    vector<vector<string>> minidb;
    string cadena;
    BinaryTree<vector<vector<string>> *> *IndexTree;

public:
    MiniDB()
    {   
        IndexTree = new BinaryTree<vector<vector<string>> *>;
    }
    void reading(string nombre, char ans)
    {
        archivo.open(nombre);
        while (getline(archivo, cadena))
        {
            stringstream ss(cadena);
            if(ans=='s')
            cout<<cadena<<endl;
            divideField(ss);
        }
    }
    void divideField(istream &registro)
    {
        vector<string> fila;
        string tmp;
        while (getline(registro, tmp, ';'))
        {
            fila.push_back(tmp);
        }
        minidb.push_back(fila);
    }
    void ShowValues()
    {
        cout << endl
             << "Cantidad de filas: " << minidb.size() << endl;
        cout << endl
             << "Cantidad de columnas: " << minidb[0].size() << endl;
    }

 
};

#endif // !__MINIDB_H__
