#ifndef SQLITE_HPP
#define SQLITE_HPP

#include <string>
#include <sqlite3.h>
#include <vector>

#include "../Libreria.hpp"
#include "../Excepcion.hpp"

/*
 * Recurso de conexion a SQLite
 */
typedef sqlite3 * LINK_SQLITE;

using namespace std;

void __conectarSQLite(std::string db, LINK_SQLITE &link_SQLite);
void __desconectarSQLite(LINK_SQLITE &link_SQLite);

bool __consultaSQLite(std::string query, vector<Resultado>& listaResultado, LINK_SQLITE &link_SQLite);

std::string __escapeSQLite(std::string cadena);

int __filasAfectadasSQLite(LINK_SQLITE &link_SQLite);
int __lastidSQLite(LINK_SQLITE &link_SQLite);

#endif /* SQLITE_HPP */
