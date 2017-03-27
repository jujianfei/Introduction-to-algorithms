#include <bits/stdc++.h>
using namespace std;
#define N 1007

map<int, int> mp; // 资源


struct IndexPriorityMinQueue {
    int pq[N]; // 这个索引的位置id是多少
    int qp[N]; // 某个id对应的索引
    int heap_size;
    IndexPriorityMinQueue() { // index from 1
        for (int i=0; i<N; i++) {
            qp[i] = -1;
        }
        heap_size = 0;
    }

    void exchange(int i, int j) { // 索引队列i位置和j位置需要交换

        int idi = pq[i];
        int idj = pq[j];
        swap(pq[i], pq[j]);
        swap(qp[idi], qp[idj]);
    }

    // if you want to change this to a max indexQ, modify this
    bool gt(int i, int j) { return mp[pq[i]] > mp[pq[j]]; }
    bool eq(int i, int j) { return mp[pq[i]] == mp[pq[j]]; }
    bool lt(int i, int j) { return mp[pq[i]] < mp[pq[j]]; }


    void swim(int k) {
        while (k > 1 && lt(k, k/2)) {
            exchange(k/2, k);
            k = k/2;
        }
    }

    void sink(int k) {
        while (2*k <= heap_size) {
            int j = 2 * k;
            if (j < N && gt(j, j+1)) j++;
            if (!gt(k, j)) break;
            exchange(k, j);
            k = j;
        }
    }

    bool contain(int id) {
        return qp[id] != -1;
    }

    void insert(int k, int src) {
        heap_size ++;
        qp[k] = heap_size;
        pq[heap_size] = k;
        mp[k] = src;
        swim(heap_size);
    }

    int get_min_src() {
        return mp[pq[1]];
    }

    int deleteMin() { // return the id
        int id_of_min = pq[1];
        exchange(1, heap_size--);
        sink(1);
        mp.erase(pq[heap_size+1]);
        // delete src
        qp[pq[heap_size+1]] = -1;

        return id_of_min;
    }

    void change(int id, int new_src) {
        mp[id] = new_src;
        swim(qp[id]);
        sink(qp[id]);
    }

    void delete_id(int id) {
        int index = qp[id];
        exchange(index, heap_size--);
        swim(index);
        sink(index);
        mp.erase(id);
        qp[id] = -1;
    }

    void debug() {
        cout << "size " << heap_size << endl;
        for (int i=1; i<=heap_size; i++) {
            cout << pq[i] << " -> " << mp[pq[i]] << endl;
        } cout << endl;

        for (int i=1; i<=10; i++) {
            cout << qp[i] << " ";
        } cout << endl;
    }
};


int main(){

    IndexPriorityMinQueue A;
    A.insert(1, 1234);
    A.insert(2, 23);
    A.insert(4, 1456);
    A.insert(5, 2);
    A.insert(8, 15);
    A.insert(3, 2222);
    A.insert(9, 1);
    A.insert(0, 12345);

    cout << A.get_min_src() << endl;
    A.change(9, 100000);
    cout << A.get_min_src() << endl;
    A.delete_id(5);
    cout << A.get_min_src() << endl;

}
