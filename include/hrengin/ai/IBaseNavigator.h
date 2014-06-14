#ifndef __H_INCLUDED__HRENGIN_IBaseNavigator
#define __H_INCLUDED__HRENGIN_IBaseNavigator

#include <AI/IBasePathfinder.h>

namespace hrengin
{
namespace ai
{

enum NAVState
{
	NA_STATE_IDLE,
	NA_STATE_GUARD,
	NA_STATE_MOVETO,
	NA_STATE_FOLLOW,
	NA_STATE_AVOID,
	NA_STATE_GIVEWAY,
	NA_STATE_BLOCKWAY,
	NA_STATE_ATTACHED,
	NA_STATE_COUNT,
	NA_STATE_ = 0x7FFFFFFF //force 32 bit for byte-alignment
};

class IBaseNavigator
{
	public:
		virtual ~IBaseNavigator() {};
		//virtual void SetPathfinder(IBasePathfinder* pathfinder) = 0;
		
		//
		virtual bool CheckState(NAVState state) = 0;
		virtual NAVState GetState() = 0;

		virtual void Move() = 0;
		virtual void Stop() = 0;
		virtual void Follow() = 0;
		virtual void AttachToGroup() = 0;
	private:
};

} // namespace ai
} // namespace hrengin

#endif //__H_INCLUDED__HRENGIN_IBaseNavigator