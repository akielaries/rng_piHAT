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
  int (*init)(comm_context_t *ctx);
  /** 
   * @brief read one byte from the comms stream
   *
   * @return byte read, some meaningful errno on failure
   */
  int (*read_one)(comm_context_t *ctx, uint16_t timeout_ms);
  /** 
   * @brief read a buffer of bytes from the comms stream
   *
   * @return bytes read, < 0 on failure
   */
  int (*read)(comm_context_t *ctx, uint32_t *rx, uint16_t rx_sz, uint16_t timeout_ms);
  /** 
   * @brief read a buffer of random bytes from the stream
   *
   * @param[in] ctx       comm context pointer
   * @param[in] data      single uint32 input
   * @param[in] timout_ms timeout after given time
   *
   * @return bytes written, < 0 on failure
   */
  int (*write_one)(comm_context_t *ctx, uint32_t tx, uint16_t timeout_ms);
  /**
   * @brief write a buffer of bytes to the comms stream
   *
   *
   * @return bytes written, < 0 on failure
   */
  int (*write)(comm_context_t *ctx, uint32_t *tx, uint16_t tx_sz, uint16_t timeout_ms);

} comm_driver_t;

#endif
