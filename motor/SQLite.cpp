#include "SQLite.hpp"

/**
 * Realiza la conexion a SQLite.
 * @param String Ruta de la base de datos
 */
void __conectarSQLite(std::string db, sqlite3 *link_SQLite) {

    const char *fichero = db.c_str();
    int rc;

    rc = sqlite3_open_v2(fichero, &link_SQLite, SQLITE_OPEN_READWRITE, NULL);

    if (rc != SQLITE_OK) {
        __desconectarSQLite(link_SQLite);
        throw ExcepcionSQLITE(sqlite3_errmsg(link_SQLite));
    }

    return;
}

/**
 * Realiza la desconexion del SQLite.
 */
void __desconectarSQLite(sqlite3 *link_SQLite) {

    if (link_SQLite != NULL) {
        sqlite3_close(link_SQLite);
    }

    return;
}
//
///**
// * Realiza la consulta de SQLite, 
// * de modo que si la consulta corresponde a una obtencion de resultados, 
// * guardara el resultado para poder recuperarse posteriormente.
// * @param String Consulta a realizar
// * @return Boolean Estado de la consulta
// */
//bool __consultaSQLite(std::string query) {
//
//    sqlite3_stmt *resultado = NULL;
//    int rc;
//
//    string columna;
//    string valor;
//
//    sqlite3_prepare_v2(this->link_SQLite, query.c_str(), query.size(), &resultado, NULL);
//
//    if (strtoupper(query.substr(0, 6)).compare("SELECT") == 0) {
//
//        this->indiceResultado = 0;
//
//        while (sqlite3_step(resultado) == SQLITE_ROW) {
//
//            Resultado fila;
//
//            for (int indice = 0; sqlite3_column_text(resultado, indice) != NULL; indice++) {
//
//                columna = string((const char *) sqlite3_column_name(resultado, indice));
//                valor = string((const char *) sqlite3_column_text(resultado, indice));
//
//                fila[columna] = valor;
//
//            }
//
//            this->listaResultado.insert(this->listaResultado.end(), fila);
//        }
//
//    } else {
//
//        rc = sqlite3_step(resultado);
//
//        if (rc != SQLITE_DONE) {
//            throw ExcepcionSQLITE(sqlite3_errmsg(this->link_SQLite));
//        }
//
//    }
//
//    sqlite3_finalize(resultado);
//    return true;
//}
//

/**
 * Realiza la secuencia de escape para las cadenas en SQLite.
 * @param String Cadena a escapar
 * @return String Cadena escapada
 */
std::string __escapeSQLite(std::string cadena) {
    return std::string(sqlite3_mprintf(cadena.c_str()));
}

/**
 * Retorna el total de filas que fueron afectadas por la operacion.
 */
int __filasAfectadasSQLite(sqlite3 *link_SQLite) {
    return sqlite3_changes(link_SQLite);
}

/**
 * Retorna el ultimo identificador afectado.
 */
int __lastidSQLite(sqlite3 *link_SQLite) {
    return sqlite3_last_insert_rowid(link_SQLite);
}