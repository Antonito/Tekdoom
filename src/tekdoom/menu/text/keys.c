/*
** keys.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 18 08:33:36 2016 Antoine Baché
** Last update Mon Jan 25 07:49:03 2016 Antoine Baché
*/

#include "tekdoom.h"

mousetab	menu_get_keys1(void)
{
  mousetab	array;

  if ((array = malloc(sizeof(int *) * KEY_BUTTONS)) == NULL)
    return (NULL);
  array[BKS_A] = &menu_type_a;
  array[BKS_B] = &menu_type_b;
  array[BKS_C] = &menu_type_c;
  array[BKS_D] = &menu_type_d;
  array[BKS_E] = &menu_type_e;
  array[BKS_F] = &menu_type_f;
  array[BKS_G] = &menu_type_g;
  array[BKS_H] = &menu_type_h;
  array[BKS_I] = &menu_type_i;
  array[BKS_J] = &menu_type_j;
  array[BKS_K] = &menu_type_k;
  array[BKS_L] = &menu_type_l;
  array[BKS_M] = &menu_type_m;
  array[BKS_N] = &menu_type_n;
  array[BKS_O] = &menu_type_o;
  array[BKS_P] = &menu_type_p;
  array[BKS_Q] = &menu_type_q;
  array[BKS_R] = &menu_type_r;
  array[BKS_S] = &menu_type_s;
  array[BKS_T] = &menu_type_t;
  return (array);
}

void	menu_get_keys2(mousetab array)
{
  array[BKS_U] = &menu_type_u;
  array[BKS_V] = &menu_type_v;
  array[BKS_W] = &menu_type_w;
  array[BKS_X] = &menu_type_x;
  array[BKS_Y] = &menu_type_y;
  array[BKS_Z] = &menu_type_z;
  array[BKS_0] = &menu_type_0;
  array[BKS_1] = &menu_type_1;
  array[BKS_2] = &menu_type_2;
  array[BKS_3] = &menu_type_3;
  array[BKS_4] = &menu_type_4;
  array[BKS_5] = &menu_type_5;
  array[BKS_6] = &menu_type_6;
  array[BKS_7] = &menu_type_7;
  array[BKS_8] = &menu_type_8;
  array[BKS_9] = &menu_type_9;
  array[BKS_LCONTROL] = &do_nothing;
  array[BKS_LSHIFT] = &do_nothing;
  array[BKS_LALT] = &do_nothing;
  array[BKS_LSYSTEM] = &do_nothing;
  menu_get_keys3(array);
  menu_get_keys4(array);
  menu_get_keys5(array);
}

void	menu_get_keys3(mousetab array)
{
  array[BKS_RCONTROL] = &do_nothing;
  array[BKS_RSHIFT] = &do_nothing;
  array[BKS_RALT] = &do_nothing;
  array[BKS_RSYSTEM] = &do_nothing;
  array[BKS_MENU] = &do_nothing;
  array[BKS_LBRACKET] = &menu_type_brackets_open;
  array[BKS_RBRACKET] = &menu_type_brackets_close;
  array[BKS_SEMICOLON] = &menu_type_semicolon;
  array[BKS_COMMA] = &menu_type_comma;
  array[BKS_PERIOD] = &menu_type_dot;
  array[BKS_QUOTE] = &menu_type_quote;
  array[BKS_SLASH] = &menu_type_slash;
  array[BKS_BACKSLASH] = &menu_type_backslash;
  array[BKS_TILDE] = &do_nothing;
  array[BKS_EQUAL] = &menu_type_equal;
  array[BKS_DASH] = &menu_type_dash;
  array[BKS_SPACE] = &do_nothing;
  array[BKS_RETURN] = &menu_type_enter;
  array[BKS_BACKSPACE] = &menu_type_backspace;
  array[BKS_TAB] = &do_nothing;
}

void	menu_get_keys4(mousetab array)
{
  array[BKS_PAGEUP] = &do_nothing;
  array[BKS_PAGEDOWN] = &do_nothing;
  array[BKS_END] = &do_nothing;
  array[BKS_HOME] = &do_nothing;
  array[BKS_INSERT] = &do_nothing;
  array[BKS_DELETE] = &do_nothing;
  array[BKS_ADD] = &menu_type_add;
  array[BKS_SUBTRACT] = &do_nothing;
  array[BKS_MULTIPLY] = &menu_type_multiply;
  array[BKS_DIVIDE] = &do_nothing;
  array[BKS_LEFT] = &do_nothing;
  array[BKS_RIGHT] = &do_nothing;
  array[BKS_UP] = &do_nothing;
  array[BKS_DOWN] = &do_nothing;
  array[BKS_NUMPAD0] = &menu_type_0;
  array[BKS_NUMPAD1] = &menu_type_1;
  array[BKS_NUMPAD2] = &menu_type_2;
  array[BKS_NUMPAD3] = &menu_type_3;
  array[BKS_NUMPAD4] = &menu_type_4;
  array[BKS_NUMPAD5] = &menu_type_5;
}

void	menu_get_keys5(mousetab array)
{
  array[BKS_NUMPAD6] = &menu_type_6;
  array[BKS_NUMPAD7] = &menu_type_7;
  array[BKS_NUMPAD8] = &menu_type_8;
  array[BKS_NUMPAD9] = &menu_type_9;
  array[BKS_F1] = &do_nothing;
  array[BKS_F2] = &do_nothing;
  array[BKS_F3] = &do_nothing;
  array[BKS_F4] = &do_nothing;
  array[BKS_F5] = &do_nothing;
  array[BKS_F6] = &do_nothing;
  array[BKS_F7] = &do_nothing;
  array[BKS_F8] = &do_nothing;
  array[BKS_F9] = &do_nothing;
  array[BKS_F10] = &do_nothing;
  array[BKS_F11] = &do_nothing;
  array[BKS_F12] = &do_nothing;
  array[BKS_F13] = &do_nothing;
  array[BKS_F14] = &do_nothing;
  array[BKS_F15] = &do_nothing;
  array[BKS_PAUSE] = &do_nothing;
}
