#include <iostream>
#include <cstdlib>

#include "Conector.hpp"

using namespace std;

int main(void) {

    /**TEST SQLITE*/

    Conector *conector = new Conector(SQLITE_DB);
    conector->conectar("/tmp/voip.db");

    conector->consulta("select * from extension");

    cout << "Se encontraron: " << conector->obtenerCantidadResultados() << endl;

        Resultado resultado;
    
        while (conector->obtenerResultado(resultado)) {
            cout << resultado["id_cuenta"] << " <=> " << resultado["host"] << endl;
            cout << endl << endl;
        }

    cout << "Escape: " << conector->escape("SELECT ID_CLIENTE FROM CLIENTE, USUARIO WHERE DATO = 'UNO%'") << endl;

    conector->desconectar();

    /**TEST MYSQL*/

    //    Conector *conector = new Conector(MYSQL_DB);
    //    conector->conectar("host", "usuario", "clave", "base de datos");

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
    //    conector->desconectar();

    return EXIT_SUCCESS;
}
