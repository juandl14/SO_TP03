# SO_TP03

## Trabajo Práctico Nº3 - Sockets

### Autores
* Borracci, Ángeles - 56648
* De Luca, Juan Manuel - 60103
* Kim, Azul Candelaria - 60264

### Contenidos:
1. Prerrequisitos
2. Compilación
3. Ejecución

---

#### 1. Prerrequisitos:
Clonar este repositorio

#### 2. Compilación:
Para compilar ingrese, en una terminal, el siguiente comando en el mismo directorio donde se encuentra el archivo llamado *Makefile*:
```
$ make all
```
Esto creará los ejecutables _newServer_ y _client_ necesarios para el funcionamiento del trabajo.

#### 3. Ejecución
Para iniciar el servidor, ejecutar el siguiente comando:
```
$ ./newServer
```
Para iniciar el cliente, ejecutar el siguiente comando en otra terminal:
```
$ ./client
```
Alternativamente, el client ofrece la opción de resolver hasta el desafío deseado si se le pasa un entero entre 1 y 12 (como mínimo resuelve sólo el primer desafío y como máximo completa todos los desafíos) como único argumento, de la siguiente manera:
```
$ ./client <NUMBER>
```
Así, se resolverá hasta el desafío indicado por <NUMBER>. De esta manera, si se corre:
```
$ ./client 12
```
Se resolverán todo los desafíos.

---

Finalmente y una vez terminada la ejecución, si se quieren remover los archivos creados en la compilación, debe utilizarse el siguiente comando en la terminal:
```
$ make clean
```