#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

// Estructura para almacenar los contadores de operaciones
struct Metrics {
    int comparisons = 0;
    int swaps = 0;
};

// ==========================================
// 1. Bubble Sort Base
// ==========================================
Metrics bubbleSortBase(vector<int> arr) {
    Metrics m;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            m.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                m.swaps++;
            }
        }
    }
    return m;
}

// ==========================================
// 2. Bubble Sort - Mejora 1 (Detección de Arreglo Ordenado)
// ==========================================
Metrics bubbleSortMejora1(vector<int> arr) {
    Metrics m;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Variable para detectar intercambios
        for (int j = 0; j < n - 1; j++) {
            m.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                m.swaps++;
                swapped = true;
            }
        }
        // Si no hubo intercambios en toda la iteración, el arreglo ya está ordenado
        if (!swapped) break;
    }
    return m;
}

// ==========================================
// 3. Bubble Sort - Mejora 2 (Reducción del Límite del Ciclo)
// ==========================================
Metrics bubbleSortMejora2(vector<int> arr) {
    Metrics m;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Se reduce el ciclo a j < n - i - 1 porque los últimos 'i' elementos ya están ordenados
        for (int j = 0; j < n - i - 1; j++) {
            m.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                m.swaps++;
            }
        }
    }
    return m;
}

// ==========================================
// 4. Bubble Sort - Completamente Optimizado (Mejora 1 + Mejora 2)
// ==========================================
Metrics bubbleSortOptimizado(vector<int> arr) {
    Metrics m;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            m.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                m.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return m;
}

// ==========================================
// 5. Selection Sort
// ==========================================
Metrics selectionSort(vector<int> arr) {
    Metrics m;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            m.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Encuentra el elemento mínimo en el subarreglo desordenado
            }
        }
        // Solo intercambia si se encontró un nuevo mínimo
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            m.swaps++;
        }
    }
    return m;
}

// Función auxiliar para imprimir métricas
void printMetrics(const string& name, Metrics m) {
    cout << name << " -> Comparaciones: " << m.comparisons << " | Intercambios: " << m.swaps << endl;
}

int main() {
    vector<vector<int>> testCases = {
        {5, 3, 8, 2},
        {1, 2, 3, 4, 5},
        {5, 4, 3, 2, 1}
    };

    for (size_t k = 0; k < testCases.size(); k++) {
        cout << "\n================ PROBANDO ARREGLO " << (k + 1) << " ================\n";
        cout << "Arreglo inicial: [";
        for (size_t i = 0; i < testCases[k].size(); i++) {
            cout << testCases[k][i] << (i + 1 < testCases[k].size() ? ", " : "");
        }
        cout << "]\n\n";

        printMetrics("Bubble Sort Base            ", bubbleSortBase(testCases[k]));
        printMetrics("Bubble Sort (Mejora 1)      ", bubbleSortMejora1(testCases[k]));
        printMetrics("Bubble Sort (Mejora 2)      ", bubbleSortMejora2(testCases[k]));
        printMetrics("Bubble Sort (Optimizado)    ", bubbleSortOptimizado(testCases[k]));
        printMetrics("Selection Sort              ", selectionSort(testCases[k]));
    }

    return 0;
}
