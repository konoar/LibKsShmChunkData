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

class TestFIFO : public testing::Test
{
protected:

    void SetUp()
    {
    }

    void TearDown()
    {
    }

};

TEST_F(TestFIFO, Case01)
{
    ASSERT_EQ(KS_OK, ksShmChunkDataInit());
}

