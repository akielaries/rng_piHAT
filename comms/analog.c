#include <stdint.h>
#include <stddef.h>

#include "comms.h"

static int init(comm_context_t *ctx);
static int read_one(comm_context_t *ctx, uint16_t timeout_ms);
static int read(comm_context_t *ctx, uint32_t *rx, uint16_t rx_sz, uint16_t timeout_ms);

comm_driver_t analog_ops = {
  .init = init,
  .read_one = read_one,
  .read = read,
  .write_one = NULL,  /** @brief I only want to perform analog reads */
  .write = NULL,      /** @brief I only want to perform analog reads */
};

static int init(comm_context_t *ctx) {
  int ret = 0;

  return ret;
}

static int read_one(comm_context_t *ctx, uint16_t timeout_ms) {
  int bytes_read = 0;

  return bytes_read;
}

static int read(comm_context_t *ctx, uint32_t *rx, uint16_t rx_sz, uint16_t timeout_ms) {
  int bytes_read = 0;

  return bytes_read;
}
