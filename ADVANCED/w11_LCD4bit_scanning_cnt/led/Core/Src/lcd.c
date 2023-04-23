#include "main.h"

void LCD_put(uint8_t ch) {
	HAL_GPIO_WritePin(LCDRS_GPIO_Port,LCDRS_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDD7_GPIO_Port,LCDD7_Pin,(GPIO_PinState)(ch&0x80));
	HAL_GPIO_WritePin(LCDD6_GPIO_Port,LCDD6_Pin,(GPIO_PinState)(ch&0x40));
	HAL_GPIO_WritePin(LCDD5_GPIO_Port,LCDD5_Pin,(GPIO_PinState)(ch&0x20));
	HAL_GPIO_WritePin(LCDD4_GPIO_Port,LCDD4_Pin,(GPIO_PinState)(ch&0x10));
	HAL_GPIO_WritePin(LCDE_GPIO_Port,LCDE_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port,LCDE_Pin,GPIO_PIN_RESET);
	HAL_Delay(1);	
	HAL_GPIO_WritePin(LCDD7_GPIO_Port,LCDD7_Pin,(GPIO_PinState)(ch&0x08));
	HAL_GPIO_WritePin(LCDD6_GPIO_Port,LCDD6_Pin,(GPIO_PinState)(ch&0x04));
	HAL_GPIO_WritePin(LCDD5_GPIO_Port,LCDD5_Pin,(GPIO_PinState)(ch&0x02));
	HAL_GPIO_WritePin(LCDD4_GPIO_Port,LCDD4_Pin,(GPIO_PinState)(ch&0x01));
	HAL_GPIO_WritePin(LCDE_GPIO_Port,LCDE_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port,LCDE_Pin,GPIO_PIN_RESET);
	HAL_Delay(1);	
}
void LCD_cmd(uint8_t ch) {
	HAL_GPIO_WritePin(LCDRS_GPIO_Port,LCDRS_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD7_GPIO_Port,LCDD7_Pin,(GPIO_PinState)(ch&0x80));
	HAL_GPIO_WritePin(LCDD6_GPIO_Port,LCDD6_Pin,(GPIO_PinState)(ch&0x40));
	HAL_GPIO_WritePin(LCDD5_GPIO_Port,LCDD5_Pin,(GPIO_PinState)(ch&0x20));
	HAL_GPIO_WritePin(LCDD4_GPIO_Port,LCDD4_Pin,(GPIO_PinState)(ch&0x10));
	HAL_GPIO_WritePin(LCDE_GPIO_Port,LCDE_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port,LCDE_Pin,GPIO_PIN_RESET);
	HAL_Delay(1);	
	HAL_GPIO_WritePin(LCDD7_GPIO_Port,LCDD7_Pin,(GPIO_PinState)(ch&0x08));
	HAL_GPIO_WritePin(LCDD6_GPIO_Port,LCDD6_Pin,(GPIO_PinState)(ch&0x04));
	HAL_GPIO_WritePin(LCDD5_GPIO_Port,LCDD5_Pin,(GPIO_PinState)(ch&0x02));
	HAL_GPIO_WritePin(LCDD4_GPIO_Port,LCDD4_Pin,(GPIO_PinState)(ch&0x01));
	HAL_GPIO_WritePin(LCDE_GPIO_Port,LCDE_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port,LCDE_Pin,GPIO_PIN_RESET);
	HAL_Delay(1);	
}
// STRING in C
// s[]="HCMUTE"
// s[0]='H'
// s[1]='C'
// s[2]='M'
// ...
// s[5] = 'E'
// s[6] = 0
void LCD_print(uint8_t *s){
	uint8_t i = 0;
	while (*(s+i) != 0) {
		LCD_put(*(s+i));
		i = i + 1;
	}
}

void LCD_CGRAM(uint8_t *s, uint8_t pos) {
	for (uint8_t i=0;i<8;i++) {
		LCD_cmd(0x40 + (pos<<3) + i);
		LCD_put(*(s+i));		
	}
}

void LCD_put4bit(uint8_t ch) {
	// 0B 0000 0000
	HAL_GPIO_WritePin(LCDRS_GPIO_Port,LCDRS_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LCDD7_GPIO_Port,LCDD7_Pin,(GPIO_PinState)(ch&0x08));
	HAL_GPIO_WritePin(LCDD6_GPIO_Port,LCDD6_Pin,(GPIO_PinState)(ch&0x04));
	HAL_GPIO_WritePin(LCDD5_GPIO_Port,LCDD5_Pin,(GPIO_PinState)(ch&0x02));
	HAL_GPIO_WritePin(LCDD4_GPIO_Port,LCDD4_Pin,(GPIO_PinState)(ch&0x01));	
	HAL_GPIO_WritePin(LCDE_GPIO_Port,LCDE_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LCDE_GPIO_Port,LCDE_Pin,GPIO_PIN_RESET);
	HAL_Delay(1);	
}

void LCD_init() {
		// LCD HD44780 Initilize begin
	HAL_Delay(15);
	// 0 0 1 1
	HAL_GPIO_WritePin(LCDRW_GPIO_Port,LCDRW_Pin,GPIO_PIN_RESET);
	LCD_put4bit(3);
	HAL_Delay(5);
	
	const uint8_t LCD_INIT_CODE[] = {3,3,2,2,8,0,8,0,1,0,6};
	for (uint8_t i=0;i<11;i++) {
		LCD_put4bit(LCD_INIT_CODE[i]);
	}
	// End of LCD initilize
}
