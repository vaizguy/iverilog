#ifndef IVL_array_H
#define IVL_array_H
/*
 * Copyright (c) 2007-2014 Stephen Williams (steve@icarus.com)
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "vvp_net.h"
#include "vpi_user.h"

typedef struct __vpiArray* vvp_array_t;
class value_callback;

/*
 * This function tries to find the array (by label) in the global
 * table of all the arrays in the design.
 */
extern vvp_array_t array_find(const char*label);
extern unsigned get_array_word_size(vvp_array_t array);
extern vpiHandle array_index_iterate(int code, vpiHandle ref);

extern void array_word_change(vvp_array_t array, unsigned long addr);

extern void array_attach_word(vvp_array_t array, unsigned addr, vpiHandle word);
extern void array_alias_word(vvp_array_t array, unsigned long addr,
                             vpiHandle word, int msb, int lsb);

extern void array_set_word(vvp_array_t arr, unsigned idx,
			    unsigned off, vvp_vector4_t val);
extern void array_set_word(vvp_array_t arr, unsigned idx,
			   double val);
extern void array_set_word(vvp_array_t arr, unsigned idx,
			   const std::string&val);
extern void array_set_word(vvp_array_t arr, unsigned idx,
			   const vvp_object_t&val);

extern vvp_vector4_t array_get_word(vvp_array_t array, unsigned address);
extern double array_get_word_r(vvp_array_t array, unsigned address);
extern void array_get_word_obj(vvp_array_t array, unsigned address, vvp_object_t&val);
extern std::string array_get_word_str(vvp_array_t array, unsigned address);

/* VPI hooks */

extern value_callback* vpip_array_word_change(p_cb_data data);
extern value_callback* vpip_array_change(p_cb_data data);

/* Compile hooks */
extern void compile_varw_real(char*label, vvp_array_t array,
			      unsigned long array_addr,
			      int msb, int lsb);
#endif /* IVL_array_H */
