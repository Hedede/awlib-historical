#ifndef __HRENGIN_hrenginmodels_H__
#define __HRENGIN_hrenginmodels_H__

#include <hrengin/common/hrengintypes.h>
#include <hrengin/common/Vector3d.h>

namespace hrengin {
enum Shape {
	SHAPE_EMPTY,
	SHAPE_SPHERE,
	SHAPE_BOX,
	SHAPE_CAPSULE,
	SHAPE_CYLINDER,
	SHAPE_CONE
};

enum Axis
{
	AXIS_X,
	AXIS_Y,
	AXIS_Z
};

struct SPrimitive {
	Shape shape;
	Axis axis;
	f32 dimensions[3];
	f32 offset[3];
	f32 rotation[3];

	SPrimitive () : shape(SHAPE_EMPTY), axis(AXIS_Y), dimensions(), offset(), rotation()
	{

	}
};

struct SMesh {
	f32* verts;
};


} // namespace hrengin

#endif __HRENGIN_hrenginmodels_H__