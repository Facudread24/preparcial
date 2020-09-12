#pragma once
struct fecha
{
    int dia;
    int mes;
    int año;
};

struct choferes
{
    char dni[10];
    char apellido[50];
    char nombre[50];
    fecha fechaIng;
    char cuit[20];
    int tipoRegistro;
    fecha fechaVen;
    char telefono[15];
    bool propietario;
    bool estado;

};