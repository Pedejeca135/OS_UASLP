// addrspace.cc 
//	Routines to manage address spaces (executing user programs).
//
//	In order to run a user program, you must:
//
//	1. link with the -N -T 0 option 
//	2. run coff2noff to convert the object file to Nachos format
//		(Nachos object code format is essentially just a simpler
//		version of the UNIX executable object code format)
//	3. load the NOFF file into the Nachos file system
//		(if you haven't implemented the file system yet, you
//		don't need to do this last step)
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include "noff.h"

//----------------------------------------------------------------------
// SwapHeader
// 	Do little endian to big endian conversion on the bytes in the 
//	object file header, in case the file was generated on a little
//	endian machine, and we're now running on a big endian machine.
//----------------------------------------------------------------------

static void 
SwapHeader (NoffHeader *noffH)
{
	noffH->noffMagic = WordToHost(noffH->noffMagic);
	noffH->code.size = WordToHost(noffH->code.size);
	noffH->code.virtualAddr = WordToHost(noffH->code.virtualAddr);
	noffH->code.inFileAddr = WordToHost(noffH->code.inFileAddr);
	noffH->initData.size = WordToHost(noffH->initData.size);
	noffH->initData.virtualAddr = WordToHost(noffH->initData.virtualAddr);
	noffH->initData.inFileAddr = WordToHost(noffH->initData.inFileAddr);
	noffH->uninitData.size = WordToHost(noffH->uninitData.size);
	noffH->uninitData.virtualAddr = WordToHost(noffH->uninitData.virtualAddr);
	noffH->uninitData.inFileAddr = WordToHost(noffH->uninitData.inFileAddr);
}

//----------------------------------------------------------------------
// AddrSpace::AddrSpace
// 	Create an address space to run a user program.
//	Load the program from a file "executable", and set everything
//	up so that we can start executing user instructions.
//
//	Assumes that the object code file is in NOFF format.
//
//	First, set up the translation from program memory to physical 
//	memory.  For now, this is really simple (1:1), since we are
//	only uniprogramming, and we have a single unsegmented page table
//
//	"executable" is the file containing the object code to load into memory
//----------------------------------------------------------------------


/**********************************************
* Cantú Olivares Pedro de Jesús.
***********************************************/



AddrSpace::AddrSpace(OpenFile *executable)
{
    NoffHeader noffH;
    unsigned int i, size;

    executable->ReadAt((char *)&noffH, sizeof(noffH), 0);
    if ((noffH.noffMagic != NOFFMAGIC) && 
		(WordToHost(noffH.noffMagic) == NOFFMAGIC))
    	SwapHeader(&noffH);
    ASSERT(noffH.noffMagic == NOFFMAGIC);


    //añadido Practica1:-------------------------------------------------------------------
    if(swapOpenFile != NULL)
    {
        char *aux;
            aux = new char[executable->Length()-40];
            executable->ReadAt(aux,executable->Length()-40,40);
            swapOpenFile->Write(aux,executable->Length()-40);
            //printf("El aux lleva: %s\n", aux );
            //delete swapOpenFile;
        
    }
    else
    {
        printf("El archivo de intercambio no existe\n");
    }
    //--------------------------------------------------------------------------------------



// how big is address space?
    size = noffH.code.size + noffH.initData.size + noffH.uninitData.size 
			+ UserStackSize;	// we need to increase the size
						// to leave room for the stack
    numPages = divRoundUp(size, PageSize);
if(!strcmp(comando,"-C")||!strcmp(comando,"-F")|| !strcmp(comando,"-R"))
{
    //imprimir el tamaño de proceso(Practica0).
    printf("\nEl tamano del proceso es: %d bytes\n",size);
    size = numPages * PageSize;

    //imrimir la cantidad de marcosw necesarios para el proceso(Practica0).
    printf("\nLa cantidad de marcos que requiere para ejecutarse son: %d \n",numPages);
}
/* Practica 2: No se necesita checar que el numero de paginas
sea menor o igual a le de los marcos puesto que es paginacion
por demanda pura(se comento el ASSERT()*/
    //ASSERT(numPages <= NumPhysPages);		// check we're not trying
						// to run anything too big --
						// at least until we have
						// virtual memory

    //DEBUG('a', "Initializing address space, num pages %d, size %d\n", 
					//numPages, size);
// first, set up the translation 
    //imprimir el esqueleto de la tabla(Practica0).
    if(!strcmp(comando,"-R") )
    printf("Indice \t No. Marco \t Bit Validez\n");
    
    //pageTable = new TranslationEntry[numPages]; //comentado para la practica2.
    pageTable = new TranslationEntry[NumPhysPages];
    if(pageTable != NULL)
{
    //printf("en AddrSpacepageTable != NULL\n");
}
else
{
    printf("en AddrSpace pageTable = NULL\n");
}
    for (i = 0; i < NumPhysPages; i++) 
    {
        //printf("pageTable. numPages: %d\n",numPages );
	pageTable[i].virtualPage = i;	// for now, virtual page # = phys page #
	//pageTable[i].physicalPage = i;
	//pageTable[i].valid = TRUE;
    pageTable[i].valid = FALSE;
	pageTable[i].use = FALSE;
	pageTable[i].dirty = FALSE;
	pageTable[i].readOnly = FALSE;  // if the code segment was entirely on 
					// a separate page, we could set its 
					// pages to be read-only
    //imprimir datos que se listan en el esqueleto de la tabla.(Practica0).
   // printf("%d              %d              %d \n",i,pageTable[i].physicalPage,pageTable[i].valid);
      if(pageTable == NULL)
{
    printf("en AddrSpace pageTable = NULL\n");
}
    }
    //imprimir (Practica0).
    if(!strcmp(comando,"-M") || !strcmp(comando,"-R") )
    {
    printf("\nMapeo de direcciones logicas\n");
    printf("Dirección logica \t No.Marco(p) \t Desplazamiento(d) \t Dirección Fisica\t\n");
}
// zero out the entire address space, to zero the unitialized data segment 
// and the stack segment
    // printf("bzero1/2\n");
    //bzero(machine->mainMemory, size);
    //printf("bzero 2/2\n");

if(pageTable != NULL)
{
    //printf("en AddrSpacepageTable != NULL\n");
}
else
{
    printf("en AddrSpace pageTable = NULL\n");
}
/*
// then, copy in the code and data segments into memory
    if (noffH.code.size > 0) {
        DEBUG('a', "Initializing code segment, at 0x%x, size %d\n", 
			noffH.code.virtualAddr, noffH.code.size);
        //executable->ReadAt(&(machine->mainMemory[noffH.code.virtualAddr]),
			//noffH.code.size, noffH.code.inFileAddr);
    }
    if (noffH.initData.size > 0) {
        DEBUG('a', "Initializing data segment, at 0x%x, size %d\n", 
			noffH.initData.virtualAddr, noffH.initData.size);
        //executable->ReadAt(&(machine->mainMemory[noffH.initData.virtualAddr]),
			//noffH.initData.size, noffH.initData.inFileAddr);
    }
    */
    
    //printf("se acabo el constructor de AddrSpace");


}

