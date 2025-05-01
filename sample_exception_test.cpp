#include <gtest/gtest.h>

#include "test/sample_exception.cpp"

TEST(ExceptionalTest, MemoryAllocation)
{
    SampleException sample;
    sample.initComponents();

    // Check if the memory allocation was successful
    ASSERT_NE(sample.m_intPtr, nullptr);
}

TEST(ExceptionalTest, MemoryAllocation2)
{
    SampleException sample;
    sample.set_test_slot(unittest_enhanced::BAD_ALLOC, 1);
    sample.initComponents();

    // Check if the memory allocation was successful
    ASSERT_EQ(sample.m_intPtr, nullptr);
}

TEST(ExceptionalTest, MemoryAllocation3)
{
    SampleException sample;
    sample.set_test_slot(unittest_enhanced::BAD_ALLOC, 2);
    sample.initComponents();

    // Check if the memory allocation was successful
    ASSERT_EQ(sample.m_intPtr, nullptr);
}

TEST(ExceptionalTest, MemoryAllocation4)
{
    SampleException sample;
    sample.set_test_slot(unittest_enhanced::BAD_ALLOC, 3);
    sample.initComponents();

    // Check if the memory allocation was successful
    ASSERT_EQ(sample.m_intPtr, nullptr);
}
