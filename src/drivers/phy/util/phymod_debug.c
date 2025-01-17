/*
 * $Id: phymod_debug.h,v 1.1.2.4 2013/07/11 08:38:24 dayad Exp $
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom/Broadcom-Compute-Connectivity-Software-robo2-rsdk/master/Legal/LICENSE file.
 *
 * $Copyright: (c) 2020 Broadcom Inc.
 * All Rights Reserved$
 */

#include <phymod/phymod_debug.h>

/*
 * Global variables to control verbose debug output.
 * Please see PHYMOD_VDBG macro in phymod_debug.h for usage.
 */
uint32_t phymod_dbg_mask;
uint32_t phymod_dbg_addr;
uint32_t phymod_dbg_lane;

int
phymod_debug_check(uint32_t flags, const phymod_access_t *pa)
{
    if ((flags & phymod_dbg_mask) == 0) {
        return 0;
    }
    if (pa == NULL) {
        return 1;
    }
    if ((pa->addr == phymod_dbg_addr)||(phymod_dbg_addr==0)) {
        if((phymod_dbg_lane==0) ||
           /* lane_mask is not set in core_access read & write */
           (pa->lane_mask==0) ||
           (pa->lane_mask & phymod_dbg_lane) != 0) {
            return 1;
        }
    }
    return 0;
}
