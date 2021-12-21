/**
 * @file test_fifo.cpp
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2021-12-17
 * 
 * @copyright Copyright Alyce (c) 2021
 */

extern "C" {
#include "pixelfifo.h"
}

#include "gtest/gtest.h"

TEST(fifo, push)
{
    struct pixelfifo_s fifo;
    uint8_t buffer[10];
    fifo_init(&fifo, buffer, 10);
    fifo_push(&fifo, 1);
    fifo_push(&fifo, 2);
    fifo_push(&fifo, 3);
    fifo_push(&fifo, 4);
    fifo_push(&fifo, 5);
    fifo_push(&fifo, 6);
    fifo_push(&fifo, 7);
    fifo_push(&fifo, 8);
    fifo_push(&fifo, 9);
    fifo_push(&fifo, 10);
    EXPECT_EQ(fifo.buffer[0], 1);
    EXPECT_EQ(fifo.buffer[1], 2);
    EXPECT_EQ(fifo.buffer[2], 3);
    EXPECT_EQ(fifo.buffer[3], 4);
    EXPECT_EQ(fifo.buffer[4], 5);
    EXPECT_EQ(fifo.buffer[5], 6);
    EXPECT_EQ(fifo.buffer[6], 7);
    EXPECT_EQ(fifo.buffer[7], 8);
    EXPECT_EQ(fifo.buffer[8], 9);
    EXPECT_EQ(fifo.buffer[9], 10);
}

TEST(fifo, push_2)
{
    struct pixelfifo_s fifo;
    uint8_t buffer[10];
    fifo_init(&fifo, buffer, 10);
    fifo_push(&fifo, 0xFF);
    fifo_push(&fifo, 0xFF);
    EXPECT_EQ(fifo.buffer[0], 0xFF);
    EXPECT_EQ(fifo.buffer[1], 0xFF);
}

TEST(fifo, push_3)
{
    struct pixelfifo_s fifo;
    uint8_t buffer[10];
    fifo_init(&fifo, buffer, 10);
    fifo_push(&fifo, 0xFF);
    fifo_push(&fifo, 0xFF);
    fifo_push(&fifo, 0xFF);
    EXPECT_EQ(fifo.buffer[0], 0xFF);
    EXPECT_EQ(fifo.buffer[1], 0xFF);
    EXPECT_EQ(fifo.buffer[2], 0xFF);
}

TEST(fifo, pop)
{
    struct pixelfifo_s fifo;
    uint8_t buffer[10];
    fifo_init(&fifo, buffer, 10);
    fifo_push(&fifo, 0xFF);
    fifo_push(&fifo, 0xFF);
    fifo_push(&fifo, 0xFF);
    EXPECT_EQ(fifo_pop(&fifo), 0xFF);
    EXPECT_EQ(fifo_pop(&fifo), 0xFF);
    EXPECT_EQ(fifo_pop(&fifo), 0xFF);
}

TEST(fifo, pop_and_push)
{
    struct pixelfifo_s fifo;
    uint8_t buffer[10];
    fifo_init(&fifo, buffer, 10);
    fifo_push(&fifo, 0x1);
    fifo_push(&fifo, 0x2);
    fifo_push(&fifo, 0x3);
    EXPECT_EQ(fifo_pop(&fifo), 0x3);
    EXPECT_EQ(fifo_pop(&fifo), 0x2);
    EXPECT_EQ(fifo_pop(&fifo), 0x1);
    fifo_push(&fifo, 0xFF);
    fifo_push(&fifo, 0xFF);
    fifo_push(&fifo, 0xFF);
    EXPECT_EQ(fifo_pop(&fifo), 0xFF);
    EXPECT_EQ(fifo_pop(&fifo), 0xFF);
    EXPECT_EQ(fifo_pop(&fifo), 0xFF);
}