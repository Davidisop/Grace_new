#include "PipeLineSetup.h"

class Box : public PipeLineSetup

{

public:

	HRESULT CreateVertexData();
	HRESULT CreateIndexData();

public:

	Box() {}
	virtual ~Box() {}

};



HRESULT Box::CreateVertexData()
{
	HRESULT hr = S_OK;
	// ¾Õ¸é
	m_VertexList.resize(24);
	m_VertexList[0] = SimpleVertex(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[1] = SimpleVertex(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[2] = SimpleVertex(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VertexList[3] = SimpleVertex(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));
	// µÞ¸é
	m_VertexList[4] = SimpleVertex(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR4(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[5] = SimpleVertex(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[6] = SimpleVertex(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VertexList[7] = SimpleVertex(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));

	// ¿À¸¥ÂÊ
	m_VertexList[8] = SimpleVertex(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[9] = SimpleVertex(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[10] = SimpleVertex(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VertexList[11] = SimpleVertex(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));

	// ¿ÞÂÊ
	m_VertexList[12] = SimpleVertex(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[13] = SimpleVertex(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[14] = SimpleVertex(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VertexList[15] = SimpleVertex(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR4(1.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));

	// À­¸é
	m_VertexList[16] = SimpleVertex(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR4(1.0f, 0.5f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[17] = SimpleVertex(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR4(1.0f, 0.5f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[18] = SimpleVertex(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR4(1.0f, 0.5f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VertexList[19] = SimpleVertex(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR4(1.0f, 0.5f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));

	// ¾Æ·§¸é
	m_VertexList[20] = SimpleVertex(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[21] = SimpleVertex(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_VertexList[22] = SimpleVertex(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(1.0f, 1.0f));
	m_VertexList[23] = SimpleVertex(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR4(0.0f, 1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.0f, 1.0f));

	m_icount_Vertexs = m_VertexList.size();
	m_Vertex_each_Size = sizeof(SimpleVertex);

	return hr;
}
HRESULT Box::CreateIndexData()
{
	HRESULT hr = S_OK;
	m_IndexList.resize(36);
	int iIndex = 0;
	m_IndexList[iIndex++] = 0; 	m_IndexList[iIndex++] = 1; 	m_IndexList[iIndex++] = 2; 
	m_IndexList[iIndex++] = 0;	m_IndexList[iIndex++] = 2; 	m_IndexList[iIndex++] = 3;
	m_IndexList[iIndex++] = 4; 	m_IndexList[iIndex++] = 5; 	m_IndexList[iIndex++] = 6;
	m_IndexList[iIndex++] = 4;	m_IndexList[iIndex++] = 6; 	m_IndexList[iIndex++] = 7;
	m_IndexList[iIndex++] = 8; 	m_IndexList[iIndex++] = 9; 	m_IndexList[iIndex++] = 10;
	m_IndexList[iIndex++] = 8;	m_IndexList[iIndex++] = 10; m_IndexList[iIndex++] = 11;
	m_IndexList[iIndex++] = 12; m_IndexList[iIndex++] = 13; m_IndexList[iIndex++] = 14;
	m_IndexList[iIndex++] = 12;	m_IndexList[iIndex++] = 14; m_IndexList[iIndex++] = 15;
	m_IndexList[iIndex++] = 16; m_IndexList[iIndex++] = 17; m_IndexList[iIndex++] = 18;
	m_IndexList[iIndex++] = 16;	m_IndexList[iIndex++] = 18; m_IndexList[iIndex++] = 19;
	m_IndexList[iIndex++] = 20; m_IndexList[iIndex++] = 21; m_IndexList[iIndex++] = 22;
	m_IndexList[iIndex++] = 20;	m_IndexList[iIndex++] = 22; m_IndexList[iIndex++] = 23;

	m_icount_Indexs = m_IndexList.size();

	return hr;
}