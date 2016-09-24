#include "Libreria.hpp"

string strtolower(string cadena) {

    string data = cadena;
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);

    return data;
}

string strtoupper(string cadena) {

    string data = cadena;
    std::transform(data.begin(), data.end(), data.begin(), ::toupper);

    return data;
}