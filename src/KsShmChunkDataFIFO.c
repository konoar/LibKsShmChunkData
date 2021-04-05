/***********************************************

  KsShmChunkDataFIFO.c
    copyright 2021.04.04 konoar

 ***********************************************/

#include "KsDefine.h"
#include "KsShmChunkDataFIFO.h"

#define KS_IS_FULL( _SZ_, _SP_, _EP_ ) \
    (*_SP_ == 0) ? *_EP_ == (_SZ_ - 1) : *_EP_ == (*_SP_ - 1) 

int ksShmChunkDataFIFOInit(
    ksChkIDPtr  list,
    ksChkSize   size,
    ksChkIDPtr  start,
    ksChkIDPtr  end)
{
    *start  = 0;
    *end    = size - 1;

    *list = KS_SHMCHKDATA_INVALID_VALUE;
    for (int idx = 1; idx < size; idx++) {
        *(list + idx) = idx - 1;
    }

    return KS_OK;
}

int ksShmChunkDataFIFOPut(
    ksChkID     id,
    ksChkIDPtr  list,
    ksChkSize   size,
    ksChkIDPtr  start,
    ksChkIDPtr  end)
{
    if (KS_IS_FULL(size, start, end)) {
        return KS_NG;
    }

    if (*start <= *end) {

    } else {

    }

    return KS_OK;
}

