#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;
#include "Choferes.h"

const char archivoChoferes [] = ("choferes.dat");


void menuChoferes() {
    int opc;
    do
    {
        system("cls");
        cout << "--------------MENU CHOFERES----------------" << endl;
        cout << "--------------" << endl << endl;

        cout << "1) NUEVO CHOFER" << endl;
        cout << "2) MODIFICAR CHOFER" << endl;
        cout << "3) LISTAR CHOFER POR DNI" << endl;
        cout << "4) LISTAR TODOS LOS CHOFERES" << endl << endl;;
        cout << "5) ELIMINAR CHOFER" << endl;
        cout << "----------------------" << endl;
        cout << "0) VOLVER AL MENU PRINCIPAL" << endl << endl;
        cout << "INGRESE SU OPCION: "<<endl<<">";
        cin >> opc;
        system("cls");
        switch (opc)
        {
        case 1: altaChofer();
            break;
        case 2: //modificarChofer();
            break;
        case 3: //listarPorDni();
            break;
        case 4: listarChoferes();
            break;
        case 5: //eliminarChoferes();
            break;
        case 0:
            break;

        }
    } while (opc != 0);
}
 /*********************************************************************/
choferes cargarChofer() {
    int aux;
    choferes chof;
    

    cout<<"CARGAR DNI: ";
    cin >> chof.dni;   ///hasta 8 espacio y no vacios 
    cout<<"CARGAR APELLIDO: ";
    cin >> chof.apellido; //50 limite no vacia
    cout<<"CARGAR NOMBRE: ";
    cin >> chof.nombre; // 50 limite no vacia
    cout<<"FECHA DE INGRESO: "; // menor o igual a fecha actual
    cout << "DIA: ";
    cin >> chof.fechaIng.dia;
    cout << "MES: ";
    cin >> chof.fechaIng.mes;
    cout << "A" << (char)165 << "O: ";
    cin >> chof.fechaIng.año;
    cout<<"INGRESAR EL CUIT: ";
    cin >> chof.cuit; //cuit hasta 20 valor unico y que no sea vacio
    cout<<"TIPO DE REGISTRO: ";
    cin >> chof.tipoRegistro; //entre 1 y 3
    cout<<"FECHA DE VENCIMIENTO: "; // mayor a fecha del sistema
    cout << "DIA: ";
    cin >> chof.fechaVen.dia;
    cout << "MES: ";
    cin >> chof.fechaVen.mes;
    cout << "A" << (char)165 << "O: ";
    cin >> chof.fechaVen.año;
    cout << "TELEFONO: ";
    cin >> chof.telefono; // sea de 15
    cout << "PROPIETARIO DEL AUTO (S/N):";
    cin >> chof.propietario; /// PONER EL AUX 

    if (chof.propietario=='S') {
        chof.propietario == true;
    }
    else
    {
        chof.propietario == false;
    }
    chof.estado == true;

    system("cls");

    return chof;
}
/****************************************************************************/
bool guardarChofer(choferes chof) {

    FILE* p;
        p = fopen(archivoChoferes, "ab");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO";
        system("pause");
        system("cls");
        return false;
    }
    if (fwrite(&chof, sizeof(chof), 1, p) == true) {
        
        fclose(p);
        cout << "REGISTRO GUARDADO CON EXITO";
        system("pause");
        return true;
    }

    fclose(p);
}
/***********************************************************************/
void altaChofer() {
    int pos;
    choferes reg;

    reg=cargarChofer();
    pos = buscarDni(reg.dni);
    if (pos != -1) {
        cout << "EL DNI YA EXISTE" << endl<<endl;
        system("pause");
        return;
    }
    guardarChofer(reg);

}
/********************************************************************/
int buscarDni(char* chof) {
    FILE* p;
    choferes reg;
    int pos = 0;
    p = fopen(archivoChoferes, "rb");
    if (p == NULL) return -1;
    while (fread(&reg, sizeof(choferes), 1, p) == 1) {
        if (strcmp(reg.dni, chof) == 0) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}
/***********************************************************/
void listarChoferes() {

    FILE* p;
    p = fopen(archivoChoferes, "rb");
    if (p == NULL) {
        cout << "ERROR AL CARGAR ARCHIVO";
        system("pause");
        system("cls");
        return;
    }
    choferes chof;
        while (fread(&chof,sizeof(chof),1,p)==1)
        {
            mostrarChoferes(chof);

        }
        system("pause");
    fclose(p);
}
/*******************************************************************/
void mostrarChoferes(choferes chof) {

    if (chof.estado == false) return;
    
        cout << "DNI:" << chof.dni << endl;
        cout << "CARGAR APELLIDO: "<<chof.apellido << endl;
        cout << "CARGAR NOMBRE: "<<chof.nombre << endl;
        cout << "FECHA DE INGRESO: "<< chof.fechaIng.dia <<"/"<< chof.fechaIng.mes << "/" << chof.fechaIng.año << endl;
        cout << "INGRESAR EL CUIT: "<<chof.cuit << endl;
        cout << "TIPO DE REGISTRO: "<<chof.tipoRegistro << endl;
        cout << "FECHA DE VENCIMIENTO: " << chof.fechaVen.dia << "/" << chof.fechaVen.mes << "/" << chof.fechaVen.año << endl;
        cout << "TELEFONO: "<<chof.telefono << endl;
        if (chof.propietario == 1) {
            cout << "PROPIETARIO DEL AUTO : S" << endl;
        }
        else
        {
            cout << "PROPIETARIO DEL AUTO : N" << endl;
        }
        cout << "--------------------------------------------------" << endl << endl;
    
}



