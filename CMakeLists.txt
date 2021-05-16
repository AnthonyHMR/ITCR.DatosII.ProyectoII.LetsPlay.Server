cmake_minimum_required(VERSION 3.17)
project(ITCR_DatosII_ProyectoII_LetsPlay_Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(ITCR_DatosII_ProyectoII_LetsPlay_Server src/cr.ac.itcr.Server/main.cpp src/cr.ac.itcr.Server/mServer.cpp src/cr.ac.itcr.Server/mServer.h src/cr.ac.itcr.Algorithms/Backtracker.h src/cr.ac.itcr.Algorithms/Backtracker.cpp)