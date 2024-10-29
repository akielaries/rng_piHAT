# rng_piHAT
Pi HAT with randon noise and number generators 

# Design
## PCB
![PCB_design](schematic/PCB_design.pdf)
![PCB_3d](schematic/PCB_3d.pdf)

## Schematic
![schematic](schematic/schematic.pdf)

# Hardware Random Number Generators
## Some notes for potential use
Potential entropy sources (with a combination of other parts):
* one of the many amps or comparators I have
* PC817 optocoupler
* CD4047 CMOS monostable/astable multivibrator
* NE555 timer
* PT2399 digital delay echo audio processor
* Linear Feedback Shift Register

## Avalanche noise generator
The avalanche noise generator circuit consists of:
- 2x 4.7k resistors
- 1x 10k resistor
- 1x 1m resistor
- 3x 3904 NPN transistors
- 10uf capacitor
- 0.1uf capacitor