//----------------------------------------------------------------------
// AddrSpace::~AddrSpace
// 	Dealloate an address space.  Nothing for now!
//----------------------------------------------------------------------

AddrSpace::~AddrSpace()
{
   delete pageTable;
}

//----------------------------------------------------------------------
// AddrSpace::InitRegisters
// 	Set the initial values for the user-level register set.
//
// 	We write these directly into the "machine" registers, so
//	that we can immediately jump to user code.  Note that these
//	will be saved/restored into the currentThread->userRegisters
//	when this thread is context switched out.
//----------------------------------------------------------------------

void
AddrSpace::InitRegisters()
{
    int i;

    for (i = 0; i < NumTotalRegs; i++)
	machine->WriteRegister(i, 0);

    // Initial program counter -- must be location of "Start"
    machine->WriteRegister(PCReg, 0);	

    // Need to also tell MIPS where next instruction is, because
    // of branch delay possibility
    machine->WriteRegister(NextPCReg, 4);

   // Set the stack register to the end of the address space, where we
   // allocated the stack; but subtract off a bit, to make sure we don't
   // accidentally reference off the end!
    machine->WriteRegister(StackReg, numPages * PageSize - 16);
    DEBUG('a', "Initializing stack register to %d\n", numPages * PageSize - 16);
}

//----------------------------------------------------------------------
// AddrSpace::SaveState
// 	On a context switch, save any machine state, specific
//	to this address space, that needs saving.
//
//	For now, nothing!
//----------------------------------------------------------------------

void AddrSpace::SaveState() 
{}

//----------------------------------------------------------------------
// AddrSpace::RestoreState
// 	On a context switch, restore the machine state so that
//	this address space can run.
//
//      For now, tell the machine where to find the page table.
//----------------------------------------------------------------------

void AddrSpace::RestoreState() 
{
    machine->pageTable = pageTable;
    machine->pageTableSize = numPages;
}


//void AddrSpace :: swapIn(char *into, int numBytes, int position)
void AddrSpace :: swapIn(int vpn)
{
    printf("Entro al SwapIn la vpn : %d \n",vpn);
    // Abrir swapFile
        // swapFile = fileSystem->Open("../test/sort.swp");
    if(swapOpenFile != NULL)
    {
        char *buffer = new char[PageSize];
        swapOpenFile->ReadAt(buffer,PageSize,vpn*PageSize);
        printf("buffer: %s\n",buffer );

        swapOpenFile->ReadAt(&(machine->mainMemory[stats->numPageFaults*PageSize]),PageSize,vpn*PageSize);
    }
    else
        printf("algo fue mal, el archivo de intercambio no existe \n");

       
}

//no necesaria aun, puesto que el archivo de intercambio almacena todo el proceso
//y el swap in solo lee la parte que requiere con la formula pertinente.
void AddrSpace:: swapOut()
{

}
