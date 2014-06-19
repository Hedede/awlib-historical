#ifndef __HRENGIN_SOUND_ISoundManager_H__
#define __HRENGIN_SOUND_ISoundManager_H__

#include <hrengin/common/hrenginapi.h>

namespace hrengin
{
namespace sound
{

class ISound;

class ISoundManager
{
public:
	virtual void addSound(const char* fileName) = 0;
	virtual void initSounds() = 0;
	virtual void playSound(const char* fileName) = 0;
};

HRENGINSOUND_API ISoundManager& getSoundManager();

} // namespace sound
} // namespace hrengin

#endif//__HRENGIN_SOUND_ISoundManager_H__