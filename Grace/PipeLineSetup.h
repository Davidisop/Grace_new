#pragma once

#include "xCore.h"



struct SimpleVertex  // 4*7 = 28바이트

{
	D3DXVECTOR3 p;
	D3DXVECTOR4 c;
	D3DXVECTOR2 t;

	bool operator == (const SimpleVertex & Vertex)
	{
		if (p == Vertex.p  &&  c == Vertex.c)
		{
			return true;
		}
		return  false;
	}

	SimpleVertex() {}
	SimpleVertex(D3DXVECTOR3 vp,		D3DXVECTOR4 vc,		D3DXVECTOR2 vt)
	{
		p = vp, c = vc, t = vt;
	}

};





struct T_CB_DATA

{

	D3DXMATRIX matWorld;

	D3DXMATRIX matView;

	D3DXMATRIX matProj;

	float fTime;

	float fActiveVP;

	float z, w;

	D3DXVECTOR4  vColor;

};







class PipeLineSetup

{

public:

	vector<SimpleVertex> m_VertexList;
	vector<DWORD>   m_IndexList;
	T_CB_DATA            m_cbData;



	UINT     m_icount_Indexs;
	UINT     m_icount_Vertexs;
	UINT     m_Vertex_each_Size;



public:

	ID3D11Buffer * m_pVertextBuffer;
	ID3D11VertexShader*   m_pVertexShader;

	ID3D11Buffer*    m_pIndexBuffer;

	ID3D11Buffer *    m_pConstantBuffer;

	ID3D11PixelShader*   m_pPixelShader;

	ID3DBlob*     m_pVSBlob;

	ID3DBlob*     m_pPSBlob;

	ID3DBlob*     m_pErrorBlob;

	ID3D11InputLayout*   m_pVertexLayout;

	ID3D11ShaderResourceView* m_pTextureSRV;

	ID3D11SamplerState*   m_pSamplerState;

	ID3D11BlendState*   m_pAlphaBlend;



public:

	virtual HRESULT CreateVertexData() {	return S_OK;	};
	virtual HRESULT CreateIndexData() {		return S_OK;	};

public:



	HRESULT CreateVertextBuffer(ID3D11Device* pd3dDevice);

	HRESULT CreateVertexShader(ID3D11Device* pd3dDevice, const TCHAR* pName);

	HRESULT CreateIndexBuffer(ID3D11Device* pd3dDevice);

	HRESULT CreateConstantBuffer(ID3D11Device* pd3dDevice);

	HRESULT CreateLayout(ID3D11Device* pd3dDevice);

	HRESULT CreatePixelShader(ID3D11Device* pd3dDevice, const TCHAR* pName);

	HRESULT LoadTexture(ID3D11Device* pd3dDevice, const TCHAR* pLoadFile);

	HRESULT SetBlendState(ID3D11Device* pd3dDevice);



public:

	bool Init(ID3D11Device* pd3dDevice, const TCHAR* p_Vertex_shader_Name, const TCHAR* p_Pixel_shader_Name)

	{
		//LoadTexture(g_pd3dDevice, p_Texture_LoadFile);
		SetBlendState(pd3dDevice);
		CreateVertextBuffer(g_pd3dDevice);
		CreateVertexShader(g_pd3dDevice, p_Vertex_shader_Name);
		CreateIndexBuffer(pd3dDevice);
		CreateLayout(g_pd3dDevice);
		CreateConstantBuffer(pd3dDevice);
		CreatePixelShader(g_pd3dDevice, p_Pixel_shader_Name);

		return true;
	}



	bool PreRender(ID3D11DeviceContext* pContext)
	{

		pContext->VSSetShader(m_pVertexShader, NULL, NULL);
		pContext->PSSetShader(m_pPixelShader, NULL, NULL);//0
		pContext->PSSetShaderResources(0, 1, &m_pTextureSRV);

		//pContext->PSSetSamplers(0, 1, &m_pSamplerState);

		UINT pStrides = sizeof(SimpleVertex);
		UINT pOffsets = 0; //*** 정점버퍼의 처리는 정점1개 단위로 연산된다.

		pContext->IASetVertexBuffers(0, 1, &m_pVertextBuffer, &pStrides, &pOffsets);
		pContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		pContext->OMSetBlendState(m_pAlphaBlend, 0, -1);
		pContext->IASetInputLayout(m_pVertexLayout);

		return true;

	}

