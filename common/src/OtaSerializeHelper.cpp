/*
 * OtaSerializeHelper.cpp
 *
 *  Created on: 2013-6-26
 *      Author: caiqingfeng
 */

#include "OtaSerializeHelper.h"
#include <boost/foreach.hpp>
#include "common/src/my_log.h"

#ifdef BIT32
typedef unsigned int LY_ULONG;
#elif BIT64
typedef unsigned long LY_ULONG;
#endif

void HexDump (char* out, const char* in, int size)
{
    for (int index = 0; index < size; index++)
    {
        sprintf (&out[index * 2], "%02x", (unsigned char)in[index]);
    }
}

void ByteDump (char* out, const char* in, int size)
{
    for (int index = 0; index < size; index++)
    {
        const char* cinter = &in[index * 2];
        int iinter;
        sscanf (cinter, "%02x", &iinter);
        out[index] = (char)iinter;
    }
}

OtaSerializeHelper::OtaSerializeHelper()
{

}

OtaSerializeHelper::~OtaSerializeHelper()
{

}

LYTimer OtaSerializeHelper::ota2timer(LYTimerMsg &tmsg)
{
    LYTimer timer;
    if (tmsg.has_server_timer_id())
    {
        timer.set_server_timer_id(tmsg.server_timer_id());
    }
    if (tmsg.has_action())
    {
        timer.set_action(tmsg.action());
    }
    if (tmsg.has_client_timer_id())
    {
        timer.set_client_timer_id(tmsg.client_timer_id());
    }
    if (tmsg.has_second_client_timer_id())
    {
        timer.set_second_client_timer_id(tmsg.second_client_timer_id());
    }
    if (tmsg.has_client_reserved1())
    {
        timer.set_client_reserved1(tmsg.client_reserved1());
    }
    if (tmsg.has_client_reserved2())
    {
        timer.set_client_reserved2(tmsg.client_reserved2());
    }
    if (tmsg.has_client_reserved3())
    {
        timer.set_client_reserved3(tmsg.client_reserved3());
    }
    if (tmsg.has_client_reserved4())
    {
        timer.set_client_reserved4(tmsg.client_reserved4());
    }
    if (tmsg.has_client_reserved5())
    {
        timer.set_client_reserved5(tmsg.client_reserved5());
    }

    return timer;
}

void OtaSerializeHelper::timer2ota(LYTimer timer, LYTimerMsg *tmsg)
{

}



