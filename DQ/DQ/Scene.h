#pragma once

class Scene
{
public:
	virtual ~Scene() {}

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	virtual bool IsFinished() const = 0;
};