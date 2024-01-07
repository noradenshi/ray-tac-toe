#include "grid.h"
#include "restart.h"
#include <raylib.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 400

int main() {
    SetTraceLogLevel(LOG_NONE);
    SetTargetFPS(60);

    InitWindow(WIDTH, HEIGHT, "ray-tac-toe");
    SetTraceLogLevel(LOG_DEBUG);
    TTC_InitGrid();

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        TTC_DrawGrid();
        if (TTC_IsWinner() || TTC_GetTurnCount() == 9)
            UI_DrawRestart();
        if (TTC_IsWinner()) {
            DrawText(TTC_GetWinner(), 600, 160, 150,
                     strcmp(TTC_GetWinner(), "X") == 0 ? PURPLE : YELLOW);
            DrawText("The winner is...", 550, 140, 20, WHITE);
        }

        EndDrawing();
    }
    return 0;
}
