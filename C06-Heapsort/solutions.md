```
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

#define N 107
struct Heap {
    int a[N];
    int length, heap_size;
    Heap() { // index from 1
        memset(a, 0, sizeof(a));
        heap_size = 0;
        length = 10;
    }
    void debug() {
        cout << "size " << heap_size << endl;
        for (int i=1; i<=length; i++) {
            cout << a[i] << " ";
        } cout << endl;
    }
};

// sink i-th element to the bottom
void max_heapfy(Heap& A, int i) {
    while (2 * i <= A.heap_size) {
        int j = 2 * i;
        if (j+1 <= A.heap_size && A.a[j] < A.a[j+1]) j++;
        if(A.a[i] > A.a[j]) break;
        else swap(A.a[i],A.a[j]);
        i = j;
    }
}

// sink i-th element to the bottom recursively
void max_heapfy_recursively(Heap& A, int i) {
    if (2 * i > A.heap_size) return;
    int l = i * 2;
    int r = i* 2 + 1;
    int largest;
    if (l <= A.heap_size && A.a[l] > A.a[i])
        largest = l;
    else
        largest = i;

    if (r <= A.heap_size && A.a[r] > A.a[largest])
        largest = r;
    if (largest != i) {
        swap(A.a[i], A.a[largest]);
        max_heapfy_recursively(A, largest);
    }
}

// build a max heap
void build_max_heap(Heap& A) {
    A.heap_size = A.length;
    for (int i=A.length/2; i>=1; i--) {
         max_heapfy(A, i);
    }
}


void heap_sort(Heap& A) {
    for (int i=A.length; i>=2; i--) {
        swap(A.a[1], A.a[i]);
        A.heap_size --;
        max_heapfy(A, 1);
    }
}

//get the max element from heap
int extract_max(Heap& A) {
    if (A.heap_size < 1) throw runtime_error("under flow");
    int ret_max = A.a[1];
    A.a[1] = A.a[A.heap_size];
    A.heap_size --;
    max_heapfy(A, 1);
    return ret_max;
}

void heap_increase_key(Heap& A, int i, int key) {
    if (key < A.a[i]) throw runtime_error("new key is smaller");

    while (i > 1 && A.a[i/2] < key) {
        A.a[i] = A.a[i/2];
        i = i/2;
    }

    A.a[i] = key;
}


void heap_delete(Heap& A, int i) {
    swap(A.a[i], A.a[A.heap_size]);
    A.heap_size -= 1;
    max_heapfy(A, i);
}


void max_heap_insert(Heap& A, int key) {
    A.heap_size += 1;
    A.a[A.heap_size] = -INF;
    heap_increase_key(A, A.heap_size, key);
}


int main() {
    Heap A;
    for (int i=1; i<=10; i++) {
        A.a[i] = i;
    }
    build_max_heap(A);
    //heap_sort(A);
    heap_delete(A, 4);
    A.debug();

    Heap B;
    max_heap_insert(B, 2);
    max_heap_insert(B, 1);
    max_heap_insert(B, 4);
    max_heap_insert(B, 3);

    cout << extract_max(B) << endl;
}
```