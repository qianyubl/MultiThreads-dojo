#include "gtest/gtest.h"
#include "../Include/MultipleThread.hpp"
class MultiThreadsTestSuite : public ::testing::Test
{
public:
    void SetUp()
    {
        g_syncTds = 0;
    }
    void TearDown()
    {   
//        string * filenames;
//        system("*.txt > filenames");
//        for( int i = 0; i  <  filenames->length(); i++)
//        {   
//            cout<< i<<endl;
//            m_mt.clearfile(filenames[i]); 

//        }
       m_mt.clearfile("test.txt");
       m_mt.clearfile("A.txt");
       m_mt.clearfile("B.txt");


    }
    MultipleThread m_mt;
};

TEST_F(MultiThreadsTestSuite, CreateAndWriteFile)
{   
    m_mt.creatAndWriteFile("test.txt","ABCD");
    EXPECT_EQ("ABCD",m_mt.ReadFromFile("test.txt"));
}


TEST_F(MultiThreadsTestSuite, SingleThreadShouldWriteSingleChar)
{   
    m_mt.creatThreadA("test.txt", 1);
    EXPECT_EQ("A",m_mt.ReadFromFile("test.txt")); 
}

TEST_F(MultiThreadsTestSuite, create2ThreadsWriteABIntoTheSameFile)
{
    m_mt.creatThreads(1);
    EXPECT_EQ("AB",m_mt.ReadFromFile("test.txt"));
}

TEST_F(MultiThreadsTestSuite, create2ThreadsWriteServeralABsIntoTheSameFile)
{
    m_mt.creatThreads(5);
    EXPECT_EQ("ABABABABAB",m_mt.ReadFromFile("test.txt"));
}

TEST_F(MultiThreadsTestSuite, create2ThreadsWriteServeralABsIntoDifferentFile)
{
    m_mt.creatThreads4DiffFiles(2);
    EXPECT_EQ("AB",m_mt.ReadFromFile("A.txt"));
    EXPECT_EQ("BA",m_mt.ReadFromFile("B.txt"));
}

