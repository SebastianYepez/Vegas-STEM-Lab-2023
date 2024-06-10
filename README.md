# Vegas-STEM-Lab-2023

## Description
In light of my recent completion of the 2024 Vegas STEM Lab, I thought it'd be nice to revisit and share the project that I provided to my students last year at the 2023 Vegas STEM Lab.

Their project was to create a Smart Home that ran solely off DFRobot's Firebeetle ESP32 microprocessor.

At the end, they developed a comprehensive Smart Home project that took in measures of analog and digital data from a variety of sensors in order to mimic a unified smart home experience.

They did so by wiring analog sensors such as gas, soil humidity, and temperature as well as digital sensors such as physical buttons to produce certain responses such as playing a specific tune when the doorbell was rung or emitting an alarm when gas levels exceeded a certain threshold.

Please check out my [Vegas STEM Lab 2024](https://github.com/SebastianYepez/Vegas-STEM-Lab-2024) repository as well!

## Limitations
Because of the amount of signals and power needed, the ESP32 could easily get overwhelmed. An alternative board could be the ESP32 Plus board, with more available pins. Or, one could utilize the Arduino Plus board that came included with the kit. I was instructed to reformat the project to work on a simple ESP32 board, since that is what the students were accustomed to using.

My students simply did not include some sensors in the final project to work around this limitation.

## Usage
There are extensive guides that I have created and provided under the "Project Guides" folder. To get started, simply purchase the KS0085 Keyestudio Smart Home and follow the assembly guide pdf I have provided to assemble the house.

One could then follow the guides I had provided for the ESP32 and complete the sensor tests, or attempt to utilize the included Arduino Plus board and follow the [wiki](https://wiki.keyestudio.com/KS0085_Keyestudio_Smart_Home_Kit_for_Arduino).