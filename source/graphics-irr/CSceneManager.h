/*
 * Copyright (C) 2014  absurdworlds
 *
 * License LGPLv3-only:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _hrengin_CSceneManager_
#define _hrengin_CSceneManager_

#include <vector>

#include <hrengin/math/Vector3d.h>

#include <hrengin/graphics/IRenderingDevice.h>

#include <hrengin/scene/scene.h>
#include <hrengin/scene/ISceneManager.h>
#include <hrengin/scene/IVisNode.h>
#include <hrengin/scene/ICameraNode.h>
#include <hrengin/scene/ILightNode.h>
#include <hrengin/scene/IEntityNode.h>

namespace irr {
class IrrlichtDevice;
namespace scene {
class ISceneManager;
class IAnimatedMesh;
class ISceneCollisionManager;
class ISceneNode;
}
}

namespace hrengin {
namespace scene {
//! Class to manage the scene graph
class CSceneManager : public ISceneManager {
public:
	CSceneManager(irr::scene::ISceneManager* irrSceneManager,
		graphics::IRenderingDevice* renderer,
		irr::IrrlichtDevice* device);

	virtual void createScene();

	virtual void drawScene();

	virtual void update();

	virtual IVisNode* createMeshSceneNode(char const* meshname);
	//virtual IVisNode* createMeshSceneNode(IMesh* mesh);
	virtual ICameraNode* createCameraSceneNode();
	virtual ILightNode* createLightSceneNode();
	virtual IEntityNode* createEntitySceneNode(IEntity* entity);
private:
	std::vector<INode*> NodeList;
	
	irr::IrrlichtDevice* device_;
	irr::scene::ISceneManager*          scnmgr;
	irr::scene::ISceneCollisionManager* colman;
public:
	irr::scene::IAnimatedMesh* convertMesh(char* const meshname);
	//irr::scene::IAnimatedMesh* convertMesh(IMesh* mesh);
};

} // namespace graphics
} // namespace hrengin
#endif//_hrengin_CSceneManager_
