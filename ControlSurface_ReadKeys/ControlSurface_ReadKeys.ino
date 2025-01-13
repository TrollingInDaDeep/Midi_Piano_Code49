
#include <Control_Surface.h>

//USBMIDI_Interface midi; // For Teensy
PluggableUSBMIDI midi; // For RP2040 -> use "Arduino Mbed OS RP2040 Boards"

//wheels on 40/41
CCPotentiometer modwheelPot {
  27,                                   // Analog pin connected to potentiometer
  {MIDI_CC::Channel_Volume, Channel_1}, // Channel volume of channel 1 //nospring
}; 
CCPotentiometer velocityPot {
  28,                                   // Analog pin connected to potentiometer
  {MIDI_CC::Modulation_Wheel, Channel_1}, // Channel volume of channel 1 //spring
}; 

//OLD Teensy Config
//int rowPins[] = {22, 23, 24, 25, 26, 27, 28, 29}; //outputs, mux
//int colPins[] = {14, 15, 16, 17, 18, 19, 20, 21}; //inputs, direct

int rowPins25[] = {0, 1, 2, 3, 4, 5, 6, 7}; //outputs, SEL
int rowPins24[] = {8, 9, 10, 11, 12, 13, 14, 15}; //outputs, SEL (14 and 15 unused, as only 6 SEL Pins)
int colPins[] = {16, 17, 18, 19, 20, 21, 22, 26}; //inputs, RD


// whic Midi Note Numbers to be sent.
// full = key fully pressed
// none = key half pressed
const AddressMatrix<8, 8> NoteAddresses24 = {{
  {16, 17, 18, 19, 20, 21, 22, 23},//full
  {16, 17, 18, 19, 20, 21, 22, 23},
  {24, 25, 26, 27, 28, 29, 30, 31},//full
  {24, 25, 26, 27, 28, 29, 30, 31},
  {32, 33, 34, 35, 36, 37, 38, 39},//full
  {32, 33, 34, 35, 36, 37, 38, 39},
  {40, 41, 42, 43, 44, 45, 46, 47},//full
  {40, 41, 42, 43, 44, 45, 46, 47}
}};

const AddressMatrix<4, 8> smallNoteAddresses24 = {{
  {16, 17, 18, 19, 20, 21, 22, 23},
  {24, 25, 26, 27, 28, 29, 30, 31},
  {32, 33, 34, 35, 36, 37, 38, 39},
  {40, 41, 42, 43, 44, 45, 46, 47}
}};

const AddressMatrix<8, 8> NoteAddresses25 = {{
  {0, 0, 0, 0, 0, 0, 0, 0},//full
  {48, 49, 50, 51, 52, 53, 54, 55},
  {0, 0, 0, 0, 0, 0, 0, 0}, //full
  {56, 57, 58, 59, 60, 61, 62, 63},
  {0, 0, 0, 0, 0, 0, 0, 0}, //full
  {64, 65, 66, 67, 68, 69, 70, 71},
  {0, 0, 0, 0, 0, 0, 0, 0},//full
  {72, 73, 74, 75, 76, 77, 78, 79} 
}};

const AddressMatrix<4, 8> smallNoteAddresses25 = {{
  {48, 49, 50, 51, 52, 53, 54, 55},
  {56, 57, 58, 59, 60, 61, 62, 63},
  {64, 65, 66, 67, 68, 69, 70, 71},
  {72, 73, 74, 75, 76, 77, 78, 79}
}};

///
/// only for halfPress
///

NoteButtonMatrix<4, 8> KeyMatrix24_small {
  //might be wrong as 14 is unused
  {14,12,10,8},//{28, 26, 24, 22},
  {26, 22, 21, 20, 19, 18, 17, 16}, //{21, 20, 19, 18, 17, 16, 15, 14},
  smallNoteAddresses24,
  Channel_1
};

NoteButtonMatrix<4, 8> KeyMatrix25_small {
  {6,4,2,0},//{28, 26, 24, 22},
  {26, 22, 21, 20, 19, 18, 17, 16}, //{21, 20, 19, 18, 17, 16, 15, 14},
  smallNoteAddresses25,
  Channel_1
};


///
/// Half and fullpress both
///

//WORKING TEENSY
// 25Key button matrix (upper 3 octaves)
// NoteButtonMatrix<8, 8> KeyMatrix25 {
//   {29, 28, 27, 26, 25, 24, 23, 22}, //reversed order
//   {21, 20, 19, 18, 17, 16, 15, 14},
//   NoteAddresses25,
//   Channel_1
// };

//To Test
// 25Key button matrix (upper 3 octaves)
NoteButtonMatrix<8, 8> KeyMatrix25 {
  {7, 6, 5, 4, 3, 2, 1, 0},//{29, 28, 27, 26, 25, 24, 23, 22}, //reversed order
  {26, 22, 21, 20, 19, 18, 17, 16},//{21, 20, 19, 18, 17, 16, 15, 14},
  NoteAddresses25,
  Channel_1
};

//To Test
// 24Key button matrix (lower 3 octaves)
NoteButtonMatrix<8, 8> KeyMatrix24 {
  {15, 14, 13, 12, 11, 10, 9, 8},//reversed order
  {26, 22, 21, 20, 19, 18, 17, 16},//{21, 20, 19, 18, 17, 16, 15, 14},
  NoteAddresses24,
  Channel_1
};

void setup() {
  Serial.begin(9600);
  Control_Surface.begin();
}

void loop() {
  Control_Surface.loop();
}
