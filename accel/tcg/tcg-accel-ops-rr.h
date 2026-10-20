/*
 * QEMU TCG Single Threaded vCPUs implementation
 *
 * Copyright 2020 SUSE LLC
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef TCG_ACCEL_OPS_RR_H
#define TCG_ACCEL_OPS_RR_H

/*
 * A vCPU spinning on a lock keeps running until it is kicked, so the
 * period bounds how long a lock handoff to another vCPU can take. Keep
 * it well below typical guest timer tick periods, otherwise SMP guests
 * can livelock on contended spinlocks.
 */
#define TCG_KICK_PERIOD (NANOSECONDS_PER_SECOND / 1000)

/* Kick all RR vCPUs. */
void rr_kick_vcpu_thread(CPUState *unused);

/* start the round robin vcpu thread */
void rr_start_vcpu_thread(CPUState *cpu);

#endif /* TCG_ACCEL_OPS_RR_H */
