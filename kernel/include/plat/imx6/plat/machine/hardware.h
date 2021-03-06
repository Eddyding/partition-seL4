/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * This software may be distributed and modified according to the terms of
 * the GNU General Public License version 2. Note that NO WARRANTY is provided.
 * See "LICENSE_GPLv2.txt" for details.
 *
 * @TAG(GD_GPL)
 */

#ifndef __PLAT_MACHINE_HARDWARE_H
#define __PLAT_MACHINE_HARDWARE_H

#define physBase          0x10000000
#define PADDR_BASE        physBase /* for compatibility with proofs */
#define kernelBase        0xe0000000
#define physMappingOffset (kernelBase - physBase)
#define BASE_OFFSET       physMappingOffset

/*
 * 0xffe00000 asid id slot (arm/arch/kernel/vspace.h)
 * 0xfff00000 devices      (plat/machine/devices.h)
 * 0xffff0000 vectors      (arch/machine/hardware.h)
 * 0xffffc000 global page  (arch/machine/hardware.h)
 * 0xfffff000 kernel stack (arch/machine/hardware.h)
 */

#define PPTR_TOP          0xfff00000
#define PADDR_TOP         (PPTR_TOP - BASE_OFFSET)


#ifndef __ASSEMBLER__

#include <types.h>
#include <arch/object/structures.h>
#include <plat/machine.h>
#include <plat/machine/hardware_gen.h>

#include <arch/machine/gic_pl390.h>
#include <arch/machine/l2c_310.h>
#include <arch/machine/priv_timer.h>

static inline void * CONST
ptrFromPAddr(paddr_t paddr)
{
    return (void*)(paddr + physMappingOffset);
}

static inline paddr_t CONST
addrFromPPtr(void *pptr)
{
    return (paddr_t)pptr - physMappingOffset;
}


int get_num_avail_p_regs(void);
p_region_t get_avail_p_reg(unsigned int i);
int get_num_dev_p_regs(void);
p_region_t get_dev_p_reg(unsigned int i);
void map_kernel_devices(void);

bool_t CONST isReservedIRQ(irq_t irq);
void handleReservedIRQ(irq_t irq);


#endif /* !__ASSEMBLER__ */

#endif /* !__PLAT_MACHINE_HARDWARE_H */
