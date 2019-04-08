//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-27.
//

#include <stdlib.h>
#include <memory.h>

int projectionArea(int** grid, int gridRowSize, int gridColSize) {
    int area = 0;

    int *temp = malloc(sizeof(int) * (gridRowSize + gridColSize));
    memset(temp, 0, sizeof(int) * (gridRowSize + gridColSize));
    int *xzProject = temp;
    int *yzProject = temp + gridRowSize;

    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (grid[i][j] == 0)
                continue;

            // add xy project
            area += 1;

            // add xz project
            if (xzProject[i] < grid[i][j])
                xzProject[i] = grid[i][j];

            // add yzProject
            if (yzProject[j] < grid[i][j])
                yzProject[j] = grid[i][j];
        }
    }

    for (int i = 0; i < gridRowSize; i++) {
        area += xzProject[i];
    }

    for (int i = 0; i < gridColSize; i++) {
        area += yzProject[i];
    }

    return area;
}

int main() {
    int a[] = {1, 0, 0, 2};
    int *b[] = {a, a + 2};
    projectionArea(b, 2, 2);
}