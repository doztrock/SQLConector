# Conector

##### 1) Descripcion.
_Que pasaria si desarrollasemos una aplicacion, cuyo objetivo es interactuar con una base de datos, pero la desarrollamos adaptada a un motor en especifico y un dia de imprevisto, tenemos que migrarnos de motor??_. Seria algo terrible no crees?. **SQLConector** intenta proveer una solucion a este problema, para las aplicaciones desarrolladas en _C++_ que interactuen con una base de datos, permitiendo de una manera mucho mas sencilla realizar conexion con algunos de los motores de base de datos mas usados en la actualidad. Y asi mismo, permitir de un momento migrar de un motor a otro e incluso usar multiples motores sin necesidad de realizar grandes esfuerzos en lo que al codigo respecta.


#### 2) Motores Soportados.
En el momento SQLConector soporta conexion con los motores:

* SQLite
* MySQL


#### 3) Como utilizar SQLConector?
SQLConector es muy sencillo de utilizar!!
Lo primero que debemos hacer es clonar nuestro repositorio de git:

`git clone algo.git`

Despues de clonar el repositorio

Incluimos nuestro _header_ en el programa donde haremos uso del SQLConector


`#include "SQLConector/Conector.hpp"`

Y listo!!

PD: Continuamos mas abajo ;)

Para no hacer mas larga la explicacion, incluire un pedazo de codigo de conexion de SQLite:

`
int main(void){

Conector *conector = new Conector(SQLITE_DB);
    conector->conectar("/tmp/archivo.db");

    conector->consulta("SELECT * FROM tabla");

    cout << "Se encontraron: "<< conector->obtenerCantidadResultados() << endl;
    
    Resultado resultado;

    while (conector->obtenerResultado(resultado)) {
        cout << resultado["valor"] << " <=> " << resultado["texto"] << endl;
        cout << endl << endl;
    }

    conector->desconectar();
}
`