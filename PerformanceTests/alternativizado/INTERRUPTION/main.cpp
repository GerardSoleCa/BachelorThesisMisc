#include "Program.h"
using namespace System;
using namespace raspberrypi;

int main(int argc, char *argv[])
{
	GC::Init();
	String *args = new String[argc];
	for(int i = 0; i < argc; i++)
		args[i] = argv[i];

	Program::Main();
	GC::Collect();
}