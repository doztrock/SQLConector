#include <iostream>
#include <cstdlib>

#include "Conector.hpp"

using namespace std;

int main(void) {

    /**
     * Prueba SQLITE
     */
    const string DATA_DB = "/home/ivan/data.db";
    Resultado resultadoCliente;
    Resultado resultadoDato;
    string consulta;

    Conector *conector = new Conector(SQLITE_DB);
    conector->conectar(DATA_DB);

    //Cliente
    
    consulta = "SELECT * FROM cliente";
    conector->consulta(consulta);

    cout << "Se encontraron: " << conector->obtenerCantidadResultados() << " resultados." << endl;

    while (conector->obtenerResultado(resultadoCliente)) {
        cout << resultadoCliente["id_cliente"] << " <=> " << resultadoCliente["nombre"] << endl;
    }

    //Dato
    
    consulta = "SELECT * FROM dato";
    conector->consulta(consulta);

    cout << "Se encontraron: " << conector->obtenerCantidadResultados() << " resultados." << endl;

    while (conector->obtenerResultado(resultadoCliente)) {
        cout << resultadoCliente["id_dato"] << " <=> " << resultadoCliente["valor"] << endl;
    }

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
