/* Copyright (c) 2024 Bytedance Ltd. and/or its affiliates

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License, version 2.0,
  as published by the Free Software Foundation.

  This program is also distributed with certain software (including
  but not limited to OpenSSL) that is licensed under separate terms,
  as designated in a particular file or component or in included license
  documentation.  The authors of MySQL hereby grant you an additional
  permission to link the program and your derivative works with the
  separately licensed software that they have included with MySQL.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License, version 2.0, for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

/** @file videx_utils.h
 *
 * @brief
 * Provide util functions required by Videx storage engine, like a function to
 * serialize MariaDB key_range to JSON object.
 */


#ifndef VIDEX_UTILS
#define VIDEX_UTILS

#include <my_global.h>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <my_base.h>
#include <key.h>
#include <structs.h>
#include <field.h>
#include <table.h>
#include <mysqld.h>
#include "videx_json_item.h"

/**
  Serializes min/max key bounds for a given index into `req_json`.
  Also prints a concise human-readable summary for debugging.

  @param min_key Minimum key range.
  @param max_key Maximum key range.
  @param key Index key information.
  @param req_json JSON object to store serialized key range.
*/
void serializeKeyRangeToJson(const key_range *min_key,
                             const key_range *max_key, KEY *key,
                             VidexJsonItem *req_json);

#endif // VIDEX_UTILS