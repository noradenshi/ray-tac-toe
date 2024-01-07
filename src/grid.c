#include "grid.h"
#include <memory.h>
#include <raylib.h>

#define OFFSET_X 250
#define OFFSET_Y 100
#define SIZE 80
#define SEPARATION 85

char boxes[9];
bool isP1Turn;
int turnCount;
bool isWinner;
char winner[2] = "_";

void TTC_InitGrid() {
    memcpy(boxes, (char[9]){0}, 9);
    isP1Turn = true;
    turnCount = 0;
    isWinner = false;
}

int TTC_GetTurnCount() { return turnCount; }
bool TTC_IsWinner() { return isWinner; }
char *TTC_GetWinner() { return winner; }

void UpdateWinnerState(int box_id) {
    if (isWinner)
        return;

    const int col = box_id % 3;
    const int row = box_id - col;
    if (boxes[row] == boxes[row + 1] && boxes[row] == boxes[row + 2]) {
        isWinner = true;
        winner[0] = boxes[row];
        return;
    }
    if (boxes[col] == boxes[col + 3] && boxes[col] == boxes[col + 6]) {
        isWinner = true;
        winner[0] = boxes[col];
        return;
    }

    if ((box_id & 1) == 1 || boxes[4] == 0)
        return;

    if (boxes[0] == boxes[4] && boxes[0] == boxes[8]) {
        isWinner = true;
        winner[0] = boxes[4];
        return;
    }
    if (boxes[2] == boxes[4] && boxes[2] == boxes[6]) {
        isWinner = true;
        winner[0] = boxes[4];
        return;
    }
}

void TTC_DrawGrid() {
    char str[2] = "_";
    for (int i = 0, row = 0; i < 9; i++) {
        str[0] = boxes[i];

        const int posX = OFFSET_X + (i % 3) * SEPARATION;
        const int posY = OFFSET_Y + row * SEPARATION;
        bool isUnderMouse = false;

        if (GetMouseX() > posX && GetMouseX() < posX + SIZE &&
            GetMouseY() > posY && GetMouseY() < posY + SIZE) {
            isUnderMouse = true;

            if (boxes[i] == 0 && IsMouseButtonPressed(0)) {
                turnCount++;
                boxes[i] = isP1Turn ? 'X' : 'O';
                UpdateWinnerState(i);
                isP1Turn = !isP1Turn;
            }
        }
        DrawRectangleLines(posX, posY, SIZE, SIZE,
                           isUnderMouse ? GREEN : LIGHTGRAY);
        DrawText(str, posX + SIZE / 5, posY + SIZE / 15, SIZE,
                 (boxes[i] == 'X' ? PURPLE : YELLOW));
        if ((i + 1) % 3 == 0)
            row++;
    }
}
