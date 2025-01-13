# Midi_Piano_Code49
We had a broken M-Audio Code49 Midi Controller where the Main chip was fried.
Replacing this chip was not an option, because we don't have the firmware and no way of flashing it.
We decided to just reuse the Keyboard with its connectors and Strap a Raspberry Pi Pico (RP2040) to them.
With this we loose all the Encoders and Drumpad buttons etc.. but we have a working Midi Piano at least.
With Multiplexers, you could of course add more of the Controls again, but this was too much work for us and we'll reuse those parts on other projects.

Shoutout to Thorbjoern for the collaboration: [thorbijoern.github.io/wiki/****](https://thorbijoern.github.io/wiki/)

# Programming the RP2040
* In Arduino IDE under Boards, install the "Arduino Mbed OS RP2040 Boards"
* Under Tools > Board, Select "Arduino Mbed OS RP2040 Boards" > Raspberry Pi Pico
* Install the Control Surface Library https://github.com/tttapa/Control-Surface

# Upload the code
* use the provided .ino script
* Figuring out the Pin Numbers is the most difficult part and requires a lot of tinkering
* Notes to be sent by the Keys can be adjusted in the Note Matrix in the code


