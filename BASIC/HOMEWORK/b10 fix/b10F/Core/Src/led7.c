#include "led7.h"

uint8_t LED7_HEX[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
//////////////////////////////////
void LED7_WriteByte(uint8_t b);

void LED7_WriteByte(uint8_t b)
{
  if (((b >> 0) & 0x01) == 1) { A_SET(); } else { A_RESET(); }
  if (((b >> 1) & 0x01) == 1) { B_SET(); } else { B_RESET(); }
  if (((b >> 2) & 0x01) == 1) { C_SET(); } else { C_RESET(); }
  if (((b >> 3) & 0x01) == 1) { D_SET(); } else { D_RESET(); }
  if (((b >> 4) & 0x01) == 1) { E_SET(); } else { E_RESET(); }
  if (((b >> 5) & 0x01) == 1) { F_SET(); } else { F_RESET(); }
  if (((b >> 6) & 0x01) == 1) { G_SET(); } else { G_RESET(); }
  if (((b >> 7) & 0x01) == 1) { DP_SET(); } else { DP_RESET(); }
}

void LED7_Number(uint8_t num)
{
  LED7_WriteByte(LED7_HEX[num]);
}
////////////////////////////////////////
void LED7A_WriteByte(uint8_t c);

void LED7A_WriteByte(uint8_t c)
{
  if (((c >> 0) & 0x01) == 1) { A1_SET(); } else { A1_RESET(); }
  if (((c >> 1) & 0x01) == 1) { B1_SET(); } else { B1_RESET(); }
  if (((c >> 2) & 0x01) == 1) { C1_SET(); } else { C1_RESET(); }
  if (((c >> 3) & 0x01) == 1) { D1_SET(); } else { D1_RESET(); }
  if (((c >> 4) & 0x01) == 1) { E1_SET(); } else { E1_RESET(); }
  if (((c >> 5) & 0x01) == 1) { F1_SET(); } else { F1_RESET(); }
  if (((c >> 6) & 0x01) == 1) { G1_SET(); } else { G1_RESET(); }
  if (((c >> 7) & 0x01) == 1) { DP1_SET(); } else { DP1_RESET(); }
}
void LED7A_Number(uint8_t num)
{
  LED7A_WriteByte(LED7_HEX[num]);
}