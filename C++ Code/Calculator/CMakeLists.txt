cmake_minimum_required(VERSION 3.5)

# Nome del progetto
project(CalculatorApp)

# Impostazione della versione di C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trova Qt5
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Aggiungi i file sorgente
set(SOURCES
    main.cpp
    Calculator.cpp
)

set(HEADERS
    Calculator.h
)

# Crea l'eseguibile
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Link Qt5
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)