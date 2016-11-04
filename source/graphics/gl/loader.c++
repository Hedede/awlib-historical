/*
 * Code in this file is placed in public domain.
 * Contact: Hedede <Haddayn@gmail.com>
 */
#include "loader.h"

#ifdef AW_SUPPORT_PLATOFRM_APPLE
#include <dlfcn.h>

namespace aw::gl::apple {
unknown_fn* get_proc_address(const char *name)
{
	static void* image = nullptr;
	
	if (image == nullptr) {
		image = dlopen("/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL", RTLD_LAZY);
		if (image == nullptr)
			return nullptr;
	}

	return dlsym(image, name);
}
} // namespace aw::gl::apple
#endif//AW_HAS_PLATOFRM_APPLE

#ifdef AW_SUPPORT_PLATOFRM_SUN
#include <dlfcn.h>
#include <stdio.h>

namespace aw::gl::sun {
unknown_fn* get_proc_address(const char* name)
{
	using gpasig = void*(const GLubyte*);

	static void* image = nullptr;
	static gpasig* gpa = nullptr;

	if (image == nullptr) {
		image = dlopen(nullptr, RTLD_LAZY | RTLD_LOCAL);
		if (image == nullptr)
			return nullptr;
		gpa = dlsym(image, "glXGetProcAddress");
	}

	if (gpa == nullptr)
		return dlsym(image, name);
	return gpa((const GLubyte*)name);
}
} // namespace sun
#endif /* __sgi || __sun */

#ifdef AW_SUPPORT_PLATFORM_WIN32
#include <aw/algorithm/in.h>

#define WIN32_LEAN_AND_MEAN 1
#define NOMINMAX
#include <windows.h>

#ifdef _MSC_VER
#pragma warning(disable: 4055)
#pragma warning(disable: 4054)
#pragma warning(disable: 4996)
#endif

namespace aw::wgl {
namespace {
bool TestPointer(unknown_fn const* ptr)
{
	if(!ptr) return 0;

	intptr_t test = intptr_t(ptr);

	if( in(test, 1, 2, 3, -1) )
		return false;
	return true;
}
} // namespace

unknown_fn* get_proc_address(const char *name)
{
	HMODULE glMod = nullptr;
	PROC pFunc = wglGetProcAddress((LPCSTR)name);
	if(TestPointer(pFunc))
		return pFunc;
	glMod = GetModuleHandleA("OpenGL32.dll");
	return (unknown_fn*)GetProcAddress(glMod, (LPCSTR)name);
}
} // namespace aw::wgl
#endif//AW_SUPPORT_PLATFORM_WIN32

#ifdef AW_SUPPORT_PLATFORM_X11
#include <GL/glx.h>
namespace aw::glx {
unknown_fn* get_proc_address(const char* name)
{
	return (unknown_fn*)(*glXGetProcAddressARB)((const GLubyte*)name);
}
} // namespace aw::glx
#endif