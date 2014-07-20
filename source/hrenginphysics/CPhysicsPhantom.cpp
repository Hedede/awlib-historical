#include "CPhysicsPhantom.h"

namespace hrengin {
namespace physics {

CPhysicsPhantom::CPhysicsPhantom(btCollisionObject* pCollObject)
	: CollObject(pCollObject)
{
	CollObject->setUserPointer(this);
}

CPhysicsPhantom::CPhysicsPhantom(btCollisionObject* pCollObject, IBaseEntity* pAttach)
	: CollObject(pCollObject), AttachedTo(pAttach)
{
	CollObject->setUserPointer(this);
}

void CPhysicsPhantom::setPosition(Vector3d pos) 
{
	btTransform localTransform;
	localTransform.setIdentity();
	localTransform.setOrigin(btVector3(pos.X,pos.Y,pos.Z));
	localTransform.setRotation(CollObject->getWorldTransform().getRotation());
	
	CollObject->setWorldTransform(localTransform);
};


void CPhysicsPhantom::setRotation(Vector3d rot) 
{
	btTransform localTransform;
	localTransform.setIdentity();
	localTransform.setOrigin(CollObject->getWorldTransform().getOrigin());
	localTransform.setRotation(btQuaternion(rot.Y,rot.X,rot.Z));
	
	CollObject->setWorldTransform(localTransform);
};


IBaseEntity* CPhysicsPhantom::getEntity()
{
	return AttachedTo;
}

} // namespace physics
} // namespace hrengin