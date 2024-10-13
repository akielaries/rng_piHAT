#include <stdint.h>

#include "rng/circuit_driver.h"
#include "comms/comms.h"


rng_driver_t avalanche_ops {
  .init = init,
  .reset = reset,
  .read_one = read_one,
  .read = read,
  .ioctl = ioctl,
};


static int init(rng_context_t *ctx) {
  int ret = 0;

  return ret;
}

static int reset(rng_context_t *ctx) {
  int ret = 0;

  return ret;
}

static int read_one(rng_context_t *ctx, uint16_t timeout_ms) {
  int read_bytes = 0;

  return read_bytes;
}

static int read(rng_context_t *ctx, uint32_t *buf, uint16_t buf_sz, uint16_t timeout_ms) {
  int read_bytes = 0;

  return read_bytes;
}

static int ioctl(rng_context_t *ctx, uint32_t opcode, void *data) {
  int ret = 0;

  return ret;
}
