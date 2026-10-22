# Lightweight Ring Buffer for STM32

A lightweight, fixed-size lock-free circular (ring) buffer implementation in C, optimized for embedded systems and **STM32 microcontrollers**. 

It is ideal for handling asynchronous data streams, such as buffering bytes received via **UART (RX/TX)**, SPI, or I2C in Interrupt Service Routines (ISRs).

## Features

**Zero Allocation:** Uses a fixed-size static array (`32` bytes, but you can change it easily). No `malloc` or dynamic memory.
**Lock-Free Single-Producer Single-Consumer (SPSC):** Safe to push in an ISR and pop in the main loop (or vice versa) without mutexes, thanks to `volatile` indices that prevent unwanted compiler optimizations.
**Lightweight:** Designed with a minimal footprint for resource-constrained MCUs.

## API Reference

### `bool push(RingBuffer* rb, uint8_t byte)`
Adds a byte to the head of the buffer.
**Returns:** `true` if successful, `false` if the buffer is full.

### `bool pop(RingBuffer* rb, uint8_t* byte)`
Removes a byte from the tail of the buffer and stores it in the provided pointer.
**Returns:** `true` if successful, `false` if the buffer is empty.

