#pragma once
#include <stdbool.h>

void TTC_InitGrid();
int TTC_GetTurnCount();
bool TTC_IsWinner();
char *TTC_GetWinner();
void TTC_DrawGrid();
