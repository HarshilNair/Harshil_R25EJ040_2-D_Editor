#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 30
#define COLS 60

char canvas[ROWS][COLS];

void clearCanvas() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}


void displayCanvas() {
    int i, j;

    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}


void drawPoint(int x, int y) {
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS)
        canvas[x][y] = '*';
}


void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (1) {
        drawPoint(x1, y1);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}


void drawRectangle(int x, int y, int h, int w) {
    int i;

    for (i = y; i < y + w; i++) {
        drawPoint(x, i);
        drawPoint(x + h - 1, i);
    }

    for (i = x; i < x + h; i++) {
        drawPoint(i, y);
        drawPoint(i, y + w - 1);
    }
}

void drawTriangle(int x1, int y1,
                  int x2, int y2,
                  int x3, int y3) {

    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x1, y1);
}


void drawCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    while (y >= x) {

        drawPoint(xc + x, yc + y);
        drawPoint(xc - x, yc + y);
        drawPoint(xc + x, yc - y);
        drawPoint(xc - x, yc - y);

        drawPoint(xc + y, yc + x);
        drawPoint(xc - y, yc + x);
        drawPoint(xc + y, yc - x);
        drawPoint(xc - y, yc - x);

        x++;

        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
}

void eraseArea(int x, int y, int h, int w) {
    int i, j;

    for (i = x; i < x + h && i < ROWS; i++) {
        for (j = y; j < y + w && j < COLS; j++) {
            canvas[i][j] = '_';
        }
    }
}


void modifyRectangle() {
    int oldx, oldy, oldh, oldw;
    int newx, newy, newh, neww;

    printf("Old Rectangle (x y h w): ");
    scanf("%d %d %d %d", &oldx, &oldy, &oldh, &oldw);

    eraseArea(oldx, oldy, oldh, oldw);

    printf("New Rectangle (x y h w): ");
    scanf("%d %d %d %d", &newx, &newy, &newh, &neww);

    drawRectangle(newx, newy, newh, neww);
}

int main() {

    int choice;

    clearCanvas();

    do {

        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Line\n");
        printf("2. Draw Rectangle\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Modify Rectangle\n");
        printf("7. Display Picture\n");
        printf("8. Clear Canvas\n");
        printf("0. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1: {
            int x1, y1, x2, y2;
            printf("x1 y1 x2 y2: ");
            scanf("%d %d %d %d",
                  &x1, &y1, &x2, &y2);
            drawLine(x1, y1, x2, y2);
            break;
        }

        case 2: {
            int x, y, h, w;
            printf("x y height width: ");
            scanf("%d %d %d %d",
                  &x, &y, &h, &w);
            drawRectangle(x, y, h, w);
            break;
        }

        case 3: {
            int x1, y1, x2, y2, x3, y3;
            printf("x1 y1 x2 y2 x3 y3: ");
            scanf("%d %d %d %d %d %d",
                  &x1, &y1,
                  &x2, &y2,
                  &x3, &y3);

            drawTriangle(x1, y1, x2, y2, x3, y3);
            break;
        }

        case 4: {
            int xc, yc, r;
            printf("centerX centerY radius: ");
            scanf("%d %d %d",
                  &xc, &yc, &r);
            drawCircle(xc, yc, r);
            break;
        }

        case 5: {
            int x, y, h, w;
            printf("x y height width: ");
            scanf("%d %d %d %d",
                  &x, &y, &h, &w);
            eraseArea(x, y, h, w);
            break;
        }

        case 6:
            modifyRectangle();
            break;

        case 7:
            displayCanvas();
            break;

        case 8:
            clearCanvas();
            printf("Canvas Cleared!\n");
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 0);

    return 0;
}