#include"hzpch.h"
#include"VertexArray.h"

#include"Renderer.h"
#include"Platform/OpenGL/OpenGLVertexArray.h"

namespace Hazel {
	VertexArray* VertexArray::Create() 
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			case RendererAPI::API::OpenGL: return new OpenGLVertexArray();
		}

		HZ_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;

	}

}