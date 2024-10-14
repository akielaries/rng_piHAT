/**
 *
 * @description Driver entry point for interfacing with the various hardware
 * random number generator circuits on the HAT. This file takes care of driver
 * setup, initiating reading from analog pins mapped to an RNG, and streaming
 * random data to one of the 3 serial transmission options. The firmware 
 * running on the HAT accepts a mux to change the RNG -> serial output mapping
 */

#include <stdio.h>

#include "rng/circuit_driver.h"
#include "comms.h"


int main (void) {
  int ret = 0;

  LOG(LOG_LEVEL_INFO, "starting with ret=%d\n", ret);

  //rng_context_t *rng_ctx = rng_init(RNG_AVALANCHE_NOISE);
  rng_context_t *rng_ctx = rng_init(RNG_THERMAL_NOISE);
  if (!rng_ctx) {
    ret = -1;
    return ret;
  }



  LOG(LOG_LEVEL_INFO, "ending with ret=%d\n", ret);
  return ret;
}
