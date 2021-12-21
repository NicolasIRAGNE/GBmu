/**
 * @file pixelfifo.c
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2021-12-17
 * 
 * @copyright Copyright Alyce (c) 2021
 */

#include "pixelfifo.h"

void fifo_init(struct pixelfifo_s *fifo, uint8_t *buffer, uint32_t size) 
{
    fifo->buffer = buffer;
    fifo->size = size;
    fifo->index = 0;
}

uint8_t fifo_pop(struct pixelfifo_s *fifo)
{
    fifo->index--;
    uint8_t ret = fifo->buffer[fifo->index];
    return (ret);
}

void fifo_push(struct pixelfifo_s *fifo, uint8_t data)
{
    fifo->buffer[fifo->index] = data;
    fifo->index++;
}

uint32_t fifo_get_size(struct pixelfifo_s *fifo)
{
    return (fifo->size);
}

void fifo_clear(struct pixelfifo_s *fifo) 
{
    fifo->index = 0;
}

