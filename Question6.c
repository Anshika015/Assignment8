#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void insert(int x) {
    heap[size] = x;
    int i = size;
    size++;

    while (i > 0 && heap[(i-1)/2] < heap[i]) {
        int t = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

int deleteMax() {
    if (size == 0)
        return -1;

    int max = heap[0];
    heap[0] = heap[size-1];
    size--;

    int i = 0;
    while (1) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int biggest = i;

        if (l < size && heap[l] > heap[biggest])
            biggest = l;
        if (r < size && heap[r] > heap[biggest])
            biggest = r;

        if (biggest != i) {
            int t = heap[i];
            heap[i] = heap[biggest];
            heap[biggest] = t;
            i = biggest;
        } else break;
    }

    return max;
}

void display() {
    if (size == 0) {
        printf("Empty\n");
        return;
    }
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int ch, val;

    while (1) {
        printf("1.Insert\n2.Delete Max\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            scanf("%d", &val);
            insert(val);
        }
        else if (ch == 2) {
            val = deleteMax();
            if (val == -1)
                printf("Empty\n");
            else
                printf("Deleted = %d\n", val);
        }
        else if (ch == 3) {
            display();
        }
        else
            break;
    }
    return 0;
}
