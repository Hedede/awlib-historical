#ifndef __H_INCLUDED__HRENGIN_ISceneNode
#define __H_INCLUDED__HRENGIN_ISceneNode

#include <Common/hrTypes.h>
#include <Base/Vector3d.h>

namespace hrengin
{

class IBaseEntity;

namespace graphics
{
	

class ISceneNode
{
	public:
		virtual void AttachToEntity(IBaseEntity* attach) = 0;

		virtual void setPosition(Vector3d pos) = 0;
		virtual void setRotation(Vector3d rot) = 0;
		// not supported
		//virtual void setScale(Vectorf3d scale) = 0;
	protected:
		Vector3d mPosition;
		Vector3d mRotation;
};

	
} // namespace graphics
} // namespace hrengin

#endif//__HG_ISceneNode__