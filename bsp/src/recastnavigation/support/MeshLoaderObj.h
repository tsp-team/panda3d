//
// Copyright (c) 2009-2010 Mikko Mononen memon@inside.org
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
//

/**
 * \file MeshLoaderObj.h
 *
 * \date 2016-03-16
 * \author Mikko Mononen (modified by consultit)
 */

#ifndef MESHLOADER_OBJ
#define MESHLOADER_OBJ

#include "common.h"
#include <nodePath.h>
#include <lmatrix.h>
#include <geomNode.h>
#include <geom.h>
#include <geomVertexData.h>
#include <geomPrimitive.h>

#include "config_recast.h"

namespace rnsup
{
class rcMeshLoaderObj
{
public:
	rcMeshLoaderObj();
	~rcMeshLoaderObj();
	
	bool load(const std::string& fileName, float scale = 1.0, float* translation = NULL);

	//Model stuff
	bool load(NodePath model, NodePath referenceNP);

	const float* getVerts() const { return m_verts; }
	const float* getNormals() const { return m_normals; }
	const int* getTris() const { return m_tris; }
	int getVertCount() const { return m_vertCount; }
	int getTriCount() const { return m_triCount; }
	const std::string& getFileName() const { return m_filename; }

	rcMeshLoaderObj& operator=(const rcMeshLoaderObj&);
private:
	// Explicitly disabled copy constructor and copy assignment operator.
	rcMeshLoaderObj(const rcMeshLoaderObj&);
	
	void addVertex(float x, float y, float z, int& cap);
	void addTriangle(int a, int b, int c, int& cap);
	//Model stuff
	void processGeomNode(PT(GeomNode)geomNode);
	void processGeom(CPT(Geom)geom);
	void processVertexData(CPT(GeomVertexData)vertexData);
	void processPrimitive(CPT(GeomPrimitive)primitive, unsigned int geomIndex);
	
	std::string m_filename;
	float m_scale;	
	float m_translation[3];
	float* m_verts;
	int* m_tris;
	float* m_normals;
	int m_vertCount;
	int m_triCount;
	//Model stuff
	std::vector<CPT(Geom)> m_geoms;
	std::vector<CPT(GeomVertexData)> m_vertexData;
	std::vector<int> m_startIndices;
	LMatrix4f m_currentTranformMat;
	int m_currentMaxIndex;
	int vcap, tcap;
public:
	//TypeWritable API
	void write_datagram(Datagram &dg) const;
	void read_datagram(DatagramIterator &scan);
};

} // namespace rnsup

#endif // MESHLOADER_OBJ
