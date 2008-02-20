/* The vmprg object.
 *
 * The program is made up of vmop_t's, one after another. When we support
 * branching (or user-defined functions) at some time, well do this via
 * special branch opcodes. They will then contain the actual memory
 * address of a logical program entry that we shall branch to. Other than
 * that, all execution is serial - that is one opcode is executed after
 * the other. This class implements a logical program store, modelled
 * after real main memory. A linked list of opcodes is used to implement it.
 * In the future, we may use linked lists of array's to enhance performance,
 * but for the time being we have taken the simplistic approach (which also
 * reduces risk of bugs during initial development). The necessary pointers
 * for this are already implemented in vmop. Though this is not the 100%
 * correct place, we have opted this time in favor of performance, which
 * made them go there.
 *
 * Copyright 2008 Rainer Gerhards and Adiscon GmbH.
 *
 * This file is part of rsyslog.
 *
 * Rsyslog is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Rsyslog is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Rsyslog.  If not, see <http://www.gnu.org/licenses/>.
 *
 * A copy of the GPL can be found in the file "COPYING" in this distribution.
 */
#ifndef INCLUDED_VMPRG_H
#define INCLUDED_VMPRG_H

#include "vmop.h"


/* the vmprg object */
typedef struct vmprg_s {
	BEGINobjInstance;	/* Data to implement generic object - MUST be the first data element! */
	vmop_t *vmopRoot;	/* start of program */
	vmop_t *vmopLast;	/* last vmop of program (for adding new ones) */
} vmprg_t;


/* prototypes */
rsRetVal vmprgConstruct(vmprg_t **ppThis);
rsRetVal vmprgConstructFinalize(vmprg_t __attribute__((unused)) *pThis);
rsRetVal vmprgDestruct(vmprg_t **ppThis);
rsRetVal addOperation(vmprg_t *pThis, vmop_t *pOp);
PROTOTYPEObjClassInit(vmprg);

#endif /* #ifndef INCLUDED_VMPRG_H */
