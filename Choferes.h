#pragma once
#include "tipos.h"
void menuChoferes();
void altaChofer();
bool guardarChofer(choferes chof);
choferes cargarChofer();
choferes leerRegistro(int pos);
int buscarDni(char *chof);
void listarChoferes();
void mostrarChoferes (choferes chof);
int cantRegistro();
void bajaChofer();
void modificarchofer();
bool guardarChoferMod(choferes chof, int pos);
void listarPorDni();