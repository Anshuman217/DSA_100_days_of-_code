#include <stdio.h>
#include <stdlib.h>

struct Car {
    int pos;
    double time;
};

int compare(const void* a, const void* b) {
    return ((struct Car*)b)->pos - ((struct Car*)a)->pos;
}

int carFleet(int target, int* position, int positionSize, int* speed, int speedSize) {
    if (positionSize == 0) return 0;

    struct Car* cars = malloc(positionSize * sizeof(struct Car));
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    qsort(cars, positionSize, sizeof(struct Car), compare);

    int fleets = 0;
    double max_time = 0.0;

    for (int i = 0; i < positionSize; i++) {
        if (cars[i].time > max_time) {
            max_time = cars[i].time;
            fleets++;
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);

    int result = carFleet(target, position, n, speed, n);
    printf("%d\n", result);

    return 0;
}