﻿#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
 
class Skydome {
public:
	void Initialize(Model* model);

	void Update();

	void Draw(const ViewProjection& viewProjection);

private:
	WorldTransform worldTransform_;

	Model* model_ = nullptr;
};
