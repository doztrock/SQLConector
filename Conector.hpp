#ifndef CONECTOR_HPP
#define CONECTOR_HPP

#include <string>
#include <vector>

#include "Libreria.hpp"
#include "Excepcion.hpp"

#include "motor/SQLite.hpp"
#include "motor/MySQL.hpp"

using namespace std;

/**
 * Tipo de motor
 */
typedef enum _motor {
    SQLITE_DB, MYSQL_DB
} Motor;

class Conector {
private:

    /*Motor*/
    Motor motor;

    /*SQLite*/
    sqlite3 *link_SQLite;

    /*MYSQL*/
    MYSQL *link_MySQL;

    /*Resultados*/
    unsigned int indiceResultado;
    vector<Resultado> listaResultado;

public:

    /*Constructor*/
    Conector(Motor motor);

    /**
     * METODOS PUBLICOS
     */

    /*Conexion*/
    void conectar(std::string db);
    //    void conectar(std::string host, std::string usuario, std::string clave, std::string db);
    //
    //    /*Consulta*/
    //    bool consulta(std::string query);
    //    bool obtenerResultado(Resultado &resultado);

    /*Desconexion*/
    void desconectar(void);

    /*Metodos Comunes*/
    std::string escape(std::string cadena);
    int obtenerFilasAfectadas(void);
    int obtenerLastID(void);
    //    unsigned long int obtenerCantidadResultados(void);

};

#endif /* CONECTOR_HPP */

