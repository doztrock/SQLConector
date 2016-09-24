#ifndef EXCEPCION_HPP
#define EXCEPCION_HPP

#include <exception>

using namespace std;

/**
 * EXCEPCION GENERAL
 */
class Excepcion : public exception {
private:
    const char *__mensaje;
public:

    Excepcion(const char *mensaje) : __mensaje(mensaje) {
    }

    const char *what() const throw () {
        return __mensaje;
    }

};

/**
 * EXCEPCION SQLITE 
 */
class ExcepcionSQLITE : public exception {
private:
    const char *__mensaje;
public:

    ExcepcionSQLITE(const char *mensaje) : __mensaje(mensaje) {
    }

    const char *what() const throw () {
        return __mensaje;
    }

};

/**
 * EXCEPCION MYSQL
 */
class ExcepcionMYSQL : public exception {
private:
    const char *__mensaje;
public:

    ExcepcionMYSQL(const char *mensaje) : __mensaje(mensaje) {
    }

    const char *what() const throw () {
        return __mensaje;
    }

};

#endif /* EXCEPCION_HPP */
