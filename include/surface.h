#pragma once

#include "tui.h"
typedef struct {
  int width;
  int height;
  int start_col;
  int start_row;
} Surface;

extern Surface *surface;

void surface_render(TUIGrid *grid);
void surface_calculate_size(int *start_row, int *start_col);
void surface_recalculate();
void surface_init();
void surface_cleanup();
