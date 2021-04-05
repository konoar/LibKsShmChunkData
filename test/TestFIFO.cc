/***********************************************

  TestFIFO.cc
    copyright 2021.04.04 konoar

 ***********************************************/

#include "gtest/gtest.h"

extern "C"
{
    #include "KsDefine.h"
    #include "KsShmChunkData.h"
    #include "KsShmChunkDataFIFO.h"
}

#define KS_FIFO_TEST_SIZE 8

class TestFIFO : public testing::Test
{
protected:

    ksChkID list[KS_FIFO_TEST_SIZE];
    ksChkID start;
    ksChkID end;

    void SetUp()
    {
        for (int idx = 0; idx < KS_FIFO_TEST_SIZE; idx++) {
            list[idx] = KS_SHMCHKDATA_INVALID_VALUE;
        }
        start = end = KS_SHMCHKDATA_INVALID_VALUE;
    }

};

TEST_F(TestFIFO, Init01)
{
    ASSERT_EQ(KS_OK, ksShmChunkDataFIFOInit(list, 8, &start, &end));

    ASSERT_EQ(0, start);
    ASSERT_EQ(7, end);

    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[0]);
    ASSERT_EQ(0,                            list[1]);
    ASSERT_EQ(1,                            list[2]);
    ASSERT_EQ(2,                            list[3]);
    ASSERT_EQ(3,                            list[4]);
    ASSERT_EQ(4,                            list[5]);
    ASSERT_EQ(5,                            list[6]);
    ASSERT_EQ(6,                            list[7]);
}

TEST_F(TestFIFO, Put01)
{
    start = end = 0;

    ASSERT_EQ(KS_OK, ksShmChunkDataFIFOPut(0, list, 8, &start, &end));

    ASSERT_EQ(0, start);
    ASSERT_EQ(1, end);

    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[0]);
    ASSERT_EQ(0,                            list[1]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[2]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[3]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[4]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[5]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[6]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[7]);
}

