/*
** keys.c for Tekdoom in /gfx_tekdoom/src/server/graphic_client/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Jan 18 08:33:36 2016 Antoine Baché
** Last update Mon Jan 25 07:48:19 2016 Antoine Baché
*/

#include "tekdoom.h"

mousetab	get_keys1(void)
{
  mousetab	array;

  if ((array = malloc(sizeof(int *) * KEY_BUTTONS)) == NULL)
    return (NULL);
  array[BKS_A] = &type_a;
  array[BKS_B] = &type_b;
  array[BKS_C] = &type_c;
  array[BKS_D] = &type_d;
  array[BKS_E] = &type_e;
  array[BKS_F] = &type_f;
  array[BKS_G] = &type_g;
  array[BKS_H] = &type_h;
  array[BKS_I] = &type_i;
  array[BKS_J] = &type_j;
  array[BKS_K] = &type_k;
  array[BKS_L] = &type_l;
  array[BKS_M] = &type_m;
  array[BKS_N] = &type_n;
  array[BKS_O] = &type_o;
  array[BKS_P] = &type_p;
  array[BKS_Q] = &type_q;
  array[BKS_R] = &type_r;
  array[BKS_S] = &type_s;
  array[BKS_T] = &type_t;
  return (array);
}

void	get_keys2(mousetab array)
{
  array[BKS_U] = &type_u;
  array[BKS_V] = &type_v;
  array[BKS_W] = &type_w;
  array[BKS_X] = &type_x;
  array[BKS_Y] = &type_y;
  array[BKS_Z] = &type_z;
  array[BKS_0] = &type_0;
  array[BKS_1] = &type_1;
  array[BKS_2] = &type_2;
  array[BKS_3] = &type_3;
  array[BKS_4] = &type_4;
  array[BKS_5] = &type_5;
  array[BKS_6] = &type_6;
  array[BKS_7] = &type_7;
  array[BKS_8] = &type_8;
  array[BKS_9] = &type_9;
  array[BKS_LCONTROL] = &do_nothing;
  array[BKS_LSHIFT] = &do_nothing;
  array[BKS_LALT] = &do_nothing;
  array[BKS_LSYSTEM] = &do_nothing;
  get_keys3(array);
  get_keys4(array);
  get_keys5(array);
}

void	get_keys3(mousetab array)
{
  array[BKS_RCONTROL] = &do_nothing;
  array[BKS_RSHIFT] = &do_nothing;
  array[BKS_RALT] = &do_nothing;
  array[BKS_RSYSTEM] = &do_nothing;
  array[BKS_MENU] = &do_nothing;
  array[BKS_LBRACKET] = &type_brackets_open;
  array[BKS_RBRACKET] = &type_brackets_close;
  array[BKS_SEMICOLON] = &type_semicolon;
  array[BKS_COMMA] = &type_comma;
  array[BKS_PERIOD] = &type_dot;
  array[BKS_QUOTE] = &type_quote;
  array[BKS_SLASH] = &type_slash;
  array[BKS_BACKSLASH] = &type_backslash;
  array[BKS_TILDE] = &do_nothing;
  array[BKS_EQUAL] = &type_equal;
  array[BKS_DASH] = &type_dash;
  array[BKS_SPACE] = &type_space;
  array[BKS_RETURN] = &type_enter;
  array[BKS_BACKSPACE] = &type_backspace;
  array[BKS_TAB] = &do_nothing;
}

void	get_keys4(mousetab array)
{
  array[BKS_PAGEUP] = &do_nothing;
  array[BKS_PAGEDOWN] = &do_nothing;
  array[BKS_END] = &do_nothing;
  array[BKS_HOME] = &do_nothing;
  array[BKS_INSERT] = &do_nothing;
  array[BKS_DELETE] = &do_nothing;
  array[BKS_ADD] = &type_add;
  array[BKS_SUBTRACT] = &do_nothing;
  array[BKS_MULTIPLY] = &type_multiply;
  array[BKS_DIVIDE] = &do_nothing;
  array[BKS_LEFT] = &do_nothing;
  array[BKS_RIGHT] = &do_nothing;
  array[BKS_UP] = &do_nothing;
  array[BKS_DOWN] = &do_nothing;
  array[BKS_NUMPAD0] = &type_0;
  array[BKS_NUMPAD1] = &type_1;
  array[BKS_NUMPAD2] = &type_2;
  array[BKS_NUMPAD3] = &type_3;
  array[BKS_NUMPAD4] = &type_4;
  array[BKS_NUMPAD5] = &type_5;
}

void	get_keys5(mousetab array)
{
  array[BKS_NUMPAD6] = &type_6;
  array[BKS_NUMPAD7] = &type_7;
  array[BKS_NUMPAD8] = &type_8;
  array[BKS_NUMPAD9] = &type_9;
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
