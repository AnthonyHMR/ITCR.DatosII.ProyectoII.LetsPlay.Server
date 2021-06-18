# Área Académica de Ingeniería en Computadores
## Algoritmos y Estructuras de Datos II
### Profesor:
#### Antonio González Torres
### Estudiantes:
#### Anthony Montero
#### Juan Peña
#### Josué Granados
## Proyecto II - SI 2021
Se trata de un programa llamado mserver, indicando como parámetro el puerto en el que está escuchando que maneja el flujo de eventos en un juego.
## Acerca del servidor
El servidor interpreta las solicitudes provenientes del cliente según como se va desarrollando el juego. Sus tareas se dividen en dos juegos:
### BP Game:
El servidor debe recibir toda la lógica que permite almacenar jugadores de un tablero tipo futbolín, donde cada uno tiene una ubicación, identificación y un equipo.
En el servidor se implementan dos algoritmos de _pathfinding_ A* y _backtracking_ para dos propósitos: uno cuando el modo de juego es Equipo 1 vs Equipo 2 y otro cuando el modo es Equipo 1 vs Máquina.  
### Genetic Puzzle:
El servidor debe implementar un algoritmo genético que se usa para aproximar una imagen fraccionada, donde cada generación es almacenada en un archivo XML que se acerca más a la imagen completa conforme se hace la mutación.

## Bibliotecas necesarias 
Este proyecto fue realizado en Ubuntu(Linux) en el lenguaje C++
Primero se necesita una biblioteca de manejo de archivos JSON. Se puede instalar con los siguientes comandos:

`apt-get update`
`do apt-get install nlohmann-json3-dev`

## Doocumentación interna:
### [Doxygen de algoritmos](https://github.com/AnthonyHMR/ITCR.DatosII.ProyectoII.LetsPlay.Server/tree/main/doc/Algorithms)
### [Doxygen de Estructuras de datos](https://github.com/AnthonyHMR/ITCR.DatosII.ProyectoII.LetsPlay.Server/tree/main/doc/DataStructures)
### [Doxygen del Server](https://github.com/AnthonyHMR/ITCR.DatosII.ProyectoII.LetsPlay.Server/tree/main/doc/Server)
