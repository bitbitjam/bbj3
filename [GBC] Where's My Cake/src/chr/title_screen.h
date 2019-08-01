// ///////////////////////
// //                   //
// //  File Attributes  //
// //                   //
// ///////////////////////

// Filename: title_screen.png
// Pixel Width: 160px
// Pixel Height: 144px

// /////////////////
// //             //
// //  Constants  //
// //             //
// /////////////////

const int title_screen_tile_map_size = 0x0168;
const int title_screen_tile_map_width = 0x14;
const int title_screen_tile_map_height = 0x12;

const int title_screen_tile_data_size = 0x0D20;
const int title_screen_tile_count = 0x0168;

// ////////////////
// //            //
// //  Map Data  //
// //            //
// ////////////////

const unsigned char title_screen_map_data[] ={
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x00,0x06,0x07,0x08,0x09,0x0A,0x00,
  0x00,0x0B,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,
  0x14,0x15,0x16,0x00,0x17,0x18,0x19,0x00,0x00,0x00,0x00,0x00,0x1A,0x1B,0x1C,0x1D,
  0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,0x31,0x32,0x33,0x34,0x35,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,
  0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x00,0x00,0x00,0x47,0x48,0x49,0x4A,0x4B,0x4C,
  0x4D,0x4E,0x4F,0x00,0x17,0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x00,0x00,0x57,0x58,
  0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,0x00,0x60,0x61,0x62,0x63,0x64,0x65,0x66,0x67,
  0x00,0x00,0x00,0x68,0x69,0x00,0x6A,0x6B,0x62,0x6C,0x6D,0x6E,0x6F,0x70,0x71,0x72,
  0x73,0x74,0x75,0x76,0x00,0x00,0x00,0x00,0x00,0x00,0x77,0x78,0x79,0x7A,0x7B,0x7C,
  0x7D,0x7E,0x7F,0x80,0x81,0x82,0x83,0x00,0x00,0x00,0x00,0x84,0x85,0x86,0x87,0x88,
  0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,0x90,0x91,0x00,0x00,0x00,0x00,0x00,0x00,0x92,
  0x93,0x94,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x95,0x96,0x97,0x98,0x99,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,0xA0,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA8,0xA9,0xAA,0xAB,
  0xAC,0xAD,0xAE,0xAF,0xB0,0x00,0x00,0x00,0xB1,0xB2,0xB3,0xB4,0xB5,0xB6,0xB7,0x00,
  0xB8,0xB9,0xBA,0xBB,0xBC,0xBD,0xBE,0xBF,0xC0,0x00,0x00,0xC1,0xC2,0xC3,0xC4,0xC5,
  0xC6,0xC7,0xC8,0x00,0xC9,0xCA,0xCB,0xCC,0xCD,0xCE,0xCF,0xD0,0xD1,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

// /////////////////
// //             //
// //  Tile Data  //
// //             //
// /////////////////

const unsigned char title_screen_tile_data[] ={
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x03,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0xC0,0x3F,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0x7F,0x80,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x00,0x60,0x00,0xC0,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x06,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x07,0x00,0x0A,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x3E,0x00,0xF1,0x0E,0xC3,0x3C,0x07,0xF8,0x0F,0xF0,
  0x03,0x00,0x0E,0x00,0x3E,0x01,0xF8,0x07,0xE0,0x1F,0xC1,0x3F,0x87,0x7F,0x0F,0xFF,
  0xFF,0x00,0xC1,0x3E,0x00,0xFF,0x0F,0xFF,0x7F,0xFF,0xFC,0xFC,0xE0,0xE0,0x80,0x80,
  0x80,0x00,0xC0,0x00,0xE0,0x00,0xF0,0x80,0xF0,0xC8,0x30,0x0C,0x32,0x0E,0x33,0x0F,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0xF8,0x00,
  0x07,0x00,0x06,0x01,0x06,0x01,0x06,0x01,0x06,0x01,0x06,0x01,0x07,0x00,0x03,0x00,
  0x00,0xFF,0x0F,0xFF,0x3F,0xFF,0x7C,0xFC,0x70,0xF0,0x60,0xE0,0x60,0xE0,0xE0,0x60,
  0x00,0xFF,0xE0,0xFF,0xFF,0xFF,0x07,0x07,0x00,0x00,0x10,0x00,0x10,0x08,0x30,0x0C,
  0xC8,0x00,0x7F,0x80,0xF3,0x8C,0xF0,0x8F,0x73,0x0F,0x73,0x0F,0xF3,0x0F,0xF3,0x0F,
  0x03,0x00,0x03,0x00,0x07,0x80,0x07,0xC0,0x2E,0xE0,0xFE,0xF0,0x3F,0x20,0x3F,0x00,
  0x00,0x80,0x40,0xC0,0x20,0xE0,0x20,0xE0,0x30,0xF0,0x31,0xF0,0x33,0xF0,0x33,0xF0,
  0x1C,0x03,0x38,0x07,0x70,0x0F,0xE1,0x1F,0xE3,0x1F,0xC7,0x3E,0x87,0x7E,0x8F,0x7C,
  0x3E,0xE1,0x7C,0xC3,0xF8,0x87,0xF0,0x8F,0xF1,0x0F,0xE3,0x1F,0xC3,0x3F,0xC7,0x3F,
  0x1E,0xFA,0x3E,0xF8,0x7B,0xF8,0xF1,0xF0,0xE0,0xE0,0xC0,0xC0,0x80,0x80,0x00,0x00,
  0x00,0x00,0x00,0x00,0x81,0x00,0xFF,0x00,0xFF,0x00,0x00,0x7F,0x00,0x3F,0x1F,0x1F,
  0x73,0x0F,0xF3,0x0F,0xE3,0x1F,0xC3,0x3F,0x07,0xFF,0x0F,0xFF,0x3E,0xFE,0xFC,0xFC,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,
  0xF8,0x04,0xF0,0x0E,0x31,0x4F,0x73,0x0F,0x63,0x1F,0xE3,0x1F,0xC7,0x3F,0x87,0x7F,
  0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
  0x03,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xE0,0x00,0xFF,0x00,0x7F,0x80,0x00,0x7F,0x20,0x3F,0x1F,0x1F,0x07,0x07,0x00,0x00,
  0x72,0x0E,0xE3,0x1E,0x83,0x7E,0x07,0xFE,0x1F,0xFC,0xFF,0xFC,0xFF,0xF8,0x07,0x00,
  0xE3,0x1F,0xE3,0x1F,0xE7,0x1F,0xC7,0x3E,0xC7,0x3E,0xCF,0x3C,0x8F,0x7C,0x8E,0x79,
  0x3F,0x00,0x7E,0x01,0xEE,0x01,0xFE,0x01,0xBC,0x43,0xBC,0x43,0x78,0x87,0x78,0x87,
  0x37,0xF0,0x3E,0xF1,0x3C,0xF3,0x7C,0xE3,0x78,0xE7,0x78,0xC7,0xF1,0x8F,0xE1,0x9F,
  0x1E,0xF8,0x1F,0xF8,0x3F,0xF0,0x7F,0xF0,0xFF,0xE0,0xFE,0xE1,0xFC,0xC3,0xF8,0xC7,
  0x8F,0x7F,0x0E,0xFE,0x1C,0xFC,0xFC,0x3C,0xF8,0x18,0x60,0x90,0x60,0x98,0xE4,0x1C,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x07,0x00,0x0F,0x00,0x1E,0x01,
  0x0F,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0x60,0x90,0x60,0x98,0xE5,0x1C,
  0xF0,0xF0,0x00,0x00,0x00,0x00,0x70,0x00,0xD9,0x00,0x8F,0x00,0xDF,0x00,0xFE,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x81,0x00,0x03,0xC0,0x05,0xE0,0x3F,0xF0,
  0x03,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0xF0,0x00,0xB0,0x48,0xB0,0x4C,0x72,0x8E,
  0x0E,0xFE,0x1E,0xFE,0x3F,0xFC,0x7F,0x78,0x3E,0x31,0x1C,0x03,0x3C,0x03,0x36,0x09,
  0x00,0x00,0x00,0x00,0x80,0x00,0x00,0xC0,0x00,0xE0,0x30,0xF0,0x78,0xF8,0xF0,0xF0,
  0x07,0x00,0x0F,0x00,0x0E,0x01,0x1E,0x01,0x1C,0x03,0x1C,0x03,0x3C,0x03,0x39,0x06,
  0x1E,0xF1,0x1C,0xF3,0x38,0xE7,0x38,0xC7,0x71,0x8E,0x61,0x9E,0xE3,0x1E,0xC7,0x3C,
  0x71,0x8F,0xF1,0x0F,0xE3,0x1E,0xE3,0x1C,0xE7,0x1C,0xC6,0x39,0xCE,0x31,0x9C,0x63,
  0xE3,0x1F,0xC7,0x3F,0x87,0x7F,0x8E,0x7E,0x1E,0xFE,0x1D,0xFC,0x39,0xF8,0x79,0xF8,
  0xF8,0x87,0xF1,0x8F,0xD1,0x0E,0xE3,0x1E,0xE3,0x1E,0xE7,0x1E,0xE7,0x1E,0xC7,0x3E,
  0xE6,0x1E,0xE6,0x1E,0xE7,0x1C,0xC7,0x3C,0xC6,0x39,0xCE,0x31,0x9C,0x63,0xF8,0x07,
  0x3D,0x02,0x3F,0x00,0x7E,0x01,0x78,0x87,0x70,0x8F,0x71,0x8F,0x73,0xCE,0x7F,0xC0,
  0xC7,0x3E,0x07,0xFC,0x1F,0xEC,0x36,0xCF,0x60,0x9C,0xE2,0x1E,0xC7,0x3F,0x87,0x7F,
  0x1C,0xE3,0x38,0xC7,0x78,0x87,0x71,0x8E,0xF1,0x0E,0xE3,0x1C,0xE6,0x19,0x7C,0x03,
  0x3E,0xE1,0x7F,0xE0,0xFF,0x00,0xBC,0x43,0xB8,0x47,0x38,0xC7,0x19,0xE7,0x3F,0xE0,
  0xE3,0x1F,0x83,0x7F,0x0F,0xF6,0x1B,0xE7,0x31,0xCE,0xF1,0x8E,0xE3,0x1E,0xC3,0x3E,
  0x67,0x18,0xE7,0x18,0x87,0x78,0xFD,0x04,0xC7,0x38,0xC7,0x38,0x8F,0x70,0xFE,0x01,
  0xE0,0xE0,0x40,0xC0,0x30,0xC0,0x70,0x88,0xE0,0x1C,0xC2,0x3E,0x87,0x7F,0x0F,0xFF,
  0x7B,0x04,0x7F,0x00,0x7E,0x01,0x3C,0x03,0x00,0x1F,0x00,0x0F,0x07,0x07,0x03,0x03,
  0x87,0x7C,0x0F,0xFC,0x1F,0xFE,0x3C,0xFC,0x78,0xF8,0xF0,0xF0,0xE0,0xE0,0xC0,0xC0,
  0xB8,0x47,0xF0,0x0F,0xC1,0x3F,0x03,0xFF,0x0F,0x7F,0x3F,0x3F,0x1C,0x1C,0x00,0x00,
  0x71,0xF0,0xE0,0xE0,0xE0,0xE0,0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
  0xC6,0x3E,0x0E,0xFE,0x0E,0x7E,0x3C,0x3C,0x1C,0x1C,0x00,0x00,0x00,0x00,0x3F,0x00,
  0xE0,0x1F,0x01,0x7F,0x07,0x3F,0x1F,0x1F,0x0E,0x0E,0x00,0x00,0x00,0x00,0xC0,0x00,
  0xEE,0xF1,0xE0,0xEF,0xC4,0xC7,0x83,0x83,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x0E,0xFE,0x1E,0xFE,0x7C,0xFC,0xF8,0xF8,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,
  0x78,0x07,0x00,0x3F,0x01,0x1F,0x0F,0x0F,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00,
  0x77,0xF8,0xF0,0xF7,0xE2,0xE3,0xC1,0xC1,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
  0x07,0xFF,0x0F,0xFF,0x3E,0xFE,0xFC,0xFC,0x70,0x70,0x00,0x00,0x00,0x00,0x00,0x00,
  0x78,0x07,0x00,0x7F,0x01,0x3F,0x1F,0x1F,0x0F,0x0F,0x00,0x00,0x00,0x00,0x01,0x00,
  0x1E,0xFE,0x7C,0xFC,0xF8,0xF8,0xE3,0xE0,0x8F,0x80,0x3E,0x01,0xF8,0x07,0xF0,0x0F,
  0x00,0x00,0x00,0x00,0x1E,0x00,0xFF,0x00,0xC0,0x3F,0x00,0xFF,0x0F,0xFF,0x7F,0xFF,
  0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x00,0xF0,0x00,0x38,0xC0,0xDF,0xE0,0xFB,0x80,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x00,0xFF,0x00,0xFF,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0xE0,0x00,
  0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x03,0x00,0x03,0x00,0x07,0x00,0x06,0x01,
  0x40,0x00,0xEC,0x00,0xBE,0x00,0xB6,0x49,0xFF,0x00,0x6B,0x90,0x6E,0x91,0x44,0xBB,
  0x00,0x00,0x24,0x00,0x6C,0x12,0x7C,0x03,0xD8,0x27,0xF8,0x07,0xF1,0x0F,0x71,0x8F,
  0x00,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x83,0x80,0xC7,0xC0,0xC7,0xC0,0xC7,0xC0,
  0xFF,0x00,0xC0,0x3F,0x80,0x7F,0x8F,0x7F,0x1F,0xFF,0x1C,0xFC,0x38,0xF8,0x38,0xF8,
  0xF8,0x00,0x3F,0xC0,0x07,0xF8,0xF0,0xFF,0xFF,0xFE,0x03,0x00,0x0F,0x00,0x1E,0x01,
  0x00,0x00,0x00,0x00,0xCF,0x00,0xFE,0x01,0xFE,0x01,0xCF,0x30,0x83,0x7C,0x0C,0xFF,
  0x00,0x00,0x00,0x00,0xFC,0x00,0x0F,0xB0,0x01,0xFE,0xFC,0x7F,0xFF,0x0F,0x7F,0x80,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0xC0,0x00,0xC0,0x20,0xC0,0x30,
  0x03,0x00,0x07,0x00,0x0F,0x00,0x1E,0x01,0x3C,0x03,0x70,0x07,0xF0,0x0F,0xF1,0x0F,
  0xC1,0x3F,0x83,0x7F,0x0F,0xFF,0x1F,0xFF,0x3E,0xFC,0x7B,0xF8,0xF3,0xF0,0xE1,0xE0,
  0xFD,0xFC,0xE3,0xE0,0x83,0x80,0x07,0x00,0x0E,0x01,0x0E,0x01,0x8C,0x03,0xFF,0x00,
  0xFC,0x03,0xCC,0x33,0x8C,0x73,0x0C,0xF3,0x1C,0xE3,0x3C,0xC3,0x78,0x87,0xF0,0x0F,
  0x07,0xF8,0x00,0xFF,0xFE,0xFF,0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,
  0xF0,0x00,0xF8,0x00,0x7C,0x80,0xFC,0x82,0x7E,0x41,0x3A,0x01,0x1E,0x01,0x1E,0x01,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x40,0xC0,0x40,0xC0,
  0x00,0x03,0x00,0x01,0x03,0x00,0x07,0x00,0x06,0x01,0x06,0x01,0x03,0x00,0x01,0x00,
  0x04,0xFF,0xEE,0x1F,0xFF,0x0E,0x1D,0xE4,0x03,0xFC,0x3E,0xF1,0xFC,0x03,0xF0,0x0F,
  0x63,0x9F,0xE3,0x1F,0xC7,0x3F,0x87,0x7F,0x0E,0xFE,0x1E,0xFE,0x3C,0xFC,0x78,0xF8,
  0x87,0x80,0x87,0x80,0x07,0x00,0x03,0x00,0x03,0x00,0x01,0x00,0x00,0x00,0x00,0x00,
  0x30,0xF0,0x30,0xF0,0x31,0xF0,0x33,0xF0,0xB3,0x70,0xF7,0x10,0xF9,0x00,0x79,0x00,
  0x7C,0x03,0xF8,0x07,0xF0,0x0F,0xED,0x13,0xCD,0x33,0xF8,0x07,0xF0,0x0F,0xE1,0x1F,
  0x1F,0xFF,0x7C,0xFC,0xF8,0xF8,0xE0,0xE0,0xC0,0xC0,0x80,0x80,0x80,0x80,0xC0,0xC0,
  0x07,0xF8,0xE0,0xFF,0x3E,0x3F,0x07,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x88,0x78,0x0C,0xFC,0x1C,0xFC,0xFC,0xFC,0x78,0x78,0x00,0x00,0x00,0x00,0x00,0x00,
  0x01,0x00,0x03,0x00,0x07,0x00,0x07,0x00,0x0F,0x00,0x1F,0x00,0x16,0x01,0x3C,0x03,
  0xE3,0x1F,0xC3,0x3F,0xC7,0x3F,0x8F,0x7F,0x0E,0xFE,0x1C,0xFC,0x3C,0xFC,0x38,0xF8,
  0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xFB,0x00,0x1F,0x60,0x0F,0x30,0x1F,0x18,0x0F,0x0C,0x00,0x01,0x00,0x00,0x00,0x00,
  0xC1,0x3F,0x03,0xFF,0x0F,0xFE,0xFF,0x00,0xFF,0x00,0x60,0x9F,0x00,0xFF,0x67,0x7F,
  0xF0,0xC0,0xE0,0x98,0xE0,0x1C,0x86,0x7E,0x07,0xFF,0x1E,0xFE,0x3E,0xFE,0xF8,0xF8,
  0x1E,0x01,0x1E,0x01,0x1E,0x01,0x1E,0x01,0x3C,0x03,0x3C,0x03,0x78,0x07,0xF0,0x0F,
  0x60,0xE0,0x60,0xE0,0x60,0xE0,0x60,0xE0,0x60,0xE0,0x60,0xE0,0xE0,0xE0,0xE0,0xE0,
  0x00,0xFF,0x03,0x7F,0x3F,0x3F,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xF0,0xF0,0xE0,0xE0,0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x1F,0x20,0x1E,0x01,0x1E,0x01,0x3E,0x01,0x3C,0x03,0x3C,0x03,0x3C,0x03,0x38,0x07,
  0x03,0xFF,0x07,0xFF,0x3F,0xFF,0x7E,0xFE,0x70,0xF0,0x60,0xE0,0xE0,0xE0,0xE0,0xE0,
  0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x03,0x00,0x07,0x00,0x07,0x00,0x0F,0x00,
  0x1C,0x00,0x7F,0x00,0xF7,0x08,0xC7,0x38,0x87,0x78,0x8F,0x78,0x1F,0xF8,0x1F,0xF0,
  0x00,0x00,0x60,0x00,0x60,0x10,0x40,0x38,0xC4,0x3C,0x8F,0x7E,0x8F,0x7E,0x1F,0xFC,
  0x3C,0x03,0x7F,0x00,0x7D,0x02,0xF8,0x07,0xF1,0x0E,0xA3,0x1C,0x8F,0x30,0xFC,0x03,
  0x70,0xF0,0xF0,0x10,0xF0,0x00,0xF0,0x08,0xE0,0x1C,0xC2,0x3E,0x07,0xFF,0x0F,0xFF,
  0x00,0x00,0x03,0x00,0x0F,0x00,0x1E,0x01,0x3C,0x03,0x79,0x06,0xFF,0x00,0xDE,0x01,
  0x00,0x00,0xC0,0x00,0xC0,0x20,0xC0,0x30,0xC8,0x38,0xCC,0x3C,0x8C,0x7C,0x0C,0xFC,
  0x3F,0x3F,0x06,0x06,0x00,0x00,0x00,0x00,0x01,0x00,0x07,0x00,0x1F,0x00,0x3C,0x03,
  0xF0,0xF0,0x03,0x00,0x07,0x00,0x3F,0x00,0xFC,0x03,0xF0,0x0F,0x00,0xFF,0x03,0xFF,
  0xE1,0x1F,0xC3,0x3F,0x87,0x7F,0x0F,0xFF,0x1E,0xFE,0x3C,0xFC,0xF8,0xF8,0xF0,0xF0,
  0xC0,0xC0,0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x38,0x07,0x39,0x07,0x39,0x07,0x39,0x07,0x1D,0x03,0x1D,0x03,0x0E,0x01,0x07,0x00,
  0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x80,
  0x00,0x00,0x01,0x00,0x03,0x00,0x07,0x00,0x0E,0x01,0x1C,0x03,0x38,0x07,0xF0,0x0F,
  0x0E,0x01,0x8E,0x01,0x0E,0xC1,0x0C,0xE3,0x3C,0xF3,0x3E,0xF1,0x77,0xF0,0xF0,0xF3,
  0x3B,0xF0,0x3E,0xE1,0x7E,0xE1,0x7C,0xC3,0x7C,0x83,0xFD,0x02,0x5F,0x20,0x0E,0xF1,
  0x1F,0xE4,0x33,0xCC,0x37,0xC8,0x66,0x98,0xC7,0x38,0xC7,0x38,0x8F,0x7C,0x0E,0xFF,
  0xF0,0x0F,0xE0,0x1F,0xE3,0x1F,0xF7,0x0F,0x7F,0x87,0x3E,0xC0,0xAF,0x70,0xB7,0x78,
  0x3E,0xFC,0xFF,0xF8,0xF7,0xF0,0xCD,0xC2,0x1D,0x02,0x78,0x07,0xF0,0x0F,0xC1,0x3F,
  0x9C,0x03,0xD0,0x0F,0xE0,0x1F,0xC3,0x3F,0xC7,0x3E,0xEF,0x1C,0xFE,0x01,0xB8,0xC7,
  0x3C,0xCC,0x64,0x9C,0xE0,0x9C,0xC6,0x3E,0x87,0x7F,0x0F,0xFC,0x1F,0xFC,0x3F,0xFC,
  0x38,0x07,0x70,0x0F,0x61,0x1F,0x03,0x3F,0x07,0x1F,0x8F,0x0F,0x86,0x46,0x80,0x60,
  0x3F,0xFF,0xFF,0xFF,0xF0,0xF0,0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
  0xC0,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,
  0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x18,0x00,0x2C,0x00,0x2C,0x20,0x4E,0x08,0x46,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,
  0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xC7,0x00,0xFF,0x00,0x00,0xFF,0x40,0x7F,0x3F,0x3F,0x0F,0x0F,0x00,0x00,0x00,0x00,
  0xC1,0x3F,0x03,0xFF,0x0F,0xFF,0x3F,0xFF,0xFC,0xFC,0xF0,0xF0,0x00,0x00,0x00,0x00,
  0xE0,0xE1,0xC0,0xC0,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x08,0xFF,0xFC,0xFF,0x7D,0x7D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x1C,0xFC,0x7C,0xFC,0xF8,0xF8,0xE0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x14,0xF7,0x52,0x73,0x38,0x38,0x08,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x03,0xFF,0x0F,0xFF,0xFF,0xFF,0x7C,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0xC0,0xFF,0x91,0x9F,0x0F,0x0F,0x03,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x79,0xF8,0xF3,0xF0,0xE2,0xE1,0x80,0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x10,0xF0,0x18,0xF8,0x38,0xF8,0x38,0xF8,0x70,0xF0,0x70,0x70,0x20,0x20,0x00,0x00,
  0x00,0x18,0x10,0x08,0x00,0x28,0x00,0x28,0x00,0x29,0x30,0x49,0x10,0x49,0x51,0x8A,
  0x08,0x46,0x48,0x87,0x08,0x87,0x0C,0x83,0x8C,0x03,0x0C,0x03,0x0C,0x03,0x04,0x03,
  0x00,0x18,0x00,0x18,0x00,0x1C,0x00,0x1C,0x00,0x9C,0x08,0x96,0x08,0x96,0x0C,0xD3,
  0x00,0x00,0x00,0x01,0x00,0x01,0x01,0x06,0x00,0x1A,0x00,0x3B,0x00,0x7C,0x00,0xFF,
  0x10,0x8A,0x9A,0x04,0x1C,0x00,0x0C,0x00,0x04,0x00,0x00,0xC0,0x00,0x38,0x00,0xC7,
  0x06,0x39,0x2A,0x45,0x12,0x45,0x13,0x44,0x2B,0x44,0x03,0x38,0x01,0x00,0x00,0xFF,
  0x0C,0xD3,0x0C,0xF3,0x0E,0xF1,0x1F,0xE0,0xFF,0x00,0xFC,0x03,0xE3,0x1C,0x1C,0xE3,
  0x00,0x00,0x00,0x80,0x00,0x80,0x80,0x60,0xA0,0x58,0x20,0xDC,0xC0,0x3E,0x00,0xFF,
  0x00,0x01,0x00,0x01,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x07,0x00,0x0F,0x00,0x0F,
  0x02,0xFD,0x04,0xF9,0x2A,0xD1,0x05,0xC0,0x48,0x84,0x11,0x8C,0x22,0x9D,0x48,0xBF,
  0x00,0xF8,0x22,0xDD,0x91,0x40,0x22,0x40,0x95,0x62,0x08,0xF7,0x90,0xFF,0x94,0xFF,
  0x00,0x00,0x5A,0xA5,0x00,0xA5,0xA5,0x00,0x5A,0x00,0xA5,0x5A,0x80,0xFF,0xA2,0xFF,
  0x60,0x1F,0x44,0xBB,0x89,0x02,0x44,0x02,0xA9,0x46,0x10,0xEF,0x80,0xFF,0xAA,0xFF,
  0x40,0xBF,0x28,0x97,0x54,0x83,0xA0,0x03,0x12,0x21,0x88,0x31,0x44,0xB9,0x12,0xFD,
  0x00,0x80,0x00,0x80,0x00,0xC0,0x00,0xC0,0x00,0xC0,0x00,0xE0,0x80,0xF0,0xC0,0xF0,
  0x00,0x0F,0x00,0x1F,0x04,0x3B,0x02,0x39,0x01,0x18,0x00,0x1C,0x00,0x0C,0x00,0x0C,
  0x1F,0xFF,0x8E,0x7F,0x50,0x2F,0x04,0x2B,0x28,0x03,0x00,0x02,0x01,0x02,0x00,0x02,
  0x18,0xF1,0x56,0xE6,0x55,0xF5,0x4F,0xBF,0xD5,0x2A,0x77,0x08,0x04,0x08,0x84,0x00,
  0xAA,0xFF,0xAB,0xFF,0x2A,0x7E,0x6A,0x95,0xE7,0x00,0xC3,0x00,0x00,0x18,0x18,0x24,
  0x9A,0x8F,0x6A,0x67,0xAA,0xAF,0xF2,0xFD,0x57,0xA8,0x76,0x88,0x84,0x08,0x09,0x00,
  0x74,0xFF,0x71,0xFE,0x4A,0xF4,0x60,0xD4,0x54,0xC0,0x40,0x40,0x80,0x40,0x00,0x40,
  0x80,0xF0,0x00,0xF8,0x20,0xDC,0x40,0x9C,0x80,0x18,0x00,0x38,0x00,0x30,0x00,0x30,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x07,
  0x00,0x0C,0x01,0x1C,0x02,0x1D,0x00,0x1F,0x03,0x3F,0x03,0xFF,0x06,0xFF,0x06,0xEF,
  0x80,0x02,0x28,0x82,0x11,0xAA,0x44,0xBB,0x20,0xFF,0xFA,0xFF,0xC2,0xFF,0x08,0xE7,
  0x80,0x00,0x0C,0x00,0x1E,0x00,0x9E,0x00,0x9E,0x00,0x0C,0x80,0x00,0x80,0x40,0x80,
  0x3C,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x30,0x7E,0x00,0x81,0x3C,0x00,
  0x01,0x00,0x30,0x00,0x79,0x00,0x79,0x00,0x79,0x00,0x30,0x01,0x00,0x01,0x03,0x01,
  0x01,0x40,0x14,0x41,0x88,0x55,0x22,0xDD,0x04,0xFF,0x8F,0xFF,0x85,0xFF,0x90,0xE7,
  0x00,0x30,0x80,0x38,0x40,0xB8,0x20,0xF8,0xF0,0xFC,0xF0,0xFF,0x40,0xFF,0x00,0xF7,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x00,0xE0,
  0x00,0x00,0x00,0x00,0x19,0x19,0x22,0x22,0x22,0x22,0x19,0x19,0x00,0x00,0x00,0x00,
  0x02,0x02,0x02,0x02,0x8A,0x8E,0x56,0x52,0x52,0x52,0x8C,0x8C,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x68,0x48,0xA0,0xA0,0x80,0xC0,0x68,0x68,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x6C,0x6C,0x82,0x86,0x8A,0x8A,0x6C,0x66,0x00,0x00,0x00,0x00,
  0x84,0x84,0x84,0x84,0xA5,0xE7,0xD6,0x94,0x94,0x94,0x63,0x63,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x31,0x31,0x8A,0x9A,0xAA,0xAA,0x31,0x19,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x8C,0x88,0x54,0x54,0xD0,0x58,0xCC,0xCC,0x40,0x40,0x80,0x80,
  0x03,0x07,0x02,0x0F,0x06,0x0F,0x05,0x1E,0x00,0x1E,0x04,0x1E,0x04,0x1E,0x04,0x1E,
  0x00,0xCE,0x10,0x8E,0x00,0x12,0x00,0x00,0x40,0x00,0x00,0x40,0x92,0x40,0x05,0xD2,
  0x00,0xE3,0x00,0x61,0x05,0x00,0x48,0x04,0x92,0x0C,0x25,0x9E,0x56,0xBF,0x13,0xFF,
  0xA0,0xC0,0xD0,0xE0,0xC8,0xF0,0xEC,0xF0,0x2E,0xF0,0x67,0xF0,0x63,0xF0,0xA1,0x70,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x81,0x00,0xE7,0x00,0xFF,0x00,
  0x05,0x03,0x0B,0x07,0x16,0x0F,0x36,0x0F,0x7E,0x0F,0xEE,0x0F,0xCE,0x0F,0x81,0x0E,
  0x80,0xC7,0x00,0x86,0xA0,0x00,0x12,0x20,0x49,0x30,0x84,0x79,0x32,0xFD,0x38,0xFF,
  0x00,0x73,0x08,0x71,0x00,0x48,0x00,0x00,0x02,0x00,0x00,0x02,0x49,0x02,0xA0,0x4B,
  0x00,0xE0,0x40,0xF0,0x60,0xF0,0xA0,0x78,0x20,0x78,0x30,0x78,0x30,0x78,0x30,0x78,
  0x00,0x00,0x00,0x00,0x66,0x67,0x95,0x94,0xB4,0x94,0x74,0x74,0x10,0x10,0x20,0x20,
  0x00,0x00,0x00,0x00,0x65,0x67,0x16,0x34,0x54,0x54,0x67,0x37,0x04,0x04,0x04,0x04,
  0x21,0x21,0x20,0x20,0x29,0x39,0xB5,0xA5,0xA5,0xA5,0x25,0x25,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x33,0x33,0x44,0x46,0x43,0x41,0x36,0x36,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x43,0x43,0x04,0x04,0x05,0x04,0x43,0x43,0x00,0x00,0x01,0x01,
  0x00,0x00,0x00,0x00,0x33,0x32,0xA5,0xA5,0xA4,0xA6,0xA3,0xA3,0x80,0x80,0x00,0x00,
  0x0A,0x0A,0x0A,0x0A,0x2A,0x3A,0x5A,0x4A,0x4A,0x4A,0x32,0x32,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x6C,0x4E,0xAA,0xA8,0x88,0xC8,0x68,0x68,0x00,0x00,0x00,0x00,
  0x01,0x1E,0x00,0x0F,0x00,0x07,0x00,0x0F,0x06,0x1F,0x1E,0x3F,0x3F,0x7F,0x7F,0xFF,
  0x28,0xD7,0x0A,0xFF,0x49,0xFE,0x50,0xEE,0x0A,0xE4,0x14,0xE0,0x0A,0xF0,0x05,0xF8,
  0x44,0xFB,0x61,0xDA,0x0A,0xD0,0xD0,0x00,0x81,0x00,0x45,0x00,0x32,0x04,0x89,0x36,
  0x00,0x70,0x00,0x70,0x10,0x60,0x20,0x40,0x2E,0x40,0x9F,0x60,0x83,0x7C,0x00,0xE3,
  0xFF,0x00,0x7E,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC3,0x00,0x3C,0xC3,
  0x00,0x0E,0x00,0x0E,0x08,0x06,0x04,0x02,0x7C,0x02,0xF9,0x06,0xC1,0x3E,0x00,0xC7,
  0x29,0xDF,0x84,0x5B,0x50,0x0B,0x0B,0x00,0x81,0x00,0xA2,0x00,0x4C,0x20,0x91,0x6C,
  0x14,0xEB,0x00,0xFF,0xA3,0x7F,0x08,0x77,0x50,0x27,0x2B,0x07,0x56,0x0F,0xA0,0x1F,
  0x80,0x78,0x00,0xF0,0x00,0xE0,0x00,0xF0,0x60,0xF8,0x78,0xFC,0xFC,0xFE,0xFE,0xFF
};
