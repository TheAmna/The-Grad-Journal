
#include <stdio.h> 
#include <stdlib.h> 
#define PAGE_SIZE 256 
#define NUM_PAGES 16 
#define NUM_FRAMES 8 
#define MAX_TRACE 100
TraceEntry trace[MAX_TRACE];
int traceCount = 0;
int framePool[NUM_FRAMES];
int frameVPN[NUM_FRAMES];
// Each process has a page table mapping virtual pages to physical frames. 
typedef struct { 
    int frameNumber; 
    int valid; // The valid flag simulates page presence. 
    } PageTableEntry;

typedef struct  
{ 
int va; 
int vpn; 
int offset; 
int pageFault; // 1 = fault, 0 = hit 
} TraceEntry; 

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

void findFreeFrame(){
 for(int i =0; i < NUM_PAGES; i++){
   if (framePool[i] == -1) {
            return i;      
        }
    }
    return -1;             
 }

int translate(Process* p, int virtualAddress){
  int vpn = virtualAddress /PAGE_SIZE;
  int offset = virtualAddress % PAGE_SIZE;
   if (vpn < 0 || vpn >= NUM_PAGES) {
        return -1;
    }
    int fault = 0;
    if (p->pageTable[vpn].valid == 0) {
        fault = 1;
        printf("Panic: Room not found at VPN x! Scrambling to build a new frame.../n");
        int frame = findFreeFrame();
        if (frame == -1) {
            printf("No free frames!\n");  
            return -1;
        }
        allocatePage(p, vpn, frame);
        }
        int pa = p->pageTable[vpn].frameNumber * PAGE_SIZE + offset;
    // append to the log
    if (traceCount < MAX_TRACE) {
        trace[traceCount].va = virtualAddress;
        trace[traceCount].vpn = vpn;
        trace[traceCount].offset = offset;
        trace[traceCount].pageFault = fault;
        traceCount++;
    }
    printf("P%d: VA %d -> VPN %d, offset %d, %s -> PA %d\n",
           p->pid, virtualAddress, vpn, offset, fault ? "PAGE FAULT" : "HIT", pa);
    return pa;
 }

void allocatePage(Process* p, int vpn, int frame)  { 
    // Map the virtual page to the physical frame 
    p -> pageTable[vpn].frameNumber = frame; 
    // Mark the entry as valid (the room is now prepared and occupied) 
    p -> pageTable[vpn].valid = 1; 
    // Update the global frame pool to record which process owns this room 
    framePool[frame] = p -> pid; 
}

void displayPhysicalMemory() {
    printf("--- Physical Memory ---\n");
    for (int i = 0; i < NUM_FRAMES; i++) {
        if (framePool[i] == -1) {
            printf("Frame %d: [FREE]\n", i);
        } else {
            printf("Frame %d: [P%d:VPN%d]\n", i, framePool[i], frameVPN[i]);
        }
    }
}

int main() {
    Process p1;
    initializeFramePool();
    initialize(&p1, 1);

    allocatePage(&p1, 1, 3);   // VPN 1 -> frame 3
    allocatePage(&p1, 2, 5);   // VPN 2 -> frame 5

    displayPhysicalMemory(&p1);

    int pa = translate(&p1, 512);
    printf("VA 512 -> PA %d\n", pa);
    return 0;
}
