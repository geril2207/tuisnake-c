#include "state.h"
#include "log.h"
#include "tui.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SomeState *state;

static void state_update_from_tui() {
  if (state == NULL || tui == NULL)
    return;

  state->cols = tui->cols;
  state->rows = tui->rows;
}

void state_update_tui_back_buffer() {
  if (tui == NULL || state == NULL)
    return;
  char *rows_msg = "Rows: ";
  char *cols_msg = "Cols: ";
  char cols_result[12];
  char rows_result[12];
  sprintf(rows_result, "%s%d", rows_msg, tui->rows);
  sprintf(cols_result, "%s%d", cols_msg, tui->cols);
  log_message("f: %s", rows_result);
  log_message("s: %s", cols_result);

  char *buf = tui_create_buffer();
  if (buf == NULL)
    return;

  char res[12];
  int rand_val = rand();
  sprintf(res, "%d", rand_val);
  for (int i = 0; res[i] != '\0'; i++) {
    buf[i] = res[i];
  }

  tui->back_buffer = buf;

  tui_show_back_buffer();
}

void state_update_on_resize() {
  state_update_from_tui();
  state_update_tui_back_buffer();
}

void state_init() {
  state = malloc(sizeof(SomeState));
  state_update_from_tui();
  state_update_tui_back_buffer();
}
