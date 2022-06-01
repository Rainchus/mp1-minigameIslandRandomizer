.n64 // Let armips know we're coding for the N64 architecture
.open "rom/mp1.z64", "rom/mp1.mod.z64", 0 // Open the ROM file
.include "asm/symbols.asm" // Include mp1.asm to tell armips' linker where to find the game's function(s)
.include "asm/bootPatch.asm" //patch boot routine to DMA our code from ROM
.headersize 0x7E712B70 // Set the displacement between ROM and RAM addresses
.org 0x80401000
.importobj "obj/main.o" // Import and link the compiled C object, overwriting the useless function with our new code
.close // Close the ROM file