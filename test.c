#include <stdio.h>
#include <stdlib.h>

int main () {
    int x = 20, *y;
    y = &x;
    *y++;
    x++;
    printf("%d %d",x,y);
}