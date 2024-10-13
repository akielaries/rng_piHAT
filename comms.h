#ifndef COMMS_H
#define COMMS_H

typedef enum {
  COMMS_SPI = 0,
  COMMS_UART,
  COMMS_I2C,
} comm_types_e;

typedef struct {
  uint8_t type;
} comm_context_t;

typedef struct {
  /**
   * @brief initialize comms + type
   */
  int (*init)(comm_context_t *ctx)
} comm_driver_t;

#endif
