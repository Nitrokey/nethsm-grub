/* csl.h - Command Stream Loader (CSL) header */
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

#ifndef CSL_H
#define CSL_H

#include <grub/file.h>

struct csl_file_operations {
	grub_file_t (*open) (const char *name, enum grub_file_type type);
	grub_ssize_t (*read) (grub_file_t file, void *buf, grub_size_t len);
	grub_off_t (*size) (const grub_file_t file);
	grub_err_t (*close) (grub_file_t file);
};

extern struct csl_file_operations csl_fs_ops;

#endif /* CSL_H */
