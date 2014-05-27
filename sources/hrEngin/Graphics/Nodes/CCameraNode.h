
#ifndef __HG_hr�CameraNode__
#define __HG_hr�CameraNode__

#include <Graphics/Nodes/ICameraNode.h>
#include <Graphics/Base/IVideoManager.h>
#include <Entities/IBaseEntity.h>

#include <Irrlicht/Irrlicht.h>

namespace hrengin
{
namespace graphics
{



class CCameraNode : public ICameraNode
{
	public:
		CCameraNode();
		CCameraNode(IBaseEntity* attach);

		virtual void AttachToEntity(IBaseEntity* attach);
		
		virtual hrengin::base::line3df castRayFromScreen(hrengin::i32 x, hrengin::i32 y);
		virtual hrengin::Vector3d __tempGetRayHitPlaneCoords(hrengin::i32 x, hrengin::i32 y);

		virtual void setPosition(Vector3d pos);
		virtual void setRotation(Vector3d rot);
		//virtual void SetScale(Vector3d scale);

		virtual void SetTargetPosition(Vector3d pos);
		virtual void SetCameraPosition(Vector3d pos);

		virtual void BindTargetToCamera(bool bind);

		virtual void SetCameraFOV(f64 fov);
		virtual void SetNearPlane(f64 dist);
		virtual void SetFarPlane(f64 dist);

		virtual void SetDistance(f64 dist);

		virtual void SetBehavior(CAM_Behavior beh);
	private:
		IBaseEntity* attachedTo;

		CAM_Behavior controlBehavior;
		
		irr::scene::ICameraSceneNode* node;
		irr::scene::ISceneNodeAnimator* animator;
};

	
} // namespace graphics
} // namespace hrengin

#endif//__HG_hr�VisNode__