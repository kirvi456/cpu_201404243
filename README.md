# Modulo CPU

Modulo que muestra la informacion de los procesos corriendo en el sistema.

### Prerequisites

What things you need to install the software and how to install them

```
GitHub
Gcc
TextEditor
```

### Installing

Clonar este repositorio https://github.com/kirvi456/cpu_201404243.git

```
git clone 
```

Compilar archivo

```
make all
```
Insertar modulo

```
sudo insmod cpu_201404243.ko
```
Verificar mensaje de insersion

```
dmesg
```
Verificar informacion de los procesos en el directorio proc/

```
cd /proc/
cat cpu_201404243
```
Se deberia abrir el archivo con la informacion del PID, Nombre y Estado de los procesos que estan corriendo en el sistema.


## Descripcion del Codigo

Para la obtencion de los datos referentes a los procesos se consulto la estructura tasks_structs, la cual contiene un lista con la metadata de los procesos en ella, algo asi como correr un ps aux, luego se procedio a recorrer la lista de procesos para mostrar la informacion de cada uno de ellos.

## Authors

* **Bryan Ordoñez** - *Sistemas Operativos 1*


## License

Bajo licencia GLP.
