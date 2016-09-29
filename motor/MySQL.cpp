#include "MySQL.hpp"

/**
 * Realiza la conexion a MySQL Server.
 * @param String Servidor
 * @param String Usuario de MySQL
 * @param String Clave del usuario
 * @param String Nombre de la base de datos
 */
void __conectarMySQL(std::string host, std::string usuario, std::string clave, std::string db, LINK_MYSQL &link_MySQL) {

    link_MySQL = mysql_init(NULL);

    if (link_MySQL != NULL) {

        if (mysql_real_connect(link_MySQL, (const char *) host.c_str(), (const char *) usuario.c_str(), (const char *) clave.c_str(), (const char *) db.c_str(), 0, NULL, 0) == NULL) {
            __desconectarMySQL(link_MySQL);
            throw ExcepcionMYSQL(mysql_error(link_MySQL));
        }

    } else {
        throw ExcepcionMYSQL(mysql_error(link_MySQL));
    }

    return;
}

/**
 * Realiza la desconexion del MySQL Server.
 */
void __desconectarMySQL(LINK_MYSQL &link_MySQL) {

    if (link_MySQL != NULL) {
        mysql_close(link_MySQL);
    }

    return;
}

/**
 * Realiza la consulta de MySQL, 
 * de modo que si la consulta corresponde a una obtencion de resultados, 
 * guardara el resultado para poder recuperarse posteriormente.
 * @param String Consulta a realizar
 * @return Boolean Estado de la consulta
 */
bool __consultaMySQL(std::string query, vector<Resultado>& listaResultado, LINK_MYSQL &link_MySQL) {

    MYSQL_RES *resultado = NULL;
    MYSQL_ROW row = NULL;
    MYSQL_FIELD *campo = NULL;
    int rc;

    std::string columna;
    std::string valor;

    if (strtoupper(query.substr(0, 6)).compare("SELECT") == 0) {

        rc = mysql_query(link_MySQL, (const char *) query.c_str());

        if (rc) {
            throw ExcepcionMYSQL(mysql_error(link_MySQL));
        }

        if (mysql_field_count(link_MySQL) > 0) {

            if ((resultado = mysql_store_result(link_MySQL)) != NULL) {

                while ((row = mysql_fetch_row(resultado))) {

                    Resultado fila;

                    for (unsigned int i = 0; i < (unsigned int) mysql_num_fields(resultado); i++) {

                        campo = mysql_fetch_field_direct(resultado, i);

                        columna = campo->name;
                        valor = row[i];

                        fila[columna] = valor;

                    }

                    listaResultado.insert(listaResultado.end(), fila);
                }

            } else {
                throw ExcepcionMYSQL(mysql_error(link_MySQL));
            }

        }

    } else {

        rc = mysql_query(link_MySQL, (const char *) query.c_str());

        if (rc) {
            throw ExcepcionMYSQL(mysql_error(link_MySQL));
        }

    }

    return true;
}

/**
 * Realiza la secuencia de escape para las cadenas en SQLite.
 * @param String Cadena a escapar
 * @return String Cadena escapada
 */
std::string __escapeMySQL(std::string cadena, LINK_MYSQL &link_MySQL) {

    unsigned long longitud;
    char cadenaEscapada[cadena.size()];

    longitud = mysql_real_escape_string(link_MySQL, cadenaEscapada, (const char *) cadena.c_str(), cadena.size());

    cadenaEscapada[longitud] = '\0';

    return std::string(cadenaEscapada);
}

/**
 * Retorna el total de filas que fueron afectadas por la operacion.
 */
int __filasAfectadasMySQL(LINK_MYSQL &link_MySQL) {
    return mysql_affected_rows(link_MySQL);
}

/**
 * Retorna el ultimo identificador afectado.
 */
int __lastidMySQL(LINK_MYSQL &link_MySQL) {
    return mysql_insert_id(link_MySQL);
}