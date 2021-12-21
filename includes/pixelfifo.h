/**
 * @file pixelfifo.h
 * @author Nicolas IRAGNE (nicolas.iragne@alyce.fr)
 * @brief 
 * @date 2021-12-17
 * 
 * @copyright Copyright Alyce (c) 2021
 */

#pragma once
#include <stdint.h>
#include "renderer.h"

/**
 * @brief A simple structure to represent a FIFO
 */
struct pixelfifo_s
{
    uint8_t *buffer;
    uint32_t size;
    uint32_t index;
};

enum pixelfifo_status_e
{
    PPU_READ_TILE_ID,
    PPU_READ_TILE_DATA0,
    PPU_READ_TILE_DATA1,
    PPU_PUSH_TO_FIFO
};

struct pixelfetcher_s
{
    struct pixelfifo_s* fifo;
    enum pixelfifo_status_e status;
    uint8_t lcdc;
};

void    fifo_init(struct pixelfifo_s *fifo, uint8_t *buffer, uint32_t size);
uint8_t fifo_pop(struct pixelfifo_s *fifo);
void    fifo_push(struct pixelfifo_s *fifo, uint8_t data);
uint32_t fifo_get_size(struct pixelfifo_s *fifo);
void    fifo_clear(struct pixelfifo_s *fifo);

void    ppu_fetch_line(uint16_t adr, uint8_t line, struct pixelfetcher_s *fetcher);