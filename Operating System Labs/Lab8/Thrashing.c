
#include <stdio.h> 
#include <stdlib.h> 
#define PAGE_SIZE 256 
#define NUM_PAGES 16 
#define NUM_FRAMES 2
#define MAX_TRACE 100

typedef struct { 
    int frameNumber; 
    int valid; // The valid flag simulates page presence. 
    } PageTableEntry;

typedef struct { 
  PageTableEntry pageTable[NUM_PAGES]; 
  int pid; 
  } Process; 

typedef struct  
    { 
    int va; 
    int vpn; 
    int offset; 
    int pageFault; // 1 = fault, 0 = hit 
    } TraceEntry; 

TraceEntry trace[MAX_TRACE];
int traceCount = 0;
int framePool[NUM_FRAMES];
int frameVPN[NUM_FRAMES];
int nextVictim = 0;   
// Each process has a page table mapping virtual pages to physical frames. 
 
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
  framePool[i] = -1;
  frameVPN[i] = -1;// -1 indicates a free frame. 
  } 
}

void allocatePage(Process* p, int vpn, int frame)  { 
    // Map the virtual page to the physical frame 
    p -> pageTable[vpn].frameNumber = frame; 
    // Mark the entry as valid (the room is now prepared and occupied) 
    p -> pageTable[vpn].valid = 1; 
    // Update the global frame pool to record which process owns this room 
    framePool[frame] = p -> pid; 
    frameVPN[frame] = vpn;
}

int findFreeFrame(){
 for(int i =0; i < NUM_FRAMES; i++){
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
        printf("Panic: Room not found at VPN %d! Scrambling to build a new frame...\n", vpn);
        int frame = findFreeFrame();
        if (frame == -1) {
             frame = nextVictim;
        nextVictim = (nextVictim + 1) % NUM_FRAMES;
        int oldVpn = frameVPN[frame];
        printf("  Evicting VPN %d from frame %d\n", oldVpn, frame);
        p->pageTable[oldVpn].valid = 0;   // victim's page is no longer present
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

    // Access VPN 1, 2, 3 over and over
    for (int round = 0; round < 10; round++) {
        for (int vpn = 1; vpn <= 3; vpn++) {
            translate(&p1, vpn * PAGE_SIZE);
        }
    }

    displayPhysicalMemory();

    int faults = 0;
    for (int i = 0; i < traceCount; i++) {
        faults += trace[i].pageFault;
    }
    printf("Total accesses: %d, page faults: %d\n", traceCount, faults);
    return 0;
}
