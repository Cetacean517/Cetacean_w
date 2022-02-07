#include <stdio.h>
#include <windows.h>
#include <windows.h>

int main() {
    system("color 0c");
    float x, y, a, z;
    for (y = 1.5; y > -1.5; y -= 0.1214)
    {
        for (x = -1.5; x < 1.5; x += 0.05)
        {
            a = x * x + y * y - 1;
            putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
            Sleep(1);
        }
        putchar('\n');
    }
    printf("             You are my once upon a time. LUV YAH!! \n");
    for (int i = 0; i < 3; i++) {
        printf("\n");
    }
    system("pause");
    return 0;
}