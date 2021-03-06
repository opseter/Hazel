#pragma once
#include "Hazel/Renderer/OrthographicCamera.h"
#include "Hazel/Renderer/Texture.h"
#include "Hazel/Renderer/SubTexture2D.h"


namespace Hazel {

	class Renderer2D
	{

	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();
		static void Flush();

		static void DrawQuard(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuard(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color);
		static void DrawQuard(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& color = glm::vec4(1.0f));
		static void DrawQuard(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& color = glm::vec4(1.0f));

		static void DrawQuard(const glm::vec2& position, const glm::vec2& size, const Ref<SubTexture2D>& subtexture, float tilingFactor = 1.0f, const glm::vec4& color = glm::vec4(1.0f));
		static void DrawQuard(const glm::vec3& position, const glm::vec2& size, const Ref<SubTexture2D>& subtexture, float tilingFactor = 1.0f, const glm::vec4& color = glm::vec4(1.0f));


		static void DrawRotatedQuard(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		static void DrawRotatedQuard(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		static void DrawRotatedQuard(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& color = glm::vec4(1.0f));
		static void DrawRotatedQuard(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& color = glm::vec4(1.0f));
	
		static void DrawRotatedQuard(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<SubTexture2D>& subtexture, float tilingFactor = 1.0f, const glm::vec4& color = glm::vec4(1.0f));
		static void DrawRotatedQuard(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<SubTexture2D>& subtexture, float tilingFactor = 1.0f, const glm::vec4& color = glm::vec4(1.0f));



		struct Statistics
		{
			uint32_t DrawCalls = 0;
			uint32_t QuadCount = 0;
			uint32_t GetTotalVertexCount() { return QuadCount * 4; }
			uint32_t GetTotalIndexCount() { return QuadCount * 6; }
		};

		static Statistics GetStats();
		static void ResetStats();
	private:
		static void FlushAndReset();
	};
	
}