Aquí tienes exactamente lo que debes pegar en el archivo `README.md` de tu repositorio (y en tu documento de entrega) para cumplir con el **Paso 4** y **Paso 5**:

---

# Proyecto: Algoritmos de Ordenamiento en C++

Este proyecto contiene las implementaciones de **Bubble Sort** (versión base y optimizaciones) y **Selection Sort**, analizando su rendimiento, comparaciones e intercambios.

---

## Paso 4. Registro de Resultados

Resultados obtenidos al probar los algoritmos con los tres arreglos de prueba:

| Arreglo Evaluado | Algoritmo | Comparaciones | Intercambios |
| --- | --- | --- | --- |
| **`[5, 3, 8, 2]`** ($n=4$) | Bubble Sort Base | 9 | 4 |
|  | Bubble Sort (Mejora 1 - Swapped) | 9 | 4 |
|  | Bubble Sort (Mejora 2 - $n-i-1$) | 6 | 4 |
|  | Bubble Sort (Optimizado Completo) | 6 | 4 |
|  | Selection Sort | 6 | 2 |
| **`[1, 2, 3, 4, 5]`** ($n=5$) | Bubble Sort Base | 16 | 0 |
|  | Bubble Sort (Mejora 1 - Swapped) | 4 | 0 |
|  | Bubble Sort (Mejora 2 - $n-i-1$) | 10 | 0 |
|  | Bubble Sort (Optimizado Completo) | 4 | 0 |
|  | Selection Sort | 10 | 0 |
| **`[5, 4, 3, 2, 1]`** ($n=5$) | Bubble Sort Base | 16 | 10 |
|  | Bubble Sort (Mejora 1 - Swapped) | 16 | 10 |
|  | Bubble Sort (Mejora 2 - $n-i-1$) | 10 | 10 |
|  | Bubble Sort (Optimizado Completo) | 10 | 10 |
|  | Selection Sort | 10 | 2 |

---

## Paso 5. Análisis de Algoritmos y Complejidad

### 1. ¿Qué mejora tuvo mayor impacto en Bubble Sort?

Depende directamente del estado inicial del arreglo:

* **En arreglos ordenados o casi ordenados:** La **Mejora 1 (bandera swapped)** produce el impacto más drástico. Permite abortar el algoritmo en la primera pasada, reduciendo las comparaciones de forma inmediata de O(n²) a O(n).
* **En arreglos completamente desordenados o invertidos:** La **Mejora 2 (j < n - i - 1)** es la única que genera un impacto real, ya que elimina las comparaciones redundantes sobre los elementos que ya se encuentran en su posición final al extremo derecho. Reduce el número total de comparaciones de (n - 1)² a (n * (n - 1)) / 2 (un ahorro de aproximadamente 37.5% de comparaciones en un arreglo de n = 5).

### 2. ¿En qué caso Bubble Sort se vuelve más eficiente?

Se vuelve más eficiente en su **mejor caso**, el cual ocurre cuando el arreglo de entrada ya se encuentra completamente ordenado de menor a mayor y el algoritmo tiene implementada la Mejora 1. En este escenario, el algoritmo solo requiere realizar n - 1 comparaciones en una sola pasada para confirmar que no hubo intercambios y terminar la ejecución inmediatamente.

### 3. Comparar número de intercambios entre Bubble Sort y Selection Sort:

Selection Sort es significativamente más eficiente que Bubble Sort respecto al número de escrituras e intercambios en memoria:

* **Bubble Sort:** Realiza intercambios locales adyacentes de forma continua durante la fase de ordenamiento. En el peor de los casos (arreglo invertido), realiza un total de O(n²) intercambios (por ejemplo, 10 intercambios para n = 5).
* **Selection Sort:** Busca el elemento mínimo global de la sección desordenada en cada iteración externa y realiza **un máximo de 1 intercambio por ciclo**. En el peor caso realiza únicamente O(n) intercambios (solo 2 intercambios en el peor caso para n = 5).

### 4. ¿Se mantiene O(n²)? Explicar.

**Sí, la complejidad se mantiene en O(n²) para el peor caso y el caso promedio.**

Aun aplicando la Mejora 2, el número total de comparaciones en el peor caso viene dado por la expresión:

`(n * (n - 1)) / 2 = 0.5 * n² - 0.5 * n`

Bajo la definición de notación asintótica Big-O, las constantes multiplicativas (0.5) y los términos de menor orden (-0.5n) se ignoran, dejando como término dominante n². Por lo tanto, la complejidad asintótica sigue siendo O(n²).

### 5. ¿En qué caso Bubble Sort puede ser O(n)?

Bubble Sort alcanza una complejidad lineal O(n) únicamente en su **mejor caso**, bajo la condición estricta de que se cumplan dos factores:

1. El algoritmo tiene integrada la **Mejora 1** (bandera swapped para interrupción temprana).
2. El arreglo de entrada está **100% ordenado desde el inicio**.

Al cumplirse ambas condiciones, el bucle interno realiza únicamente n - 1 comparaciones, detecta que swapped permaneció en falso y rompe la ejecución del bucle exterior inmediatamente.
