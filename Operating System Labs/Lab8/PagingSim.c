#include <stdio.h> 
#include <stdlib.h> 
#define PAGE_SIZE 256 
#define NUM_PAGES 16 
#define NUM_FRAMES 8 
// Each process has a page table mapping virtual pages to physical frames. 
typedef struct { 
    int frameNumber; 
    int valid; // The valid flag simulates page presence. 
    } PageTableEntry;

typedef struct { 
  PageTableEntry pageTable[NUM_PAGES]; 
  int pid; 
  } Process; 

int framePool[NUM_FRAMES]; // -1 = free frame 
// Initialize the Process 
void initialize(Process* p, int pid) { 
  p->pid = pid; 
    
  for (int i = 0; i < NUM_PAGES; i++) { 
    p->pageTable[i].valid = 0; // Mark all pages as invalid. 
  } 
} 
// Initialize the Frame Pool 
void initializeFramePool() { 
  for (int i = 0; i < NUM_FRAMES; i++) { 
  framePool[i] = -1;  // -1 indicates a free frame. 
  } 
}

int translate(Process* p, int virtualAddress){
  int vpn = virtualAddress /PAGE_SIZE;
  int offset = virtualAddress % PAGE_SIZE;
   if (vpn < 0 || vpn >= NUM_PAGES) {
        return -1;
    }
    if (p->pageTable[vpn].valid == 0) {
        return -1;
    }
    return p->pageTable[vpn].frameNumber * PAGE_SIZE + offset;
 }

void allocatePage(Process* p, int vpn, int frame)  { 
    // Map the virtual page to the physical frame 
    p -> pageTable[vpn].frameNumber = frame; 
    // Mark the entry as valid (the room is now prepared and occupied) 
    p -> pageTable[vpn].valid = 1; 
    // Update the global frame pool to record which process owns this room 
    framePool[frame] = p -> pid; 
}

displayPageTable(Process* p){
    for (int i = 0; i < NUM_PAGES; i++){
        if (p->pageTable[i].valid == 1) {
            printf("VPN %d -> Frame %d\n", i, p->pageTable[i].frameNumber);
        } else {
            printf("VPN %d -> INVALID\n", i);
        }
    }
}
