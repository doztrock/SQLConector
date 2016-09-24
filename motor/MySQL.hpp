#ifndef MYSQL_HPP
#define MYSQL_HPP

#include <string>
#include <mysql/mysql.h>

#include "../Libreria.hpp"
#include "../Excepcion.hpp"

void __conectarMySQL(std::string host, std::string usuario, std::string clave, std::string db, MYSQL *link_MySQL);
void __desconectarMySQL(MYSQL *link_MySQL);

//bool Conector::__consultaMySQL(std::string query);

std::string __escapeMySQL(std::string cadena, MYSQL *link_MySQL);

int __filasAfectadasMySQL(MYSQL *link_MySQL);
int __lastidMySQL(MYSQL *link_MySQL);

#endif /* MYSQL_HPP */
