#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

#include "circuit_driver.h"
#include "comms.h"

/** @brief forward declarations of available RNG drivers */
extern rng_driver_t avalanche_ops;
extern rng_driver_t thermal_ops;

/** @brief registry struct */
typedef struct {
  rng_types_e   type;
  rng_driver_t  *ops;
} rng_driver_entry_t;

/** @brief driver registry table */
static rng_driver_entry_t rng_driver_registry[] = {
  { RNG_AVALANCHE_NOISE,  &avalanche_ops },
  { RNG_THERMAL_NOISE,    &thermal_ops },
  { RNG_TYPES_END,        NULL }, // termination
};

/** @brief static RNG ctx */
static rng_context_t gl_rng_ctx;

/** @brief device driver registry lookup */
static rng_driver_t *find_rng_driver(rng_types_e type) {
  //printf("finding RNG driver type {%d} from registry...\n", type);
  LOG(LOG_LEVEL_INFO, "finding RNG driver type {%d} from registry...\n", type);

  for (int i = 0; rng_driver_registry[i].type != RNG_TYPES_END; ++i) {
    if (rng_driver_registry[i].type == type) {
      return rng_driver_registry[i].ops;
    }
  }
  return NULL;
}

/** brief top level initialize function */
rng_context_t *rng_init(rng_types_e type) {
  printf("initializing RNG driver with type %d...\n", type);
  LOG(LOG_LEVEL_INFO, "intializing RNG driver type {%d}...\n", type);

  // find the driver for the given RNG type
  rng_driver_t *driver = find_rng_driver(type);
  if (!driver || !driver->init) {
    return NULL; // driver not found or missing init function
  }

  // init the static context
  gl_rng_ctx.type = type;
  gl_rng_ctx.driver = driver;
  // ready to call the driver-specific init function
  if (driver->init(&gl_rng_ctx) < 0) {
    return NULL; // Initialization failed
  }
  return &gl_rng_ctx;
}
