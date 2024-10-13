
tmp_make:
	arm-none-eabi-gcc comms/analog.c comms/uart.c
	arm-none-eabi-gcc rng/avalanche.c

lazy_verify:
	gcc comms/analog.c comms/uart.c
	gcc rng/avalanche.c
