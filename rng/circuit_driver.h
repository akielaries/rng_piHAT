#ifndef RNG_DRIVER_H
#define RNG_DRIVER_H

#include <stdint.h>

typedef enum {
  RNG_AVALANCHE_NOISE = 0,
  RNG_THERMAL_NOISE,
  RNG_SHOT_NOISE,
  RNG_RING_OSCILLATOR,
  RNG_JITTER,
  RNG_DECAY,
} rng_types_e;

typedef struct {
  uint8_t type;
} rng_context_t;

typedef struct {
  /**
   * @brief initialize RNG + type
   *
   * @param[in] ctx         RNG context pointer
   *
   * @return 0 on success, < 0 on failure
   */
  int (*init)(rng_context_t *ctx);
  /**
   * @brief reset circuit via GPIO
   *
   * @param[in] ctx         RNG context pointer
   *
   * @return 0 on success, < 0 on failure
   */
  int (*reset)(rng_context_t *ctx);
  /**
   * @brief read one random byte from the stream
   *
   * @param[in] ctx         RNG context pointer
   * @param[in] timeout_ms  timeout after given time
   *
   * @return byte read, some meaningful errno on failure
   */
  int (*read_one)(rng_context_t *ctx, uint16_t timeout_ms);
  /**
   * @brief read a buffer of random bytes from the stream
   *
   * @param[in] ctx         RNG context pointer
   * @param[in] buf         receive buffer
   * @param[in] buf_sz      receive buffer size
   * @param[in] timeout_ms  timeout after given time
   *
   * @return bytes read, < 0 on failure
   */
  int (*read)(rng_context_t *ctx, uint32_t *buf, uint16_t buf_sz, uint16_t timeout_ms);
  /**
   * @brief device/circuit ioctl operation
   *
   * @param[in]     ctx     RNG context pointer
   * @param[in]     opcode  ioctl operation code
   * @param[in/out] data    return data
   *
   * @return 0 on success, < 0 on failure
   */
  int (*ioctl)(rng_context_t *ctx, uint32_t opcode, void *data);
} rng_driver_t;

#endif
