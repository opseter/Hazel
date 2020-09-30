#pragma once
#include "OrthographicCamera.h"
#include "Texture.h"

namespace Hazel {

	class Renderer2D
	{

	public:
		static void Init();
		static void Shudown();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		static void DrawQuard(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuard(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);

		static void DrawQuard(const glm::vec2& position, const glm::vec2& size, Ref<Texture>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawQuard(const glm::vec3& position, const glm::vec2& size, Ref<Texture>& texture, float tilingFactor = 1.0f, const glm::vec4 & tintColor = glm::vec4(1.0f));

		static void DrawRotatedQuard(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		static void DrawRotatedQuard(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		static void DrawRotatedQuard(const glm::vec2& position, const glm::vec2& size, float rotation, Ref<Texture>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawRotatedQuard(const glm::vec3& position, const glm::vec2& size, float rotation, Ref<Texture>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
	};


}