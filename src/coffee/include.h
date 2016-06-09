////////////////////////////////////////////////
// This file is here to make sure the import  //
// process is handled smothly. Since the      //


#ifndef __INCLUDE__H__
#define __INCLUDE__H__
	//All os-s
	#if TARGET_OS=="Linux"
    	//Linux specific
    	#include <SDL2/SDL.h>
    	#include <glew.h>

	#elif TARGET_OS=="Windows"
		//Windows specific
    	#include <gl\GL.h>
    	#include "GLEW\glew.h"
		#include "SDL2\SDL.h"

	#endif
#endif
