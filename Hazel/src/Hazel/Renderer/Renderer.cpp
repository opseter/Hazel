#include "hzpch.h"
#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "Renderer2D.h"
namespace Hazel {

	Scope<Renderer::SceneData> Renderer::m_ScenData =  CreateScope<Renderer::SceneData>();

	void Renderer::BeginScene(OrthographicCamera& camera )//once you kown all the thing of the scene ,you can do some optmision
	{
		m_ScenData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewport(0, 0, width, height);
	}

	void Renderer::Init()
	{
		RenderCommand::Init();
		Renderer2D::Init();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const Ref<Shader>& shader,const Ref<VertexArray>& vertexArray,const glm::mat4& transform)
	{
		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_ViewProjection", m_ScenData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Transform", transform);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

}