#include <stdio.h>

void maxHeapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i) {
        int t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        maxHeapify(a, n, largest);
    }
}

void minHeapify(int a[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && a[l] < a[smallest])
        smallest = l;
    if (r < n && a[r] < a[smallest])
        smallest = r;

    if (smallest != i) {
        int t = a[i];
