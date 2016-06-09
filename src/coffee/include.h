//////////////////////////////////////////////////
// This file is here to make sure the import	//
// process is handled smothly. Since the		//
// OS-s have different include directories.		//
//////////////////////////////////////////////////

#ifndef __INCLUDE__H__
#define __INCLUDE__H__
	//All os-s
	#if TARGET_OS==LINUX
    	//Linux specific
    	#include <SDL2/SDL.h>
    	#include <GL/glew.h>

	#elif TARGET_OS==WINDOWS
		//Windows specific
    	#include <gl\GL.h>
    	#include "GLEW\glew.h"
		#include "SDL2\SDL.h"

	#elif TARGET_OS==MAC
		//Not implemented, yet!
	#endif
#endif
