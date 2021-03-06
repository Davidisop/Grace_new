#pragma once
#include <d3d11.h>

namespace DX
{
	class xDxState
	{
	public:
		static ID3D11DepthStencilState*   g_pDSVStateEnableLessEqual;
		static ID3D11DepthStencilState*   g_pDSVStateEnableGreater;


		static ID3D11RasterizerState* g_pRSWireFrame;
		static ID3D11RasterizerState* g_pRSSolid;
		static ID3D11RasterizerState* g_pRSBackCullSolid;
		static ID3D11RasterizerState* g_pRSFrontCullSolid;
		static ID3D11RasterizerState* g_pRSNoneCullSolid;
		static ID3D11RasterizerState* g_pRSBackCullWireFrame;
		static ID3D11RasterizerState* g_pRSFrontCullWireFrame;
		static ID3D11RasterizerState* g_pRSNoneCullWireFrame;

		static ID3D11BlendState* g_pBSNoBlend;
		static ID3D11BlendState* g_pBSAlphaBlend;

		static ID3D11SamplerState*	g_pSSWrapLinear;

		static HRESULT SetState(ID3D11Device* pd3dDevice);
		static bool Release();
	public:
		xDxState();
		~xDxState();
	};

	static void ApplyDSS(ID3D11DeviceContext* pContext,
		ID3D11DepthStencilState* pState,
		UINT iRef=0x01)
	{
		pContext->OMSetDepthStencilState(pState,iRef );
	}
	static void ApplyRS(ID3D11DeviceContext* pContext,
		ID3D11RasterizerState* pState)
	{
		pContext->RSSetState(pState);
	}	

	static void ApplyBS(
		ID3D11DeviceContext* pContext,
		ID3D11BlendState* pState,
		const float fBlendFactor[] = 0,
		UINT iMask = 0xffffffff)
	{
		pContext->OMSetBlendState(pState,
			fBlendFactor, iMask);
	}

	static void ApplySS(ID3D11DeviceContext*   pContext, ID3D11SamplerState*      pSamplerState,
		UINT iSlot = 0, UINT iArray = 1)
	{
		pContext->PSSetSamplers(iSlot, iArray, &pSamplerState);
	}
}

