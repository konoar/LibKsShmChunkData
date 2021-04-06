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

#define KS_FIFO_TEST_SIZE 7

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
    ASSERT_EQ(KS_OK, ksShmChunkDataFIFOInit(list, KS_FIFO_TEST_SIZE, &start, &end));

    ASSERT_EQ(0, start);
    ASSERT_EQ(6, end);

    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[0]);
    ASSERT_EQ(0,                            list[1]);
    ASSERT_EQ(1,                            list[2]);
    ASSERT_EQ(2,                            list[3]);
    ASSERT_EQ(3,                            list[4]);
    ASSERT_EQ(4,                            list[5]);
    ASSERT_EQ(5,                            list[6]);
}

TEST_F(TestFIFO, Put01)
{
    start   = 0;
    end     = 6;

    list[0] = KS_SHMCHKDATA_INVALID_VALUE;
    list[1] = 0;
    list[2] = 1;
    list[3] = 2;
    list[4] = 3;
    list[5] = 4;
    list[6] = 5;

    ASSERT_EQ(KS_NG, ksShmChunkDataFIFOPut(415, list, KS_FIFO_TEST_SIZE, &start, &end));

    ASSERT_EQ(0, start);
    ASSERT_EQ(6, end);

    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[0]);
    ASSERT_EQ(0,                            list[1]);
    ASSERT_EQ(1,                            list[2]);
    ASSERT_EQ(2,                            list[3]);
    ASSERT_EQ(3,                            list[4]);
    ASSERT_EQ(4,                            list[5]);
    ASSERT_EQ(5,                            list[6]);
}

TEST_F(TestFIFO, Put02)
{
    start   = 6;
    end     = 5;

    list[0] = 0;
    list[1] = 1;
    list[2] = 2;
    list[3] = 3;
    list[4] = 4;
    list[5] = 5;
    list[6] = KS_SHMCHKDATA_INVALID_VALUE;

    ASSERT_EQ(KS_NG, ksShmChunkDataFIFOPut(415, list, KS_FIFO_TEST_SIZE, &start, &end));

    ASSERT_EQ(6, start);
    ASSERT_EQ(5, end);

    ASSERT_EQ(0,                            list[0]);
    ASSERT_EQ(1,                            list[1]);
    ASSERT_EQ(2,                            list[2]);
    ASSERT_EQ(3,                            list[3]);
    ASSERT_EQ(4,                            list[4]);
    ASSERT_EQ(5,                            list[5]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[6]);
}

TEST_F(TestFIFO, Put03)
{
    start   = 3;
    end     = 2;

    list[0] = 3;
    list[1] = 4;
    list[2] = 5;
    list[3] = KS_SHMCHKDATA_INVALID_VALUE;
    list[4] = 0;
    list[5] = 1;
    list[6] = 2;

    ASSERT_EQ(KS_NG, ksShmChunkDataFIFOPut(415, list, KS_FIFO_TEST_SIZE, &start, &end));

    ASSERT_EQ(3, start);
    ASSERT_EQ(2, end);

    ASSERT_EQ(3,                            list[0]);
    ASSERT_EQ(4,                            list[1]);
    ASSERT_EQ(5,                            list[2]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[3]);
    ASSERT_EQ(0,                            list[4]);
    ASSERT_EQ(1,                            list[5]);
    ASSERT_EQ(2,                            list[6]);
}

TEST_F(TestFIFO, Put04)
{
    start   = 0;
    end     = 0;

    list[0] = KS_SHMCHKDATA_INVALID_VALUE;
    list[1] = KS_SHMCHKDATA_INVALID_VALUE;
    list[2] = KS_SHMCHKDATA_INVALID_VALUE;
    list[3] = KS_SHMCHKDATA_INVALID_VALUE;
    list[4] = KS_SHMCHKDATA_INVALID_VALUE;
    list[5] = KS_SHMCHKDATA_INVALID_VALUE;
    list[6] = KS_SHMCHKDATA_INVALID_VALUE;

    ASSERT_EQ(KS_OK, ksShmChunkDataFIFOPut(415, list, KS_FIFO_TEST_SIZE, &start, &end));

    ASSERT_EQ(0, start);
    ASSERT_EQ(1, end);

    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[0]);
    ASSERT_EQ(415,                          list[1]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[2]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[3]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[4]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[5]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[6]);
}

