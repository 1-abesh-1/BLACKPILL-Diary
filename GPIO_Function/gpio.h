

#define PortA          0           
#define PortB          1           
#define PortC          2  
#define PortD          3 
#define PortE          4 
#define PortH          5



#define IN  0
#define OUT 1
#define AF	2
#define AN 	3



void gpio_init(char port);
void pinOutput(char port,char no);
void pin(char port,char no, char mode);
