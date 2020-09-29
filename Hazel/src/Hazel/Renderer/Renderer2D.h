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

		static void DrawQuard(const glm::vec2& position, const glm::vec2& size, Ref<Texture>& texture);
		static void DrawQuard(const glm::vec3& position, const glm::vec2& size, Ref<Texture>& texture);
	};


}