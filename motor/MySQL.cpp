#include "MySQL.hpp"
//
///**
// * Realiza la conexion a MySQL Server.
// * @param String Servidor
// * @param String Usuario de MySQL
// * @param String Clave del usuario
// * @param String Nombre de la base de datos
// */
//void Conector::__conectarMySQL(std::string host, std::string usuario, std::string clave, std::string db) {
//
//    this->link_MySQL = mysql_init(NULL);
//
//    if (this->link_MySQL != NULL) {
//
//        if (mysql_real_connect(this->link_MySQL, (const char *) host.c_str(), (const char *) usuario.c_str(), (const char *) clave.c_str(), (const char *) db.c_str(), 0, NULL, 0) == NULL) {
//            this->__desconectarMySQL();
//            throw ExcepcionMYSQL(mysql_error(this->link_MySQL));
//        }
//
//    } else {
//        throw ExcepcionMYSQL(mysql_error(this->link_MySQL));
//    }
//
//    return;
//}
//
///**
// * Realiza la desconexion del MySQL Server.
// */
//void Conector::__desconectarMySQL() {
//
//    if (this->link_MySQL != NULL) {
//        mysql_close(this->link_MySQL);
//    }
//
//    return;
//}
//
///**
// * Realiza la consulta de MySQL, 
// * de modo que si la consulta corresponde a una obtencion de resultados, 
// * guardara el resultado para poder recuperarse posteriormente.
// * @param String Consulta a realizar
// * @return Boolean Estado de la consulta
// */
//bool Conector::__consultaMySQL(std::string query) {
//
//    MYSQL_RES *resultado = NULL;
//    MYSQL_ROW row = NULL;
//    MYSQL_FIELD *campo = NULL;
//    int rc;
//
//    std::string columna;
//    std::string valor;
//
//    if (strtoupper(query.substr(0, 6)).compare("SELECT") == 0) {
//
//        rc = mysql_query(this->link_MySQL, (const char *) query.c_str());
//
//        if (rc) {
//            throw ExcepcionMYSQL(mysql_error(this->link_MySQL));
//        }
//
//        if (mysql_field_count(this->link_MySQL) > 0) {
//
//            if ((resultado = mysql_store_result(this->link_MySQL)) != NULL) {
//
//                this->indiceResultado = 0;
//
//                while ((row = mysql_fetch_row(resultado))) {
//
//                    Resultado fila;
//
//                    for (unsigned int i = 0; i < (unsigned int) mysql_num_fields(resultado); i++) {
//
//                        campo = mysql_fetch_field_direct(resultado, i);
//
//                        columna = campo->name;
//                        valor = row[i];
//
//                        fila[columna] = valor;
//
//                    }
//
//                    this->listaResultado.insert(this->listaResultado.end(), fila);
//                }
//
//            } else {
//                throw ExcepcionMYSQL(mysql_error(this->link_MySQL));
//            }
//
//        }
//
//    } else {
//
//        rc = mysql_query(this->link_MySQL, (const char *) query.c_str());
//
//        if (rc) {
//            throw ExcepcionMYSQL(mysql_error(this->link_MySQL));
//        }
//
//    }
//
//    return true;
//}
//
///**
// * Realiza la secuencia de escape para las cadenas en SQLite.
// * @param String Cadena a escapar
// * @return String Cadena escapada
// */
//std::string Conector::__escapeMySQL(std::string cadena) {
//
//    unsigned long longitud;
//    char cadenaEscapada[cadena.size()];
//
//    longitud = mysql_real_escape_string(this->link_MySQL, cadenaEscapada, (const char *) cadena.c_str(), cadena.size());
//
//    cadenaEscapada[longitud] = '\0';
//
//    return std::string(cadenaEscapada);
//}
//
///**
// * Retorna el total de filas que fueron afectadas por la operacion.
// */
//int Conector::__filasAfectadasMySQL() {
//    return mysql_affected_rows(this->link_MySQL);
//}
//
///**
// * Retorna el ultimo identificador afectado.
// */
//int Conector::__lastidMySQL() {
//    return mysql_insert_id(this->link_MySQL);
//}