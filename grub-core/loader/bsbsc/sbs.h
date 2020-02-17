/* sbs.h - Signed Block Stream (SBS) header */
/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2020  codelabs GmbH
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SBS_H
#define SBS_H

#define SBS_VERMAGIC		0xe6019598
#define SHA512_HASHSUM_LEN	64
#define PGP_RSA4096_SIG_LEN	566

enum
{
	SBS_HASH_ALGO_NONE       = 0,
	SBS_HASH_ALGO_SHA1       = 1,
	SBS_HASH_ALGO_SHA2_256   = 2,
	SBS_HASH_ALGO_SHA2_384   = 3,
	SBS_HASH_ALGO_SHA2_512   = 4,
	SBS_HASH_ALGO_RIPEMD_160 = 5,
};

enum
{
	SBS_SIG_SCHEME_PGP = 1,
};

struct sbs_header_t
{
	grub_uint32_t version_magic;
	grub_uint32_t block_count;
	grub_uint32_t block_size;
	grub_uint32_t sig_len;
	grub_uint16_t header_size;
	grub_uint16_t hashsum_len;
	grub_uint16_t hash_algo_id_1;
	grub_uint16_t hash_algo_id_2;
	grub_uint16_t hash_algo_id_3;
	grub_uint16_t hash_algo_id_4;
	grub_uint16_t sig_scheme_id;
	grub_uint16_t reserved;
	grub_uint32_t padding_len;
	grub_uint8_t root_hash[SHA512_HASHSUM_LEN];
} __attribute__ ((packed));

#endif /* SBS_H */
