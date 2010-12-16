/******************************************************************************
**
** This file is part of libcommhistory.
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Alexander Shalamov <alexander.shalamov@nokia.com>
**
** This library is free software; you can redistribute it and/or modify it
** under the terms of the GNU Lesser General Public License version 2.1 as
** published by the Free Software Foundation.
**
** This library is distributed in the hope that it will be useful, but
** WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
** or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
** License for more details.
**
** You should have received a copy of the GNU Lesser General Public License
** along with this library; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
**
******************************************************************************/

#ifndef COMMHISTORY_CALLEVENT_H
#define COMMHISTORY_CALLEVENT_H

#include "event.h"
#include "libcommhistoryexport.h"

namespace CommHistory
{

class LIBCOMMHISTORY_EXPORT CallEvent : public Event
{
public:
    enum CallType
    {
        UnknownCallType = 0,
        DialedCallType,
        MissedCallType,
        ReceivedCallType
    };
};

}

#endif /* CALLEVENT_H_ */
