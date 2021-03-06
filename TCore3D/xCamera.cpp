#include "xCamera.h"

D3DXMATRIX xCamera::SetViewMatrix(
	D3DXVECTOR3 vPos,
	D3DXVECTOR3 vTarget,
	D3DXVECTOR3 vUp)
{
	m_vPos = vPos;
	m_vTarget = vTarget;
	m_vUp = vUp;
	D3DXMatrixLookAtLH(&m_matView,
		&vPos,
		&vTarget,
		&vUp);
	return m_matView;
}

D3DXMATRIX xCamera::SetProjMatrix(float fFov,
	float fAspect,
	float fNear,
	float fFar)
{
	m_fFov= fFov;
	m_fAspect= fAspect;
	m_fNear= fNear;
	m_fFar= fFar;
	D3DXMatrixPerspectiveFovLH(&m_matProj,
		fFov,
		fAspect,
		fNear, fFar);
	return m_matProj;
}

void  xCamera::UpdateProjMatrix(UINT width, UINT height)
{
	m_fAspect = (float)width / (float)height;
	SetProjMatrix(m_fFov,
		m_fAspect,
		m_fNear, m_fFar);
}
xCamera::xCamera()
{
}


xCamera::~xCamera()
{
}