	bool Render(ID3D11DeviceContext* pContext, UINT index_Count)
	{

		PreRender(pContext);
		PostRender(pContext, index_Count);

		return true;

	}

	bool PostRender(ID3D11DeviceContext* pContext, UINT index_Count)
	{
		pContext->Draw(index_Count, 0);
		return true;

	}



	bool Release()

	{

		if (m_pPixelShader != NULL)  m_pPixelShader->Release();

		if (m_pPSBlob != NULL) m_pPSBlob->Release();

		if (m_pVertexShader != NULL) m_pVertexShader->Release();

		if (m_pVertexLayout != NULL) m_pVertexLayout->Release();

		if (m_pVSBlob != NULL) m_pVSBlob->Release();

		if (m_pErrorBlob != NULL)m_pErrorBlob->Release();

		if (m_pConstantBuffer != NULL)m_pConstantBuffer->Release();

		if (m_pIndexBuffer != NULL)m_pIndexBuffer->Release();

		if (m_pVertextBuffer != NULL) m_pVertextBuffer->Release();

		if (m_pAlphaBlend != NULL)m_pAlphaBlend->Release();

		if (m_pSamplerState != NULL)m_pSamplerState->Release();

		if (m_pTextureSRV != NULL)m_pTextureSRV->Release();









		m_pVSBlob = NULL;

		m_pPSBlob = NULL;

		m_pErrorBlob = NULL;

		m_pVertexLayout = NULL;

		m_pTextureSRV = NULL;

		m_pSamplerState = NULL;

		m_pAlphaBlend = NULL;



		m_pVertextBuffer = NULL;

		m_pConstantBuffer = NULL;

		m_pIndexBuffer = NULL;

		m_pVertexShader = NULL;

		m_pPixelShader = NULL;

		m_pVertexLayout = NULL;



		return true;

	}

public:

	PipeLineSetup() {}

	~PipeLineSetup() {}

};





HRESULT PipeLineSetup::CreateConstantBuffer(ID3D11Device* pd3dDevice)

{

	HRESULT hr;

	D3D11_BUFFER_DESC bd;

	D3D11_SUBRESOURCE_DATA sd;

	ZeroMemory(&bd, sizeof(bd));

	ZeroMemory(&sd, sizeof(sd));



	bd.Usage = D3D11_USAGE_DEFAULT;

	bd.CPUAccessFlags = 0;



	bd.ByteWidth = sizeof(T_CB_DATA);

	bd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

	sd.pSysMem = &m_cbData;





	if (FAILED(hr = pd3dDevice->CreateBuffer(&bd, &sd, &m_pConstantBuffer)))

	{

		return hr;;

	}



	return hr;



}





HRESULT PipeLineSetup::CreateIndexBuffer(ID3D11Device* pd3dDevice)

{

	HRESULT hr;

	D3D11_BUFFER_DESC bd;

	D3D11_SUBRESOURCE_DATA sd; // 집어넣을 데이터



	ZeroMemory(&bd, sizeof(bd));

	ZeroMemory(&sd, sizeof(sd));



	bd.Usage = D3D11_USAGE_DEFAULT;

	bd.CPUAccessFlags = 0;

	bd.ByteWidth = m_IndexList.size() * sizeof(DWORD);

	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;

	sd.pSysMem = &m_IndexList;



	if (FAILED(hr = pd3dDevice->CreateBuffer(&bd, &sd, &m_pIndexBuffer)))

	{

		return hr;;

	}



	return hr;



}





HRESULT  PipeLineSetup::CreateVertextBuffer(ID3D11Device* pd3dDevice)

{

	HRESULT hr;

	D3D11_BUFFER_DESC pDesc;

	ZeroMemory(&pDesc, sizeof(D3D11_BUFFER_DESC));



	pDesc.ByteWidth = m_VertexList.size() * sizeof(SimpleVertex);



	pDesc.Usage = D3D11_USAGE_DEFAULT;

	pDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;



	D3D11_SUBRESOURCE_DATA pInitialData;

	ZeroMemory(&pInitialData, sizeof(pInitialData));



	pInitialData.pSysMem = &m_VertexList;



	if (FAILED(hr = pd3dDevice->CreateBuffer(

		&pDesc,

		&pInitialData,

		&m_pVertextBuffer)))

	{

		return hr;

	}



	return hr;

}

