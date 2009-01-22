/***********************************************************************
** KPSFileFinder.h                                                    **
**                                                                    **
** This file is part of dvisvgm -- the DVI to SVG converter           **
** Copyright (C) 2005-2007 Martin Gieseking <martin.gieseking@uos.de> **
**                                                                    **
** This program is free software; you can redistribute it and/or      **
** modify it under the terms of the GNU General Public License        **
** as published by the Free Software Foundation; either version 2     **
** of the License, or (at your option) any later version.             **
**                                                                    **
** This program is distributed in the hope that it will be useful,    **
** but WITHOUT ANY WARRANTY; without even the implied warranty of     **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      **
** GNU General Public License for more details.                       **
**                                                                    **
** You should have received a copy of the GNU General Public License  **
** along with this program; if not, write to the Free Software        **
** Foundation, Inc., 51 Franklin Street, Fifth Floor,                 **
** Boston, MA 02110-1301, USA.                                        **
***********************************************************************/
// $Id$

#ifndef KPSFILEFINDER_H
#define KPSFILEFINDER_H

#include <string>
#include "FontMap.h"

class KPSFileFinder
{
   public:
		static const char* lookup (const std::string &fname, bool extended=true);
		static const char* lookupEncFile (std::string fontname);
		static const char* lookupEncName (std::string fname);
		static const char *progname;
		static const char *usermap;
		static bool mktexEnabled;
	
		///@todo make protected
		static void initialize ();
		static void finalize ();

	private:
		static bool initialized;
		static FontMap fontmap;
};

#endif
