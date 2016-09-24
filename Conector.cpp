#include "Conector.hpp"

Conector::Conector(Motor motor) {
    this->motor = motor;
    this->indiceResultado = 0;
}

void Conector::conectar(std::string db) {

    switch (this->motor) {

        case SQLITE_DB:
            __conectarSQLite(db, this->link_SQLite);
            break;

        default:
            throw Excepcion("El motor no soporta los parametros de conexion especificados.");
            break;

    }

    return;
}
//
//void Conector::conectar(std::string host, std::string usuario, std::string clave, std::string db) {
//
//    switch (this->motor) {
//
//        case MYSQL_DB:
//           __conectarMySQL(host, usuario, clave, db);
//            break;
//
//        default:
//            throw Excepcion("El motor no soporta los parametros de conexion especificados.");
//            break;
//
//    }
//
//    return;
//}
//
//bool Conector::consulta(std::string query) {
//
//    bool resultado = false;
//
////    switch (this->motor) {
////
////        case SQLITE_DB:
////            resultado = this->__consultaSQLite(query);
////            break;
////
////        case MYSQL_DB:
////            resultado = this->__consultaMySQL(query);
////            break;
////
////    }
//
//    return resultado;
//}
//
//bool Conector::obtenerResultado(Resultado &resultado) {
//
//    Resultado vacio;
//
//    //    if (this->indiceResultado < this->listaResultado.size()) {
//    //
//    //        resultado = listaResultado.at(indiceResultado);
//    //        this->indiceResultado++;
//    //
//    //        return true;
//    //    } else {
//    //        resultado = vacio;
//    //    }
//
//    return false;
//}
//

void Conector::desconectar(void) {

    switch (this->motor) {

        case SQLITE_DB:
            __desconectarSQLite(this->link_SQLite);
            break;

        case MYSQL_DB:
//            __desconectarMySQL();
            break;

    }

    return;
}

std::string Conector::escape(std::string cadena) {

    std::string cadenaEscapada;

    switch (this->motor) {

        case SQLITE_DB:
            cadenaEscapada = __escapeSQLite(cadena);
            break;

        case MYSQL_DB:
//            cadenaEscapada = this->__escapeMySQL(cadena);
            break;

    }

    return cadenaEscapada;
}

int Conector::obtenerFilasAfectadas() {

    int cantidad = 0;

    switch (this->motor) {

        case SQLITE_DB:
            cantidad = __filasAfectadasSQLite(this->link_SQLite);
            break;

        case MYSQL_DB:
//            cantidad = this->__filasAfectadasMySQL();
            break;

    }

    return cantidad;
}

int Conector::obtenerLastID() {

    int last_id = 0;

    switch (this->motor) {

        case SQLITE_DB:
            last_id = __lastidSQLite(this->link_SQLite);
            break;

        case MYSQL_DB:
//            last_id = this->__lastidMySQL();
            break;

    }

    return last_id;
}
//
//unsigned long int Conector::obtenerCantidadResultados() {
//
//    if (!this->listaResultado.empty()) {
//        return this->listaResultado.size();
//    }
//
//    return 0;
//}