TEST_F(TestFIFO, Put05)
{
    start   = 6;
    end     = 6;

    list[0] = KS_SHMCHKDATA_INVALID_VALUE;
    list[1] = KS_SHMCHKDATA_INVALID_VALUE;
    list[2] = KS_SHMCHKDATA_INVALID_VALUE;
    list[3] = KS_SHMCHKDATA_INVALID_VALUE;
    list[4] = KS_SHMCHKDATA_INVALID_VALUE;
    list[5] = KS_SHMCHKDATA_INVALID_VALUE;
    list[6] = KS_SHMCHKDATA_INVALID_VALUE;

    ASSERT_EQ(KS_OK, ksShmChunkDataFIFOPut(415, list, KS_FIFO_TEST_SIZE, &start, &end));

    ASSERT_EQ(6, start);
    ASSERT_EQ(0, end);

    ASSERT_EQ(415,                          list[0]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[1]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[2]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[3]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[4]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[5]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[6]);
}

TEST_F(TestFIFO, Put06)
{
    start   = 3;
    end     = 3;

    list[0] = KS_SHMCHKDATA_INVALID_VALUE;
    list[1] = KS_SHMCHKDATA_INVALID_VALUE;
    list[2] = KS_SHMCHKDATA_INVALID_VALUE;
    list[3] = KS_SHMCHKDATA_INVALID_VALUE;
    list[4] = KS_SHMCHKDATA_INVALID_VALUE;
    list[5] = KS_SHMCHKDATA_INVALID_VALUE;
    list[6] = KS_SHMCHKDATA_INVALID_VALUE;

    ASSERT_EQ(KS_OK, ksShmChunkDataFIFOPut(415, list, KS_FIFO_TEST_SIZE, &start, &end));

    ASSERT_EQ(3, start);
    ASSERT_EQ(4, end);

    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[0]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[1]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[2]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[3]);
    ASSERT_EQ(415,                          list[4]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[5]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[6]);
}

TEST_F(TestFIFO, Put07)
{
    start   = 0;
    end     = 1;

    list[0] = KS_SHMCHKDATA_INVALID_VALUE;
    list[1] = 0;
    list[2] = KS_SHMCHKDATA_INVALID_VALUE;
    list[3] = KS_SHMCHKDATA_INVALID_VALUE;
    list[4] = KS_SHMCHKDATA_INVALID_VALUE;
    list[5] = KS_SHMCHKDATA_INVALID_VALUE;
    list[6] = KS_SHMCHKDATA_INVALID_VALUE;

    ASSERT_EQ(KS_OK, ksShmChunkDataFIFOPut(415, list, KS_FIFO_TEST_SIZE, &start, &end));

    ASSERT_EQ(0, start);
    ASSERT_EQ(2, end);

    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[0]);
    ASSERT_EQ(0,                            list[1]);
    ASSERT_EQ(415,                          list[2]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[3]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[4]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[5]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[6]);
}

TEST_F(TestFIFO, Put08)
{
    start   = 5;
    end     = 6;

    list[0] = KS_SHMCHKDATA_INVALID_VALUE;
    list[1] = KS_SHMCHKDATA_INVALID_VALUE;
    list[2] = KS_SHMCHKDATA_INVALID_VALUE;
    list[3] = KS_SHMCHKDATA_INVALID_VALUE;
    list[4] = KS_SHMCHKDATA_INVALID_VALUE;
    list[5] = KS_SHMCHKDATA_INVALID_VALUE;
    list[6] = 0;

    ASSERT_EQ(KS_OK, ksShmChunkDataFIFOPut(415, list, KS_FIFO_TEST_SIZE, &start, &end));

    ASSERT_EQ(5, start);
    ASSERT_EQ(0, end);

    ASSERT_EQ(415,                          list[0]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[1]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[2]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[3]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[4]);
    ASSERT_EQ(KS_SHMCHKDATA_INVALID_VALUE,  list[5]);
    ASSERT_EQ(0,                            list[6]);
}
