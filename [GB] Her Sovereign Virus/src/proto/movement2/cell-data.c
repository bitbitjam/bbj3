
#define NBSFRAMES 0x08                  /* Nb frames for the sprite */

/*
 * Image size: 0x10 x 0x80
 * Number of tiles (total - unique): 0x1E - 0x1C
 */
const unsigned char fmri_tiles[] ={
  0x22,0x24,
  0x26,0x28,
  0x2a,0x2c,
  0x2e,0x30,
  0x32,0x34,
  0x36,0x38,
  0x3a,0x3c,
  0x3e,0x40
};

const unsigned char cell_data[] ={
  //// fMRI
  // Bottom
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
  0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  // 
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x01,0x07,0x03,0x07,
  0x03,0x07,0x01,0x07,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x80,0xE0,0xC0,0xE0,
  0xC0,0xE0,0x80,0xE0,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  //
  0x00,0x00,0x00,0x00,0x00,0x03,0x01,0x0F,0x07,0x1F,0x0F,0x1F,0x0F,0x3E,0x1F,0x3D,
  0x1F,0x3D,0x0F,0x3E,0x0F,0x1F,0x07,0x1F,0x01,0x0F,0x00,0x03,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0xC0,0x80,0xF0,0xE0,0xF8,0xF0,0xF8,0xF0,0x7C,0xF8,0xBC,
  0xF8,0xBC,0xF0,0x7C,0xF0,0xF8,0xE0,0xF8,0x80,0xF0,0x00,0xC0,0x00,0x00,0x00,0x00,
  // Bottom-Center
  0x00,0x07,0x03,0x1F,0x0F,0x3F,0x1F,0x7F,0x3F,0x77,0x3F,0xF9,0x7F,0xFA,0x7F,0xFC,
  0x7F,0xFC,0x7F,0xFA,0x3F,0xF9,0x3F,0x77,0x1F,0x7F,0x0F,0x3F,0x03,0x1F,0x00,0x07,
  0x00,0xE0,0xC0,0xF8,0xF0,0xFC,0xF8,0xFE,0xFC,0xEE,0xFC,0x9F,0xFE,0x5F,0xFE,0x3F,
  0xFE,0x3F,0xFE,0x5F,0xFC,0x9F,0xFC,0xEE,0xF8,0xFE,0xF0,0xFC,0xC0,0xF8,0x00,0xE0,
  // Top-Center
  0x00,0x07,0x03,0x1F,0x0F,0x3E,0x1F,0x63,0x3F,0x60,0x3F,0xE1,0x7F,0xF0,0x7F,0xD4,
  0x7F,0xD4,0x7F,0xF0,0x3F,0xE1,0x3F,0x60,0x1F,0x63,0x0F,0x3E,0x03,0x1F,0x00,0x07,
  0x00,0xE0,0xC0,0xF8,0xF0,0x7C,0xF8,0xC6,0xFC,0x06,0xFC,0x87,0xFE,0x0F,0xFE,0x2F,
  0xFE,0x2B,0xFE,0x0F,0xFC,0x87,0xFC,0x06,0xF8,0xC6,0xF0,0x7C,0xC0,0xF8,0x00,0xE0,
  //
  0x00,0x00,0x00,0x00,0x00,0x03,0x01,0x0E,0x07,0x18,0x0F,0x11,0x0F,0x30,0x1F,0x24,
  0x1F,0x24,0x0F,0x30,0x0F,0x11,0x07,0x18,0x01,0x0E,0x00,0x03,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0xC0,0x80,0x70,0xE0,0x18,0xF0,0x88,0xF0,0x0C,0xF8,0x24,
  0xF8,0x24,0xF0,0x0C,0xF0,0x88,0xE0,0x18,0x80,0x70,0x00,0xC0,0x00,0x00,0x00,0x00,
  //
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x01,0x06,0x03,0x04,
  0x03,0x04,0x01,0x06,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x80,0x60,0xC0,0x20,
  0xC0,0x20,0x80,0x60,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  // Top
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
  0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
  0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
