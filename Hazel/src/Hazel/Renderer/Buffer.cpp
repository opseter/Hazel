#include"hzpch.h"
#include"Buffer.h"

#include"Renderer.h"
#include"Platform/OpenGL/OpenGLBuffer.h"
namespace Hazel {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			case RendererAPI::API::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}

		HZ_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(unsigned int* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			case RendererAPI::API::OpenGL: return new OpenGLIndexBuffer(indices, count);
		}

		HZ_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
	}

}