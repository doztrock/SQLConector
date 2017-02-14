# Compilador
CC=g++

# Libreria Compartida
LIBNAME=libsqlconector

# Flags
CFLAGS=-Wall -O3
FLAGS=-lsqlite3 -I/usr/include/mysql -fabi-version=2 -fno-omit-frame-pointer -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -ldl

# Dependencias
DEPENDENCIAS=Conector.o Libreria.o 
MOTORES=motor/SQLite.o motor/MySQL.o

all: dependencias motores
	$(CC) $(CFLAGS) $(DEPENDENCIAS) $(MOTORES) -Wl,-soname=$(LIBNAME).so -o $(LIBNAME).so -fpic -shared -shared-libgcc

clean:
	rm -f conector-test $(DEPENDENCIAS) $(MOTORES)

dependencias: $(DEPENDENCIAS)

motores: $(MOTORES)

.cpp.o:
	$(CC) $(CFLAGS) $(FLAGS) -c -o $*.o $<
