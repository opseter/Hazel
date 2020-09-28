#include"hzpch.h"
#include"Texture.h"

#include"Platform/OpenGL/OpenGLTexture.h"

#include"Renderer.h"

namespace Hazel{

	Hazel::Texture2D* Hazel::Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
		case RendererAPI::API::OpenGL: return new OpenGLTexture2D(path);
		}

		HZ_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
	}

}
