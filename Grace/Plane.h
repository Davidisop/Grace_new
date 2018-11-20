#include "PipeLineSetup.h"

class Plane : public PipeLineSetup

{

public:

	HRESULT CreateVertexData() {}

	HRESULT CreateIndexData() {}

public:

	Plane() {}
	virtual ~Plane() {}

};



HRESULT Plane::CreateVertexData()
{
	HRESULT hr = S_OK;
	// ¾Õ¸é
	m_VertexList.resize(4);
	m_VertexList[0] = SimpleVertex(D3DXVECTOR3(-1.0f, 1.0f, 0.0f),  D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[1] = SimpleVertex(D3DXVECTOR3(1.0f, 1.0f, 0.0f), D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[2] = SimpleVertex(D3DXVECTOR3(1.0f, -1.0f, 0.0f), D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VertexList[3] = SimpleVertex(D3DXVECTOR3(-1.0f, -1.0f, 0.0f),  D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	
	m_icount_Vertexs = m_VertexList.size();
	m_Vertex_each_Size = sizeof(SimpleVertex);

	return hr;
}



HRESULT Plane::CreateIndexData()
{
	HRESULT hr = S_OK;
	m_IndexList.resize(6);

	int iIndex = 0;
	m_IndexList[iIndex++] = 0; 	m_IndexList[iIndex++] = 1; 	m_IndexList[iIndex++] = 2;
	m_IndexList[iIndex++] = 0;	m_IndexList[iIndex++] = 2; 	m_IndexList[iIndex++] = 3;

	m_icount_Indexs = m_IndexList.size();

	return hr;
}