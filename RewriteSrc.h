/*
*   Copyright (C) 2017 by Jonathan Naylor G4KLX
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software
*   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#if !defined(REWRITESRC_H)
#define	REWRITESRC_H

#include "DMREmbeddedData.h"
#include "DMRDataHeader.h"
#include "DMRCSBK.h"
#include "Rewrite.h"
#include "DMRData.h"
#include "DMRLC.h"

#include <string>

class CRewriteSrc : public IRewrite {
public:
	CRewriteSrc(const std::string& name, unsigned int fromSlot, unsigned int fromId, unsigned int toSlot, unsigned int toTG, unsigned int range);
	virtual ~CRewriteSrc();

	virtual bool process(CDMRData& data, bool trace);

private:
	std::string      m_name;
	unsigned int     m_fromSlot;
	unsigned int     m_fromIdStart;
	unsigned int     m_fromIdEnd;
	unsigned int     m_toSlot;
	unsigned int     m_toTG;
	CDMRLC           m_lc;
	CDMREmbeddedData m_embeddedLC;
	CDMRDataHeader   m_dataHeader;
	CDMRCSBK         m_csbk;

	void processHeader(CDMRData& data, unsigned char dataType);
	void processVoice(CDMRData& data);
	void processDataHeader(CDMRData& data);
	void processCSBK(CDMRData& data);
};


#endif
