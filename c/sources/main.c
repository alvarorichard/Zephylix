
#include "../include/chunk.h"
#include "../include/debug.h"
#include "../include/common.h"

#define EXIT_SUCCESS 0

int main(int argc, char *argv[])
{
	Chunk chunk;
	intitChunk(&chunk);
	writeChunk(&chunk, OP_RETURN);
	disassembleChunk(&chunk, "test chunk");
	freeChunk(&chunk);
	return EXIT_SUCCESS;
}