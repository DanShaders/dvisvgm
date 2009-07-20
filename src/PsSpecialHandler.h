/***********************************************************************
** PsSpecialHandler.h                                                 **
**                                                                    **
** This file is part of dvisvgm -- the DVI to SVG converter           **
** Copyright (C) 2005-2009 Martin Gieseking <martin.gieseking@uos.de> **
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

#ifndef PSSPECIALHANDLER_H
#define PSSPECIALHANDLER_H

#include <stack>
#include <vector>
#include "GraphicPath.h"
#include "PSInterpreter.h"
#include "SpecialHandler.h"

class XMLElementNode;

class PsSpecialHandler : public SpecialHandler, protected PSActions
{
	public:
		PsSpecialHandler ();
		const char* name () const   {return "ps";}
		const char* info () const   {return "dvips PostScript specials";}
		int prefixes (const char **p[]) const;
		bool process (const char *prefix, std::istream &is, SpecialActions *actions);

	protected:	
		void initialize ();
		void psfile (const std::string &fname, const std::map<std::string,std::string> &attr);

		void clip (std::vector<double> &p)           {clip(p, false);}
		void clip (std::vector<double> &p, bool evenodd);
		void closepath (std::vector<double> &p);
		void curveto (std::vector<double> &p);
		void eoclip (std::vector<double> &p)         {clip(p, true);}
		void eofill (std::vector<double> &p)         {fill(p, true);}
		void fill (std::vector<double> &p)           {fill(p, false);}
		void fill (std::vector<double> &p, bool evenodd);
		void gsave (std::vector<double> &p);
		void grestore (std::vector<double> &p);
		void initclip (std::vector<double> &p);
		void lineto (std::vector<double> &p);
		void moveto (std::vector<double> &p);
		void newpath (std::vector<double> &p);
		void rotate (std::vector<double> &p);
		void scale (std::vector<double> &p);
		void setcmykcolor (std::vector<double> &cmyk);
		void setdash (std::vector<double> &p);
		void setgray (std::vector<double> &p);
		void sethsbcolor (std::vector<double> &hsb);
		void setlinecap (std::vector<double> &p)     {_linecap = p[0];}
		void setlinejoin (std::vector<double> &p)    {_linejoin = p[0];}
		void setlinewidth (std::vector<double> &p)   {_linewidth = p[0] ? p[0]*1.00375 : 0.1;}
		void setmatrix (std::vector<double> &p);
		void setmiterlimit (std::vector<double> &p)  {_miterlimit = p[0]*1.00375;}
		void setrgbcolor (std::vector<double> &rgb);
		void stroke (std::vector<double> &p);
		void translate (std::vector<double> &p);

   private:
		PSInterpreter _psi;
		SpecialActions *_actions;
		bool _initialized;
		XMLElementNode *_xmlnode;   ///< if != 0, created SVG elements are appended to this node
		GraphicPath<double> _path;
		float _linewidth;           ///< current linewidth
		float _miterlimit;          ///< current miter limit
		unsigned _linecap  : 2;     ///< current line cap (0=butt, 1=round, 2=projecting square)
		unsigned _linejoin : 2;     ///< current line join (0=miter, 1=round, 2=bevel)
		int _dashoffset;            ///< current dash offset
		int _numClips;              ///< number of clipping paths
		std::stack<int> _clipStack;
		std::vector<int> _dashpattern;
};

#endif