#pragma once
#include "Sandbox2D.h"
#include "imgui/imgui.h"
#include "Hazel/Renderer/Renderer2D.h"
#include <glm/gtc/type_ptr.hpp>
#include "Platform/OpenGL/OpenGLShader.h"

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnAttach()
{
	m_CheckerboardTexture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
	
}

void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(Hazel::TimeStep ts)
{
	m_CameraController.OnUpdate(ts);

	Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Hazel::RenderCommand::Clear();

	Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
	
	
	Hazel::Renderer2D::DrawQuard({ -1.0f,0.0f }, { 0.3f,0.5f }, { 0.8f,0.2f,0.3f ,1.0f });
	Hazel::Renderer2D::DrawQuard({ 0.0f,0.0f }, { 1.0f,1.0f }, { 0.2f,0.2f,0.7f ,1.0f });
	Hazel::Renderer2D::DrawQuard({ 0.0f,0.0f,-0.1f }, { 10.0f,10.0f }, m_CheckerboardTexture);
	

	Hazel::Renderer2D::EndScene();

}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Hazel::Event& e)
{
	m_CameraController.OnEvent(e);
}