#include <stdint.h>

#include "circuit_driver.h"
#include "comms.h"

static int thermal_init(rng_context_t *ctx);
static int thermal_reset(rng_context_t *ctx);
static int thermal_read_one(rng_context_t *ctx, uint16_t timeout_ms);
static int thermal_read(rng_context_t *ctx, uint32_t *buf, uint16_t buf_sz, uint16_t timeout_ms);
static int thermal_ioctl(rng_context_t *ctx, uint32_t opcode, void *data);


rng_driver_t thermal_ops = {
  .init     = thermal_init,
  .reset    = thermal_reset,
  .read_one = thermal_read_one,
  .read     = thermal_read,
  .ioctl    = thermal_ioctl,
};


static int thermal_init(rng_context_t *ctx) {
  int ret = 0;

  return ret;
}

static int thermal_reset(rng_context_t *ctx) {
  int ret = 0;

  return ret;
}

static int thermal_read_one(rng_context_t *ctx, uint16_t timeout_ms) {
  int read_bytes = 0;

  return read_bytes;
}

static int thermal_read(rng_context_t *ctx, uint32_t *buf, uint16_t buf_sz, uint16_t timeout_ms) {
  int read_bytes = 0;

  return read_bytes;
}

static int thermal_ioctl(rng_context_t *ctx, uint32_t opcode, void *data) {
  int ret = 0;

  return ret;
}
