#ifndef TUI_H
#define TUI_H

typedef struct {
  char *back_buffer;
  char *front_buffer;
  int cols;
  int rows;
} TUIData;

void tui_get_terminal_size(int *rows, int *cols);
void tui_clear_screen();
void tui_hide_cursor();
void tui_show_cursor();
void tui_draw_screen();

void tui_init();

extern TUIData *tui;

char *tui_create_buffer();
void tui_swap_buffer(char *buffer);
void tui_show_back_buffer();
void tui_free(TUIData *tui_ctx);
char *tui_buffer_at(char *buffer, int col, int row, int rows, int cols);
void tui_enable_alternate_buffer();
void tui_disable_alternate_buffer();
void tui_get_center_point(int *col, int *row);

void tui_enable_raw_mode();
void tui_disable_raw_mode();
#endif
