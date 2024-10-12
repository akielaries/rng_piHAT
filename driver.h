#ifndef RNG_DRIVER_H
#define RNG_DRIVER_H

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
   */
  int (*init)(rng_context_t *ctx);
  /**
   * @brief reset circuit via GPIO
   */
  int (*reset)(rng_context_t *ctx);
  /**
   * @brief read one byte from the stream
   */
  int (*read_one)(rng_context *ctx, int32_t byte);
  /**
   * @brief read a buffer of bytes from the stream
   */
  int (*read)(rng_context_t *ctx, int32_t *bytes);
} rng_driver_t;

#endif
