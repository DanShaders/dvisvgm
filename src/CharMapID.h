/*************************************************************************
** CharMapID.h                                                          **
**                                                                      **
** This file is part of dvisvgm -- the DVI to SVG converter             **
** Copyright (C) 2005-2013 Martin Gieseking <martin.gieseking@uos.de>   **
**                                                                      **
** This program is free software; you can redistribute it and/or        **
** modify it under the terms of the GNU General Public License as       **
** published by the Free Software Foundation; either version 3 of       **
** the License, or (at your option) any later version.                  **
**                                                                      **
** This program is distributed in the hope that it will be useful, but  **
** WITHOUT ANY WARRANTY; without even the implied warranty of           **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the         **
** GNU General Public License for more details.                         **
**                                                                      **
** You should have received a copy of the GNU General Public License    **
** along with this program; if not, see <http://www.gnu.org/licenses/>. **
*************************************************************************/

#ifndef CHARMAPID_H
#define CHARMAPID_H

#include "types.h"

/** Represents a character map of a font. */
struct CharMapID {
	CharMapID () : platform_id(0), encoding_id(0) {}
	CharMapID (UInt8 plf_id, UInt8 enc_id) : platform_id(plf_id), encoding_id(enc_id) {}

	bool operator == (const CharMapID &ids) const {
		return platform_id == ids.platform_id && encoding_id == ids.encoding_id;
	}

	bool operator != (const CharMapID &ids) const {
		return platform_id != ids.platform_id || encoding_id != ids.encoding_id;
	}

	bool valid () const {return platform_id != 0 && encoding_id != 0;}

	static const CharMapID WIN_SYMBOL;
	static const CharMapID WIN_UCS2;
	static const CharMapID WIN_SHIFTJIS;
	static const CharMapID WIN_PRC;
	static const CharMapID WIN_BIG5;
	static const CharMapID WIN_WANSUNG;
	static const CharMapID WIN_JOHAB;
	static const CharMapID WIN_UCS4;
	static const CharMapID MAC_JAPANESE;
	static const CharMapID MAC_TRADCHINESE;
	static const CharMapID MAC_SIMPLCHINESE;
	static const CharMapID MAC_KOREAN;

	UInt8 platform_id;
	UInt8 encoding_id;
};

#endif