/*
 * Stack implementation
 *
 * Author: Arun Prakash Jana <engineerarun@gmail.com>
 * Copyright (C) 2015 by Arun Prakash Jana <engineerarun@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dslib.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "stack.h"

stack_p get_stack()
{
	stack_p stack = calloc(1, sizeof(stack_t));

	stack->head = calloc(1, sizeof(dlist_pp));
	return stack;
}

bool push(stack_p stack, void *val)
{
	dlist_p nodeptr = calloc(1, sizeof(dlist_t));

	nodeptr->data = val;

	if (add_head_dlist(stack->head, nodeptr))
		return TRUE;
	else
		return FALSE;
}

void *pop(stack_p stack)
{
	void *data = get_head_dlist(stack->head);

	if (delete_head_dlist(stack->head) == -1)
		log(DEBUG, "head or first node is NULL!\n");

	return data;
}

bool destroy_stack(stack_p stack)
{
	if (destroy_dlist(stack->head) == -1)
		return FALSE;

	free(stack->head);
	free(stack);

	return TRUE;
}
