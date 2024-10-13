#include <stdint.h>
#include <stddef.h>

#include "comms.h"

static int analog_init(comm_context_t *ctx);
static int analog_read_one(comm_context_t *ctx, uint16_t timeout_ms);
static int analog_read(comm_context_t *ctx, uint32_t *rx, uint16_t rx_sz, uint16_t timeout_ms);
static int analog_ioctl(comm_context_t *ctx, uint32_t opcode, void *data);


comm_driver_t analog_ops = {
  .init       = analog_init,
  .read_one   = analog_read_one,
  .read       = analog_read,
  .write_one  = NULL, /** @brief I only want to perform analog reads */
  .write      = NULL, /** @brief I only want to perform analog reads */
  .ioctl      = analog_ioctl,
};

static int analog_init(comm_context_t *ctx) {
  int ret = 0;

  return ret;
}

static int analog_read_one(comm_context_t *ctx, uint16_t timeout_ms) {
  int bytes_read = 0;

  return bytes_read;
}

static int analog_read(comm_context_t *ctx, uint32_t *rx, uint16_t rx_sz, uint16_t timeout_ms) {
  int bytes_read = 0;

  return bytes_read;
}

static int analog_ioctl(comm_context_t *ctx, uint32_t opcode, void *data) {
  int ret = 0;

  return ret;
}
