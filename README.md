# SPI on MKL05Z32x4

This coded exercises the MCP4141 SPI controlled potentiometer.

## Multiplexed Serial Data In and Serial Data Out on MCP4141
1. MOSI (Master Out, Slave In) is connected to SDI/SDO via a 680R resistor.
1. SDI/SDO is connected directly to MISO.
1. When Master wishes to read Slave, Master issues a 2-byte write.
  Top 4 most-significant bits are the Slave's memory address.
  The remainder bits are all set to 1's.


