#pragma once

// 모든 그래프의 인터페이스
struct IGraph
{
	virtual void onUpdate(int n) = 0;
	virtual ~IGraph() {}
};