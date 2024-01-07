#include "restart.h"
#include "grid.h"
#include <raylib.h>

#define POS_X 80
#define POS_Y 150
#define WIDTH 120
#define HEIGHT 50

void UI_DrawRestart() {
    bool isUnderMouse = false;
    if (GetMouseX() > POS_X && GetMouseX() < POS_X + WIDTH &&
        GetMouseY() > POS_Y && GetMouseY() < POS_Y + HEIGHT) {
        isUnderMouse = true;

        if (IsMouseButtonPressed(0)) {
            TTC_InitGrid();
        }
    }

    DrawRectangle(POS_X, POS_Y, WIDTH, HEIGHT,
                  isUnderMouse ? LIGHTGRAY : RAYWHITE);
    DrawText("restart", POS_X + 5, POS_Y + 10, 28, BLACK);
}
