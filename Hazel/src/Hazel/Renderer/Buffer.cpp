#include "hzpch.h"
#include "Hazel/Renderer/Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"
namespace Hazel {

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
		case RendererAPI::API::OpenGL: return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}

		HZ_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(unsigned int* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			case RendererAPI::API::OpenGL: return CreateRef<OpenGLIndexBuffer>(indices, count);
		}

		HZ_CORE_ASSERT(false, "Unkown RendererAPI!");
		return nullptr;
	}

}