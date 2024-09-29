#include "system_def.h"
#include "mcal_std_types.h"

// Define masks for rows and columns
#define ROW_MASK  0x0F  // Assuming rows are connected to the lower 4 bits (P1.0 - P1.3)
#define COL_MASK  0xFF  // Assuming columns are connected to all 8 bits (P2.0 - P2.7)

void delay(uint16_t steps);
void delay_ms(uint16_t milliseconds);
void default_handler(void);
void nmi_handler(void);

