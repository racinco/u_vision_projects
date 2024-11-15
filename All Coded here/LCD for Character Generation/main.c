# include <reg51.h>
# include <delay8051.h>

sbit RS = P1^0;
sbit RW = P1^1;
sbit EN = P1^2;

void lcd_write(unsigned char val)
{
	P2 = val;
	RW = 0;
	EN = 1;
	delay_ms(2);
	EN = 0; 	
}
void lcd_data(unsigned char _data)
{
	RS = 1;
	lcd_write(_data);
}

void lcd_cmd(unsigned char cmd)
{
	RS = 0;
	lcd_write(cmd);
}


void lcd_init(){
	lcd_cmd(0x01);
	lcd_cmd(0x02);
	lcd_cmd(0x06);
	lcd_cmd(0x80);
	lcd_cmd(0x0c);
	lcd_cmd(0x38);
}
code cgram_lut[] = {
0x10,0x18,0x1c,0x1e,0x1e,0x1c,0x18,0x10,
0x00,0x00,0x00,0x0e,0x0e,0x00,0x00,0x00,
0x00,0x0e,0x1f,0x1f,0x1f,0x1f,0x0e,0x00,
0x00,0x04,0x0e,0x0e,0x0e,0x04,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

void build_cgram()
{
		char i;
		lcd_cmd(0x40);
		
		for(i=0;i<32;i++)
		lcd_data(cgram_lut[i]);
			
		lcd_cmd(0xc0);
}

void lcd_string(char *s)
{
	while(*s)
	{
			lcd_data(*s++);
	}
}

void lcd_integer(int num)
{
	char buf[10],i=0;
	if(num==0)
	{
		lcd_data('0');
		return;
	}
	if(num<0)
	{
		lcd_data('-');
		num=-num;
	}
	while(num)
	{
		buf[i++]=num%10+48;
		num=num/10;
	}
	
	for(--i;i>=0;i--)
	{
		lcd_data(buf[i]);
	}
}

int lcd_atoi(char*p)
{
	int num=0,i;
	
	for(i=0;p[i];i++)
	{
		num = num * 10 + p[i] - 48;
	}
	return num;
}

void main(){
	P1 =0; 
	P2 = 0; 
	lcd_init(); 
	build_cgram(); 

}
