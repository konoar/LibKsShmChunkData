/***********************************************

  KsShmChunkDataFIFO.h
    copyright 2021.04.04 konoar

 ***********************************************/

#ifndef __KS_SHM_CHUNK_DATA_FIFO_H__
#define __KS_SHM_CHUNK_DATA_FIFO_H__

#define KS_SHMCHKDATA_INVALID_VALUE 0xffffffff

typedef unsigned int  ksChkID;
typedef unsigned int* ksChkIDPtr;
typedef unsigned int  ksChkSize;

int ksShmChunkDataFIFOInit(
    ksChkIDPtr  list,
    ksChkSize   size,
    ksChkIDPtr  start,
    ksChkIDPtr  end);

int ksShmChunkDataFIFOPut(
    ksChkID     id,
    ksChkIDPtr  list,
    ksChkSize   size,
    ksChkIDPtr  start,
    ksChkIDPtr  end);

#endif // __KS_SHM_CHUNK_DATA_FIFO_H__

