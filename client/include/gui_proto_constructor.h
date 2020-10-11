/**********************************************************************
 Freeciv - Copyright (C) 1996 - A Kjeldberg, L Gregersen, P Unold
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
***********************************************************************/

#ifndef FC__GUI_PROTO_CONSTRUCTOR_H
#define FC__GUI_PROTO_CONSTRUCTOR_H

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

#ifdef GUI_CB_MODE
#define GUI_FUNC_PROTO(_type, _func, ...)                                   \
  EXTERN_C _type gui_##_func(__VA_ARGS__);                                  \
  EXTERN_C _type _func(__VA_ARGS__);
#else
#define GUI_FUNC_PROTO(_type, _func, ...) EXTERN_C _type _func(__VA_ARGS__);
#endif

#endif /* FC__GUI_PROTO_CONSTRUCTOR_H */
