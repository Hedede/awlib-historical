#include <Irrlicht/irrlicht.h>

#include <hrengin/common/hrengintime.h>

#include "CVideoManager.h"

namespace hrengin {

HRENGINGRAPHICS_API u32 getTime()
{
	static irr::ITimer* timer(graphics::getLocalManager().GetDevice()->getTimer());
	return timer->getTime();
}

}