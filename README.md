[![C++](https://img.shields.io/badge/C%2B%2B-Programming-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![CMake](https://img.shields.io/badge/CMake-Build%20System-064F8C?logo=cmake&logoColor=white)](https://cmake.org/)
[![Git](https://img.shields.io/badge/Git-Version%20Control-F05032?logo=git&logoColor=white)](https://git-scm.com/)

Repositorio personal orientado a la práctica, organización y documentación de soluciones de algoritmia en C++.

Este proyecto forma parte de mi portafolio técnico y reúne ejercicios, laboratorios y exámenes resueltos aplicando estructuras de datos, recursividad, fuerza bruta y técnicas fundamentales de programación.

---

## Sobre el Proyecto

`Algorithms` es un repositorio enfocado en fortalecer habilidades de resolución de problemas mediante implementaciones en C++.

El objetivo principal es mantener una base de soluciones organizada, clara y progresiva, que refleje práctica constante en algoritmia, estructuras de datos y desarrollo de código mantenible.

Este repositorio demuestra:

- Resolución de problemas algorítmicos.
- Implementación de soluciones en C++.
- Uso de CMake para proyectos de compilación.
- Organización modular por tema o técnica.
- Reutilización de código común.
- Manejo de estructuras de datos fundamentales.
- Control de versiones con Git.

---

## Tecnologías Utilizadas

- C++
- CMake
- Git
- GitHub

---

## Áreas de Práctica

El repositorio incluye soluciones relacionadas con:

- Fuerza bruta
- Recursividad
- Listas simplemente enlazadas
- Manejo de punteros
- Modularización de código
- Separación de archivos fuente y cabecera
- Implementación de funciones auxiliares
- Organización de proyectos con CMake

---

## Estructura General

```text
algorithms/
├── brute-force/
│   ├── exams/
│   ├── exercises/
│   └── labs/
│
├── recursive/
│   ├── exercises/
│   └── labs/
│
├── simply-linked-list/
│   ├── exercises/
│   └── labs/
│
├── lab-statements/
├── library/
└── README.md
```

---

## Módulos Principales

### brute-force

Contiene soluciones basadas en evaluación directa, exploración completa de posibilidades y estrategias de fuerza bruta.

Este módulo permite practicar análisis de casos, construcción de soluciones iniciales y validación de lógica antes de aplicar optimizaciones.

### recursive

Contiene problemas resueltos mediante recursividad.

Este módulo refuerza el razonamiento por subproblemas, casos base, llamadas recursivas y descomposición progresiva de soluciones.

### simply-linked-list

Contiene ejercicios relacionados con listas simplemente enlazadas.

Este módulo trabaja conceptos como nodos, punteros, inserción, recorrido, eliminación y manipulación dinámica de memoria.

### library

Contiene código reutilizable para apoyar diferentes soluciones.

Actualmente incluye una biblioteca para listas enlazadas con estructuras y funciones auxiliares.

### lab-statements

Contiene enunciados de laboratorios y exámenes utilizados como referencia para las soluciones.

---

## Enfoque Técnico

El repositorio busca mantener soluciones comprensibles, organizadas y fáciles de revisar.

Cada problema suele estar compuesto por archivos como:

```text
main.cpp
Funciones.cpp
Funciones.h
CMakeLists.txt
```

Esta separación permite distinguir entre:

- Punto de entrada del programa.
- Implementación de funciones.
- Declaraciones y estructuras.
- Configuración de compilación.

---

## Compilación

La mayoría de proyectos utilizan CMake.

Ejemplo general de compilación:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Algunos ejercicios tienen su propio archivo `CMakeLists.txt`, por lo que la compilación debe ejecutarse desde la carpeta correspondiente.

---

## Buenas Prácticas Aplicadas

Este repositorio aplica buenas prácticas como:

- Separación entre archivos `.cpp` y `.h`.
- Uso de carpetas por tema o técnica.
- Centralización de recursos compartidos.
- Reutilización de estructuras comunes.
- Nombres consistentes para facilitar navegación.
- Exclusión de archivos generados por compilación o IDE.
- Commits descriptivos para documentar cambios relevantes.

---

## Valor como Portafolio

Este proyecto evidencia práctica en fundamentos importantes para desarrollo de software:

- Pensamiento algorítmico.
- Programación estructurada en C++.
- Manejo de memoria y punteros.
- Diseño modular.
- Organización de repositorios.
- Uso de herramientas de construcción.
- Control de versiones.

Aunque el repositorio tiene origen académico, está organizado con una visión profesional para mostrar evolución técnica, disciplina de trabajo y capacidad de mantener una base de código clara.

---

## Estado del Proyecto

Proyecto en desarrollo activo.

Actualmente se encuentra en una etapa de organización, limpieza estructural y consolidación de soluciones.

---

## Autor

**Ivan Baltazar**

Repositorio personal de práctica y portafolio técnico en algoritmia y C++.
