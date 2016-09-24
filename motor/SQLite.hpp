#ifndef SQLITE_HPP
#define SQLITE_HPP

#include <string>
#include <sqlite3.h>
#include <vector>

#include "../Libreria.hpp"
#include "../Excepcion.hpp"

using namespace std;

void __conectarSQLite(std::string db, sqlite3 *link_SQLite);
void __desconectarSQLite(sqlite3 *link_SQLite);

bool __consultaSQLite(std::string query, vector<Resultado>& listaResultado, sqlite3 *link_SQLite);

std::string __escapeSQLite(std::string cadena);

int __filasAfectadasSQLite(sqlite3 *link_SQLite);
int __lastidSQLite(sqlite3 *link_SQLite);

#endif /* SQLITE_HPP */
