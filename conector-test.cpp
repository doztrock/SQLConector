#include <iostream>
#include <cstdlib>

#include <ctime>
#include <sstream>
#include <unistd.h>

#include "Conector.hpp"

using namespace std;

string generarNumero(void) {

    stringstream numero;
    srand(time(NULL));

    numero << rand() % 1000000 + 100000;

    return numero.str();
}

int main(void) {

    Conector *conector = new Conector(MYSQL_DB);
    conector->conectar("localhost", "root", "Slptshr369*", "prueba");

    //    conector->consulta("select * from cliente");
    //
    //    cout << "Se encontraron: " << conector->obtenerCantidadResultados() << " resultados." << endl;
    //
    //    Resultado resultado;
    //
    //    while (conector->obtenerResultado(resultado)) {
    //        cout << resultado["id_cliente"] << " <=> " << resultado["nombre"] << endl;
    //        cout << endl << endl;
    //    }
    //
    //    cout << "Escape: " << conector->escape("SELECT ID_CLIENTE FROM CLIENTE, USUARIO WHERE DATO = 'UNO%'") << endl;
    //
    conector->desconectar();

    return EXIT_SUCCESS;
}
