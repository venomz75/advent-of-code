#include <stdio.h>
#include <string.h>
#include <limits.h>

int wrapping = 0;
int ribbon = 0;

int main() {
    char line[100];
    FILE *file = fopen("input.txt", "r");

    if (file) {
        while(fgets(line, 100, file)) {
            int dims[3]; //L, W, H
            int i = 0;

            char* token = strtok(line, "x"); 
            while (token) {
                sscanf (token, "%d", &dims[i++]);
                token = strtok(NULL,"x");
            }
            int largest = 0;
            int largest_index = -1;
            for (int i = 0; i < 3; i++) {
                if (dims[i] > largest) {largest = dims[i]; largest_index = i;}
            }

            for (int i = 0; i < 3; i++) {
                if (i != largest_index) {ribbon += 2*dims[i];}
            }
            ribbon += dims[0] * dims[1] * dims[2];
            int areas[3]; //L*W, W*H, H*L
            areas[0] = dims[0] * dims[1];
            areas[1] = dims[1] * dims[2];
            areas[2] = dims[2] * dims[0];
            int smallest = INT_MAX;

            for (int i = 0; i < 3; i++) {
                if (areas[i] < smallest) {smallest = areas[i];}
            }
            wrapping += (2*areas[0] + 2*areas[1] + 2*areas[2] + smallest);
        }
        printf("Total wrapping area: %d\n", wrapping);
        printf("Total ribbon length: %d\n", ribbon);;
    }
}