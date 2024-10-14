#include <stdint.h>

#include "circuit_driver.h"
#include "comms.h"

static int avalanche_init(rng_context_t *ctx);
static int avalanche_reset(rng_context_t *ctx);
static int avalanche_read_one(rng_context_t *ctx, uint16_t timeout_ms);
static int avalanche_read(rng_context_t *ctx, uint32_t *buf, uint16_t buf_sz, uint16_t timeout_ms);
static int avalanche_ioctl(rng_context_t *ctx, uint32_t opcode, void *data);


rng_driver_t avalanche_ops = {
  .init     = avalanche_init,
  .reset    = avalanche_reset,
  .read_one = avalanche_read_one,
  .read     = avalanche_read,
  .ioctl    = avalanche_ioctl,
};


static int avalanche_init(rng_context_t *ctx) {
  LOG(LVL_INFO, "calling avalanche init...\n");
  int ret = 0;

  return ret;
}

static int avalanche_reset(rng_context_t *ctx) {
  LOG(LVL_INFO, "calling avalanche reset...\n");
  int ret = 0;

  return ret;
}

static int avalanche_read_one(rng_context_t *ctx, uint16_t timeout_ms) {
  LOG(LVL_INFO, "calling avalanche read_one...\n");
  int read_bytes = 0;

  return read_bytes;
}

static int avalanche_read(rng_context_t *ctx, uint32_t *buf, uint16_t buf_sz, uint16_t timeout_ms) {
  LOG(LVL_INFO, "calling avalanche read...\n");
  int read_bytes = 0;

  return read_bytes;
}

static int avalanche_ioctl(rng_context_t *ctx, uint32_t opcode, void *data) {
  LOG(LVL_INFO, "calling avalanche ioctl...\n");
  int ret = 0;

  return ret;
}
