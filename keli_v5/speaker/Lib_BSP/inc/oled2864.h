//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
//  UG-2864HSWEG01 (2864-46p) Reference Code
//
//    Dot Matrix: 128*64
//    Driver IC : SSD1306 (Solomon Systech)
//    Interface : 8-bit 68XX/80XX Parallel, 3-/4-wire SPI
//    Revision  :
//    Date      : 2009/06/05
//    Author    :
//    Editor    : Humphrey Lin
//
//  Copyright (c) Univision Technology Inc.
//
//=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=


void uDelay(unsigned char l);
void Delay(unsigned char n);
void delay_1us(void);
void Write_Command(unsigned char Data);
void Write_Data(unsigned char Data);
void Set_Start_Column(unsigned char d);
void Set_Addressing_Mode(unsigned char d);
void Set_Column_Address(unsigned char a, unsigned char b);
void Set_Page_Address(unsigned char a, unsigned char b);
void Set_Start_Line(unsigned char d);
void Set_Contrast_Control(unsigned char d);
void Set_Charge_Pump(unsigned char d);
void Set_Segment_Remap(unsigned char d);
void Set_Entire_Display(unsigned char d);
void Set_Inverse_Display(unsigned char d);
void Set_Multiplex_Ratio(unsigned char d);
void Set_Display_On_Off(unsigned char d);	
void Set_Start_Page(unsigned char d);
void Set_Common_Remap(unsigned char d);
void Set_Display_Offset(unsigned char d);
void Set_Display_Clock(unsigned char d);
void Set_Precharge_Period(unsigned char d);
void Set_Common_Config(unsigned char d);
void Set_VCOMH(unsigned char d);
void Set_NOP(void);
void Fill_RAM(unsigned char Data);
void OLED_ClearScreen(void);
void Fill_Block(unsigned char Data, unsigned char a, unsigned char b, unsigned char c, unsigned char d);
void Checkerboard(void);
void Frame(void);
void Show_Font57(unsigned char a, unsigned char b, unsigned char c, unsigned char d);
void Show_String(unsigned char a, unsigned char *Data_Pointer, unsigned char b, unsigned char c);
void Show_Pattern(unsigned char *Data_Pointer, unsigned char a, unsigned char b, unsigned char c, unsigned char d);
void OLED_DisChar(uint8_t Line, uint16_t Column, uint8_t Color, uint8_t Ascii);
void OLED_DisStrLine(uint8_t Line, uint8_t Color, uint8_t *ptr);
void Vertical_Scroll(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e);
void Horizontal_Scroll(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e);
void Continuous_Scroll(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f, unsigned char g, unsigned char h);
void Deactivate_Scroll(void);
void Fade_In(void);
void Fade_Out(void);
void Sleep(unsigned char a);
void Test(void);
void OLED_Init_E(void);
void OLED_Init_I(void);
void OLED_Test(void);



