#include "state.h"
#include "tui.h"
#include <stdio.h>
#include <stdlib.h>

void events_handle_exit() {
  tui_show_cursor();
  tui_disable_raw_mode();
  fflush(stdout);
  exit(0);
}

void events_handle_resize() {
  if (tui == NULL)
    return;

  tui_get_terminal_size(&tui->rows, &tui->cols);
  state_update_on_resize();
}
