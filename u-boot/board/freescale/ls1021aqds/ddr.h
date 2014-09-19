/*
 * Copyright 2014 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __DDR_H__
#define __DDR_H__
struct board_specific_parameters {
	u32 n_ranks;
	u32 datarate_mhz_high;
	u32 rank_gb;
	u32 clk_adjust;
	u32 wrlvl_start;
	u32 wrlvl_ctl_2;
	u32 wrlvl_ctl_3;
	u32 cpo_override;
	u32 write_data_delay;
	u32 force_2t;
};

/*
 * These tables contain all valid speeds we want to override with board
 * specific parameters. datarate_mhz_high values need to be in ascending order
 * for each n_ranks group.
 */
static const struct board_specific_parameters udimm0[] = {
	/*
	 * memory controller 0
	 *   num|  hi| rank|  clk| wrlvl |   wrlvl   |  wrlvl | cpo  |wrdata|2T
	 * ranks| mhz| GB  |adjst| start |   ctl2    |  ctl3  |      |delay |
	 */
	{1,  833,  1, 6,     8, 0x06060607, 0x08080807,   0x1f,    2,  0},
	{1,  1350, 1, 6,     8, 0x0708080A, 0x0A0B0C09,   0x1f,    2,  0},
	{1,  833,  2, 6,     8, 0x06060607, 0x08080807,   0x1f,    2,  0},
	{1,  1350, 2, 6,     8, 0x0708080A, 0x0A0B0C09,   0x1f,    2,  0},
	{2,  833,  4, 6,     8, 0x06060607, 0x08080807,   0x1f,    2,  0},
	{2,  1350, 4, 6,     8, 0x0708080A, 0x0A0B0C09,   0x1f,    2,  0},
	{2,  1350, 0, 6,     8, 0x0708080A, 0x0A0B0C09,   0x1f,    2,  0},
	{2,  1666, 4, 4,   0xa, 0x0B08090C, 0x0B0E0D0A,   0x1f,    2,  0},
	{2,  1666, 0, 4,   0xa, 0x0B08090C, 0x0B0E0D0A,   0x1f,    2,  0},
	{}
};

static const struct board_specific_parameters *udimms[] = {
	udimm0,
};

#endif
