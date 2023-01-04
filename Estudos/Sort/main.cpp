#include <iostream>
#include <cstdlib> 
#include <chrono>
using namespace std;

template< typename T >
void bubblesort(T A[], int l, int r) {
    bool trocou = true;
    for(int i = l; i < r && trocou; i++) {
        trocou = false;
        for(int j = r; j > i; j--) {
            if(A[j] < A[j-1]) {
                T aux = A[j];
                A[j] = A[j-1];
                A[j-1] = aux;
                trocou = true;
            }
        }
    }
}

template <typename T>
void insertionsort(T A[], int l, int r) {
    for(int i = l+1; i <= r; i++) {
        T key = A[i];
        int j = i-1;
        while(j >= l &&  A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

template <typename T>
void selectionsort(T A[], int l, int r) {
    for(int i = l; i < r; i++) {
        int min = i;
        for(int j = i+1; j <= r; j++) {
            if(A[j] < A[min]) {
                min = j;
            }
        }
        T aux = A[i];
        A[i] = A[min];
        A[min] = aux;
    }
}

template <typename T>
void merge(T A[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    T L[n1], R[n2];
    for(int i = 0; i < n1; i++) {
        L[i] = A[l+i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = A[m+1+j];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergesort(T A[], int l, int r) {
    if(l < r) {
        int m = (l+r)/2;
        mergesort(A, l, m);
        mergesort(A, m+1, r);
        merge(A, l, m, r);
    }
}

template <typename T>
int partition(T A[], int l, int r) {
    T pivot = A[r];
    int i = l-1;
    for(int j = l; j < r; j++) {
        if(A[j] <= pivot) {
            i++;
            T aux = A[i];
            A[i] = A[j];
            A[j] = aux;
        }
    }
    T aux = A[i+1];
    A[i+1] = A[r];
    A[r] = aux;
    return i+1;
}

template <typename T>
void quicksort(T A[], int l, int r) {
    if(l < r) {
        int p = partition(A, l, r);
        quicksort(A, l, p-1);
        quicksort(A, p+1, r);
    }
}

template< typename T >
void testa_algoritmo(T vec[], int l, int r, string nome, void (*func)(T[], int, int)){
    auto start = std::chrono::steady_clock::now();
    func(vec, l, r);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = end-start;
    auto duration = 
        std::chrono::duration_cast<std::chrono::microseconds>(elapsed_time);
    cout << "\ntime : " << nome << " " << duration.count() << " microseconds" << endl;
}

template< typename T >
void print(T A[], int l, int r) {
    for(int i = l; i <= r; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 9000; 
    int vec[n];
    for(int i = 0; i < n; ++i) {
        vec[i] = rand() % 100;
    }

    testa_algoritmo(vec, 0, n-1, "bubblesort", bubblesort);
    testa_algoritmo(vec, 0, n-1, "insertionsort", insertionsort);
    testa_algoritmo(vec, 0, n-1, "selectionsort", selectionsort);
    testa_algoritmo(vec, 0, n-1, "quicksort", quicksort);

    return 0;
}