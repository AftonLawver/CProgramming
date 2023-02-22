#include <stdio.h>
typedef struct {
    int length;
    int width;
} rectangle;

typedef struct {
    int x;
    int y;
} position;

typedef struct {
    char owner[30];
    rectangle size;
    position location;
} buildingPlan;

int main() {
    rectangle myRectangle = {3,10};
    printf("Length:%d Width:%d\n", myRectangle.length, myRectangle.width);
    return 0;
}
