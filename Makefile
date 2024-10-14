
tmp_make:
	arm-none-eabi-gcc comms/analog.c comms/uart.c rng/avalanche.c

lazy_verify:
	gcc -Werror -Wall -pedantic \
		main.c comms/analog.c comms/i2c.c comms/uart.c comms/spi.c \
		rng/avalanche.c rng/thermal.c rng/circuit_driver.c \
		-Icomms/


