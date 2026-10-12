typedef struct  
{ 
int va; 
int vpn; 
int offset; 
int pageFault; // 1 = fault, 0 = hit 
} TraceEntry; 
