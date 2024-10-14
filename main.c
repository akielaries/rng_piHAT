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


int main (void) {
  int ret = 0;

  printf("starting\n");



  return ret;
}