HRESULT PipeLineSetup::CreateVertexShader(ID3D11Device* pd3dDevice, const TCHAR* pszFileName)

{

	HRESULT hr;

	hr = D3DX11CompileFromFile(pszFileName, NULL, NULL, "VS", "vs_5_0", 0, 0, NULL, &m_pVSBlob, &m_pErrorBlob, NULL);

	if (FAILED(hr))

	{

		OutputDebugStringA((char*)m_pErrorBlob->GetBufferPointer());

		return false;

	}



	//4)정점쉐이더 생성

	// 정점버퍼의 정점을 실제 처리하는 곳-->정점쉐이더



	if (FAILED(hr = g_pd3dDevice->CreateVertexShader(m_pVSBlob->GetBufferPointer(), m_pVSBlob->GetBufferSize(), NULL, &m_pVertexShader)))

	{

		return hr;

	}

	return hr;

}

HRESULT PipeLineSetup::CreatePixelShader(ID3D11Device* pd3dDevice, const TCHAR* pszFileName)

{

	HRESULT hr;

	hr = D3DX11CompileFromFile(pszFileName, NULL, NULL, "PS", "ps_5_0", 0, 0, NULL, &m_pPSBlob, &m_pErrorBlob, NULL);

	if (FAILED(hr))

	{

		OutputDebugStringA((char*)m_pErrorBlob->GetBufferPointer());

		return false;

	}



	if (FAILED(hr = g_pd3dDevice->CreatePixelShader(

		m_pPSBlob->GetBufferPointer(),

		m_pPSBlob->GetBufferSize(), NULL, &m_pPixelShader)))

	{

		m_pPSBlob->Release();

		return NULL;

	}

	m_pPSBlob->Release();

	return hr;

}



HRESULT PipeLineSetup::CreateLayout(ID3D11Device* pd3dDevice)

{

	HRESULT hr;

	if (m_pVSBlob == NULL) return E_FAIL;

	//6)레이아웃 설정



	D3D11_INPUT_ELEMENT_DESC ied[] =

	{

		{ "POSITION",  0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },

	{ "COLOR",  0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12,  D3D11_INPUT_PER_VERTEX_DATA, 0 },

	{ "TEXTURE", 0, DXGI_FORMAT_R32G32_FLOAT,0, 28, D3D11_INPUT_PER_VERTEX_DATA, 0 }

	};

	int iNumElement = sizeof(ied) / sizeof(D3D11_INPUT_ELEMENT_DESC);

	if (FAILED(hr = g_pd3dDevice->CreateInputLayout(

		ied, iNumElement,

		m_pVSBlob->GetBufferPointer(),

		m_pVSBlob->GetBufferSize(),

		&m_pVertexLayout)))

	{

		return hr;

	}

	return hr;

}



HRESULT PipeLineSetup::LoadTexture(ID3D11Device* pd3dDevice, const TCHAR* pLoadFile)

{

	HRESULT hr;

	if (FAILED(hr = D3DX11CreateShaderResourceViewFromFile(g_pd3dDevice, pLoadFile, NULL, NULL, &m_pTextureSRV, NULL)))

	{

		return hr;

	}

	D3D11_SAMPLER_DESC sd;

	ZeroMemory(&sd, sizeof(D3D11_SAMPLER_DESC));

	sd.AddressU = D3D11_TEXTURE_ADDRESS_MIRROR;

	sd.AddressV = D3D11_TEXTURE_ADDRESS_MIRROR;

	sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

	sd.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;

	g_pd3dDevice->CreateSamplerState(&sd, &m_pSamplerState);

	return hr;

}



HRESULT PipeLineSetup::SetBlendState(ID3D11Device* pd3dDevice)

{

	HRESULT hr = S_OK;

	D3D11_BLEND_DESC bd;

	ZeroMemory(&bd, sizeof(bd));



	bd.RenderTarget[0].BlendEnable = true;

	//FinalColor = destColor * DescBlend + srcColor * SrcBlend;

	bd.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;

	bd.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;

	bd.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;



	//FinalAlpha = destAlpha * DescBlendAlpha + srcAlpha * SrcBlendAlpha;

	bd.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;

	bd.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;

	bd.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

	bd.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

	hr = g_pd3dDevice->CreateBlendState(&bd, (ID3D11BlendState **)&m_pAlphaBlend);

	return hr;

}


