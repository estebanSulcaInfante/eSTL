# eSTL — Estructuras de Datos from Scratch en C++

![License](https://img.shields.io/badge/license-MIT-green)
![Build](https://img.shields.io/badge/build-passing-brightgreen)
![Docs](https://img.shields.io/badge/docs-Doxygen-blue)

> **Repositorio académico** para el curso **“Algoritmos y Estructuras de Datos”**.  
> Implementa versiones educativas de contenedores clásicos (listas, pilas, árboles…) sin recurrir a la STL nativa, con el objetivo de reforzar la comprensión de su lógica interna, complejidad y diseño simplificado.

---

## Contenido del proyecto

| Módulo (`include/…`) | Estructura                | Estado   |
|----------------------|---------------------------|----------|
| `eSinglyLinkedList`  | Lista enlazada simple     | Implementada |
| `eDoublyLinkedList`  | Lista doblemente enlazada | En progreso |
| `eStack`             | Pila basada en lista      | Planeado |
| `eQueue`             | Cola basada en lista      | Planeado |
| `eHashTable`         | Tabla Hash con su funcion | Planeado |

> Cada módulo se agrupa en carpetas independientes con sus cabeceras (`.h/.hpp`), implementaciones (`.tpp/.cpp`) y pruebas.

---

## Construcción y pruebas

```bash
# Clona el repositorio
git clone https://github.com/estebanSulcaInfante/eSTL.git && cd eSTL

# Compila los ejemplos (requiere CMake >= 3.20)
cmake -B build -S .
cmake --build build --config Release

# Ejecuta la batería de tests (Catch2/GoogleTest, según módulo)
ctest --test-dir build
