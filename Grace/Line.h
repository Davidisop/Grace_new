#include "PipeLineSetup.h"

class Line : public PipeLineSetup
{
public:

	HRESULT CreateVertexData() {}
	HRESULT CreateIndexData() {}

public:

	Line();
	virtual ~Line();
};


HRESULT Line::CreateVertexData()
{
	HRESULT hr = S_OK;
	// ¾Õ¸é
	m_VertexList.resize(2);
	m_VertexList[0] = PNCT_VERTEX(D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, -1.0f), D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR2(0.0f, 0.0f));
	m_VertexList[1] = PNCT_VERTEX(D3DXVECTOR3(1.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, -1.0f), D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f), D3DXVECTOR2(1.0f, 0.0f));
	m_iNumVertex = m_VertexList.size();
	return hr;
}
HRESULT Line::CreateIndexData()
{
	HRESULT hr = S_OK;
	m_IndexList.resize(2);
	int iIndex = 0;
	m_IndexList[iIndex++] = 0;
	m_IndexList[iIndex++] = 1;
	m_iNumIndex = m_IndexList.size();
	return hr;
}
bool Line::Draw(
	ID3D11DeviceContext* pContext,
	D3DXVECTOR3 vStart,
	D3DXVECTOR3 vEnd,
	D3DXVECTOR4 vColor)
{
	PNCT_VERTEX vertexList[2];
	vertexList[0] = m_VertexList[0];
	vertexList[1] = m_VertexList[1];
	vertexList[0].p = vStart;
	vertexList[0].c = vColor;
	vertexList[1].p = vEnd;
	vertexList[1].c = vColor;
	pContext->UpdateSubresource(
		m_dxObj.m_pVertexBuffer.Get(),
		0, NULL, &vertexList, 0, 0);

	Render(pContext);

	pContext->IASetPrimitiveTopology(
		D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	return true;
}
HRESULT Line::LoadPixelShader(T_STR  szName) {
	HRESULT hr = S_OK;
	m_dxObj.m_pPixelShader.Attach(
		DX::LoadPixelShaderFile(m_pd3dDevice,
			szName.c_str(), NULL, "PSLine"));

	return hr;
}
Line::xLineShape()
{
	m_Primitive = D3D_PRIMITIVE_TOPOLOGY_LINELIST;
}
Line::~xLineShape()
{
}