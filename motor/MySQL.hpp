#ifndef MYSQL_HPP
#define MYSQL_HPP

#include <string>
#include <mysql/mysql.h>
#include <vector>

#include "../Libreria.hpp"
#include "../Excepcion.hpp"

/*
 * Recurso de conexion a MySQL
 */
typedef MYSQL * LINK_MYSQL;

using namespace std;

void __conectarMySQL(std::string host, std::string usuario, std::string clave, std::string db, LINK_MYSQL &link_MySQL);
void __desconectarMySQL(LINK_MYSQL &link_MySQL);

bool __consultaMySQL(std::string query, vector<Resultado>& listaResultado, LINK_MYSQL &link_MySQL);

std::string __escapeMySQL(std::string cadena, LINK_MYSQL &link_MySQL);

int __filasAfectadasMySQL(LINK_MYSQL &link_MySQL);
int __lastidMySQL(LINK_MYSQL &link_MySQL);

#endif /* MYSQL_HPP */
