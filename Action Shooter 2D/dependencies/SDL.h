//This is due to the SDL linux package being in a weird folder, might have been a more elegant solution
//But this works and doesn't require messing with the linux distro itself. Also its all handled compile
// time so no performance hit.
#ifdef __ANDROID__
#include <SDL.h>
#elif __linux__
#include "SDL2/SDL.h"
#else
#include <SDL.h>
#endif