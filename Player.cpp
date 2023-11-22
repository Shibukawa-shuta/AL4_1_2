#include "Player.h"
#include "ImGuiManager.h"
#include "Mymath.h"
#include <cassert>

void Player::Initialize(Model* model) {
	assert(model);
	model_ = model;
	worldTransform_.Initialize();

	worldTransform_.translation_ = {0.0f, 0.0f, 7.3f};
	worldTransform_.rotation_ = {0.0f, 0.0f, 0.0f};
	worldTransform_.scale_ = {1.0f, 1.0f, 1.0f};
}

void Player::Update() {

	ImGui::Begin("Player");
	ImGui::DragFloat3("tr", &worldTransform_.translation_.x, 0.1f);
	ImGui::DragFloat3("rot", &worldTransform_.rotation_.x, 0.1f);
	ImGui::DragFloat3("sc", &worldTransform_.scale_.x, 0.1f);
	ImGui::End();

	worldTransform_.UpdateMatrix();
}

void Player::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldTransform_, viewProjection);
}

