# Algorithms

[![C++](https://img.shields.io/badge/language-C%2B%2B-00599C?logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![CMake](https://img.shields.io/badge/build-CMake-064F8C?logo=cmake&logoColor=white)](https://cmake.org/)
[![GitHub Actions](https://img.shields.io/github/actions/workflow/status/IvanBaltazar-Dev/ControlLocal/cmake.yml?branch=main&label=build&logo=githubactions&logoColor=white)](../../actions)
[![Last Commit](https://img.shields.io/github/last-commit/IvanBaltazar-Dev/ControlLocal?logo=git&logoColor=white)](../../commits/main)
[![Repo Size](https://img.shields.io/github/repo-size/IvanBaltazar-Dev/ControlLocal?logo=github&logoColor=white)](../../)
[![License](https://img.shields.io/github/license/IvanBaltazar-Dev/ControlLocal)](./LICENSE)

Repositorio personal para organizar, resolver y documentar problemas de algoritmia, laboratorios, exámenes y ejercicios prácticos en C++.

Este proyecto está diseñado como una base de estudio y portafolio técnico, manteniendo una estructura clara, escalable y consistente para evidenciar progreso en resolución de problemas, diseño de soluciones y manejo ordenado de código fuente.

---

## Tabla de Contenidos

- [Descripción](#descripción)
- [Objetivo del Repositorio](#objetivo-del-repositorio)
- [Tecnologías](#tecnologías)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Convención de Nombres](#convención-de-nombres)
- [Convención para PDFs](#convención-para-pdfs)
- [Módulos Principales](#módulos-principales)
- [Librería Reutilizable](#librería-reutilizable)
- [Compilación](#compilación)
- [Flujo de Trabajo](#flujo-de-trabajo)
- [Buenas Prácticas](#buenas-prácticas)
- [Estado del Proyecto](#estado-del-proyecto)
- [Autor](#autor)

---

## Descripción

`Algorithms` es un repositorio enfocado en la práctica progresiva de algoritmia usando C++.

El contenido está organizado por técnica, tema o estructura de datos. Cada laboratorio, examen o ejercicio se ubica dentro de una categoría específica y sigue una convención de nombres uniforme para facilitar la navegación, búsqueda y mantenimiento del proyecto.

El repositorio prioriza:

- Organización clara del código.
- Separación entre soluciones y enunciados.
- Reutilización de estructuras auxiliares.
- Convenciones consistentes de nombres.
- Escalabilidad para nuevos ciclos, laboratorios y exámenes.

---

## Objetivo del Repositorio

El objetivo principal es construir una base técnica organizada para el estudio de algoritmos y estructuras de datos.

Este repositorio busca servir como:

- Registro académico de laboratorios y exámenes.
- Portafolio técnico de soluciones en C++.
- Base de práctica para algoritmia.
- Espacio para mejorar diseño, orden y mantenibilidad del código.
- Referencia personal para futuros problemas similares.

---

## Tecnologías

El proyecto utiliza principalmente:

- C++
- CMake
- Git
- GitHub
- GitHub Actions

---

## Estructura del Proyecto

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
│
├── library/
│   └── BibliotecaLista/
│
├── README.md
└── .gitignore
```

---

## Convención de Nombres

Los directorios de trabajos académicos siguen el formato:

```text
<tipo>-<numero>_<ciclo>_p<pregunta>
```

Donde:

- `<tipo>` representa el tipo de trabajo.
- `<numero>` representa el número del laboratorio o examen.
- `<ciclo>` representa el ciclo académico.
- `<pregunta>` representa el número de pregunta o problema.

Valores esperados:

```text
tipo: lab | ex
numero: 01, 02, 03, ...
ciclo: YYYY-N
pregunta: p1, p2, p3, ...
```

Ejemplos válidos:

```text
lab-01_2025-2_p1
lab-02_2025-2_p2
ex-01_2025-2_p3
```

---

## Convención para PDFs

Los enunciados se almacenan en el directorio `lab-statements/`.

El formato para PDFs es:

```text
<tipo>-<numero>_<ciclo>.pdf
```

Ejemplos:

```text
lab-01_2024-1.pdf
lab-02_2025-2.pdf
ex-01_2025-2.pdf
```

Los PDFs no deben almacenarse dentro de las carpetas de soluciones, salvo que exista una razón específica para hacerlo.

---

## Módulos Principales

### brute-force

Contiene soluciones desarrolladas mediante estrategias de fuerza bruta.

```text
brute-force/
├── exams/
├── exercises/
└── labs/
```

Este módulo agrupa problemas donde se exploran soluciones directas, búsqueda exhaustiva o evaluación completa de posibilidades.

---

### recursive

Contiene soluciones basadas en recursividad.

```text
recursive/
├── exercises/
└── labs/
```

Este módulo se enfoca en problemas donde la solución se construye mediante llamadas recursivas, reducción del problema o exploración de subcasos.

---

### simply-linked-list

Contiene implementaciones y problemas relacionados con listas simplemente enlazadas.

```text
simply-linked-list/
├── exercises/
└── labs/
```

Este módulo agrupa ejercicios donde se aplican estructuras dinámicas, nodos, punteros y operaciones sobre listas.

---

## Librería Reutilizable

El directorio `library/` contiene código auxiliar reutilizable.

Actualmente incluye:

```text
library/
└── BibliotecaLista/
```

`BibliotecaLista` contiene estructuras y funciones relacionadas con listas enlazadas, tales como:

- Definición de nodos.
- Definición de listas.
- Elementos de lista.
- Funciones auxiliares.
- Operaciones reutilizables.

La intención de esta carpeta es evitar duplicación innecesaria de código cuando varios problemas comparten estructuras similares.

---

## Compilación

La mayoría de soluciones utilizan C++ y CMake.

Archivos típicos por ejercicio:

```text
main.cpp
Funciones.cpp
Funciones.h
CMakeLists.txt
```

Compilación general:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

En algunos casos, cada laboratorio o examen puede tener su propio archivo `CMakeLists.txt`, por lo que la compilación debe ejecutarse desde la carpeta correspondiente.

---

## Flujo de Trabajo

Al agregar un nuevo laboratorio, examen o ejercicio:

1. Identificar la categoría principal.
2. Crear el directorio usando la convención establecida.
3. Agregar los archivos fuente de la solución.
4. Guardar el PDF del enunciado en `lab-statements/`.
5. Reutilizar código desde `library/` cuando corresponda.
6. Verificar que no se agreguen archivos generados por el IDE o la compilación.
7. Confirmar los cambios con un mensaje de commit descriptivo.

Ejemplo:

```text
brute-force/labs/lab-01_2026-1_p1/
lab-statements/lab-01_2026-1.pdf
```

---

## Buenas Prácticas

Se recomienda mantener las siguientes reglas:

- Usar nombres en minúsculas.
- Usar dos dígitos para laboratorios y exámenes.
- Mantener una estructura consistente entre módulos.
- Separar soluciones de enunciados.
- Evitar subir archivos compilados.
- Evitar subir carpetas generadas por IDEs.
- Mantener los commits claros y descriptivos.
- Reutilizar librerías comunes cuando sea posible.

Ejemplos correctos:

```text
lab-01_2025-1_p1
lab-01_2025-1_p2
lab-02_2025-2_p1
ex-01_2025-2_p3
```

Ejemplos a evitar:

```text
2025-1_lab-01_p1
2025-2-ex1_p3
lab_2025_1_P2
Laboratorio01_Algoritmia
```

---

## .gitignore Recomendado

Se recomienda excluir archivos generados automáticamente:

```gitignore
.idea/
cmake-build-debug/
CMakeFiles/
cmake_install.cmake
CMakeCache.txt
compile_commands.json
*.exe
*.obj
*.o
```

---

## GitHub Actions

Este repositorio puede integrarse con GitHub Actions para validar automáticamente compilaciones con CMake.

Ejemplo de workflow recomendado:

```yaml
name: CMake Build

on:
  push:
    branches:
      - main
  pull_request:
    branches:
      - main

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
      - name: Checkout repository
        uses: actions/checkout@v4

      - name: Configure CMake
        run: cmake -S . -B build

      - name: Build project
        run: cmake --build build
```

El badge de GitHub Actions del inicio del README espera un workflow llamado:

```text
cmake.yml
```

Ubicación esperada:

```text
.github/workflows/cmake.yml
```

Si el workflow tiene otro nombre, se debe actualizar la URL del badge.

---

## Estado del Proyecto

Este repositorio se encuentra en desarrollo activo.

Áreas actuales de trabajo:

- Normalización de estructura.
- Organización de enunciados.
- Reutilización de código común.
- Mejora progresiva de soluciones.
- Automatización futura de validaciones.

---

## Autor

**Ivan Baltazar**

Repositorio orientado al aprendizaje, práctica y documentación de algoritmia en C++.

---

## Nota Final

La organización del repositorio está pensada para crecer con nuevos ciclos, laboratorios, exámenes y ejercicios sin perder claridad estructural.

La prioridad del proyecto es mantener una base limpia, consistente y útil como referencia técnica personal y como portafolio profesional.
